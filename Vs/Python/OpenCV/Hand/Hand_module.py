import cv2
import mediapipe as mp
import time
from cvzone.HandTrackingModule import HandDetector
import math


class HandDetector:
    def __init__(self, mode=False, maxHands=2 , modelC=1, detectionCon=0.5, trackCon=0.5):
        self.mode = mode
        self.maxHands = maxHands
        self.detectionCon = detectionCon
        self.modelC = modelC
        self.trackCon = trackCon

        self.mpHands = mp.solutions.hands
        self.hands = self.mpHands.Hands(self.mode, self.maxHands, self.modelC, self.detectionCon, self.trackCon)
        self.mpDraw = mp.solutions.drawing_utils
        self.tipid = [4,8,12,16,20]

    def findHands(self, img, draw=True):


        imRGB = cv2.cvtColor(img, cv2.COLOR_BGR2RGB)
        self.results = self.hands.process(imRGB)
        # print(results.multi_hand_landmarks)  

        if self.results.multi_hand_landmarks:
            for handLms in self.results.multi_hand_landmarks:
                if draw:
                    self.mpDraw.draw_landmarks(img, handLms,self.mpHands.HAND_CONNECTIONS)

        return img

    def findPosition(self, img, handNo=0, draw=True):
        xlist = []
        ylist = []
        bbox = []
        self.lmlist = []

        if self.results.multi_hand_landmarks:
            myhand = self.results.multi_hand_landmarks[handNo]
            for id, lm in enumerate(myhand.landmark):
                h, w, c = img.shape
                cx, cy = int(lm.x*w), int(lm.y*h)
                xlist.append(cx)
                ylist.append(cy)
                self.lmlist.append([id, cx, cy])
                xmin,xmax = min(xlist),max(xlist)
                ymin,ymax = min(ylist),max(ylist)
                bbox = xmin,ymin,xmax,ymax
                if draw:
                    cv2.circle(img, (cx, cy), 5, (255, 0, 255), -1)

            if draw:
                cv2.rectangle(img,(bbox[0]-20,bbox[1]-20),(bbox[2]+20,bbox[3]+20),(0,255,0),2)

                # print(id,cx,cy)
        return self.lmlist,bbox
    
    def fingerUp(self):
        fingers = []
        #Thumb
        if self.lmlist[self.tipid[0]][1] < self.lmlist[self.tipid[0]-1][1]:
            fingers.append(0)
        else:
            fingers.append(1)
        # 4 Fingers
        for id in range(1,5):

            if self.lmlist[self.tipid[id]][2] > self.lmlist[self.tipid[id]-2][2]:
                fingers.append(0)
            else:
                fingers.append(1)
        return fingers
    
    def findDistance(self,p1,p2,img):
        # print(lmlist[4],lmlist[8])
            x1,y1 = (self.lmlist[p1][1]),(self.lmlist[p1][2])
            x2,y2 = (self.lmlist[p2][1]),(self.lmlist[p2][2])
            cv2.circle(img,(x1,y1),10,(0,0,255),cv2.FILLED)
            cv2.circle(img,(x2,y2),10,(0,0,255),cv2.FILLED)

            cv2.line(img,(x1,y1),(x2,y2),(0,255,0),2,cv2.BORDER_CONSTANT)
            cx,cy = (x1+x2)//2 , (y1+y2)//2
            cv2.circle(img,(cx,cy),10,(0,0,255),cv2.FILLED)

            length = math.hypot(x2-x1,y2-y1)
            # print(length)
            
            return length,img,[x1,y1,x2,y2,cx,cy]

            

def main():
    cap = cv2.VideoCapture(0)
    cTime = 0
    pTime = 0
    detector = HandDetector(detectionCon=0.8, maxHands=1)
    while True:

        _, img = cap.read()
        img = detector.findHands(img)
        lmlist,_ = detector.findPosition(img)
        if len(lmlist)!=0:
            print(lmlist[4])

        cTime = time.time()
        fps = 1 / (cTime - pTime)
        pTime = cTime

        cv2.putText(img, str(int(fps)), (10,50), cv2.FONT_HERSHEY_SIMPLEX,2,(0,0,255),2)

        cv2.imshow('Lol', img)
        if cv2.waitKey(1) == ord('q'):
            break

    cap.release()
    cv2.destroyAllWindows()


if __name__ == '__main__':
    main()


