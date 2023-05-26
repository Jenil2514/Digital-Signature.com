import cv2 as c
import numpy as np
import mediapipe as mp
import Hand_module as hm
import os

folderpath = 'Finger_Img'
mylist = os.listdir(folderpath)
# print(mylist)
overlaylist = []
for imPath in mylist:
    image = c.imread(f'{folderpath}/{imPath}')
    overlaylist.append(image)

print(len(overlaylist))

cap = c.VideoCapture(0)

detector = hm.HandDetector(detectionCon=0.75)
fingerIdx = [4,8,12,16,20]
while True:

    sucess, img = cap.read()
    img = detector.findHands(img)
    lmlist,_ = detector.findPosition(img,draw=False)
    # print(lmlist)

    
    if len(lmlist) !=0 :
        trackfg = []
            # for thumb
        
        if lmlist[4][1] < lmlist[2][1]:
            trackfg.append(0)

        else:
            trackfg.append(1)
        for id in range(1,5):

            if lmlist[fingerIdx[id]][2] > lmlist[fingerIdx[id]-2][2]:
            # print(str(lmlist[8][2])+'8',str(lmlist[6][2])+'6')
                trackfg.append(0)
            else:
                trackfg.append(1)    
        
        # print(trackfg)
        total_fig = trackfg.count(1)
        print(total_fig)       
        h,w,ch = overlaylist[total_fig-1].shape
        img[0:h,0:w]= overlaylist[total_fig-1]


    c.imshow('Finger',img)
    if c.waitKey(1) == ord('q'):
        break

cap.release()
c.destroyAllWindows()
