import cv2
import mediapipe as mp
import time
import Hand_module as hm


cap = cv2.VideoCapture(0)
cTime = 0
pTime = 0
detector = hm.handDetector()
while True:

        _, img = cap.read()
        img = detector.findHands(img)
        lmlist = detector.findPosition(img)
        if len(lmlist) != 0:
            print(lmlist[4])

        cTime = time.time()
        fps = 1 / (cTime - pTime)
        pTime = cTime

        cv2.putText(img, str(int(fps)), (10, 50),
                    cv2.FONT_HERSHEY_SIMPLEX, 2, (0, 0, 255), 2)

        cv2.imshow('Lol', img)
        if cv2.waitKey(1) == ord('q'):
            break

cap.release()
cv2.destroyAllWindows()
