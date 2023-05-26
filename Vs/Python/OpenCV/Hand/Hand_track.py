import cv2
import mediapipe as mp
import time

cap = cv2.VideoCapture(0)
mpHands = mp.solutions.hands
hands = mpHands.Hands()

mpDraw = mp.solutions.drawing_utils

cTime = 0
pTime = 0

while True:

    ret, img = cap.read()
    imRGB = cv2.cvtColor(img, cv2.COLOR_BGR2RGB)
    results = hands.process(imRGB)

    print(results.multi_hand_landmarks)    
    if results.multi_hand_landmarks:
        for handLms in results.multi_hand_landmarks:
            for id , lm in enumerate(handLms.landmark):
                h, w, c = img.shape
                cx, cy = int(lm.x*w),int(lm.y*h)
                # cv2.circle(img,(cx,cy),15,(0,0,0),2)
                # print(id,cx,cy)
        mpDraw.draw_landmarks(img, handLms,mpHands.HAND_CONNECTIONS)
            
    cTime = time.time()
    fps = 1 / (cTime - pTime)
    pTime = cTime

    cv2.putText(img, str(int(fps)), (10,50), cv2.FONT_HERSHEY_SIMPLEX,2,(0,0,255),2)

    cv2.imshow('Lol', img)
    if cv2.waitKey(1) == ord('q'):
        break

cap.release()
cv2.destroyAllWindows()
