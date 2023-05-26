import cv2 as c
import mediapipe as mp
import numpy as np
import time
import math
import Hand_module as hm
from ctypes import cast, POINTER
from comtypes import CLSCTX_ALL
from pycaw.pycaw import AudioUtilities, IAudioEndpointVolume


#################
Cwidth = 640
Cheight = 480

devices = AudioUtilities.GetSpeakers()
interface = devices.Activate(
    IAudioEndpointVolume._iid_, CLSCTX_ALL, None)
volume = cast(interface, POINTER(IAudioEndpointVolume))
# volume.GetMute()
# volume.GetMasterVolumeLevel()
volumerg = volume.GetVolumeRange()
minvolume = volumerg[0]
maxvolume = volumerg[1]

#################
cap = c.VideoCapture(0)
cap.set(3, Cwidth)
cap.set(4, Cheight)
cTime = 0
pTime = 0
detection = hm.HandDetector(detectionCon=0.75)
area = 0
while True:
    sucess, img = cap.read()
    img = detection.findHands(img)
    lmlist, bbox = detection.findPosition(img)
    if len(lmlist) != 0:

        # ARea
        area = (bbox[2]-bbox[0]) * (bbox[3]-bbox[1])//100
        # print(bbox)
        # print(area)
        
        if 230 < area < 1600:

            # Distance betweeen thumb and index
            length, img, lineInfo = detection.findDistance(4, 8, img)

            #Convert Volume
            # vol = np.interp(length, [30, 210], [minvolume, maxvolume])
            volper = np.interp(length,[30,210],[0,100])
            #Smoothness
            smoothness = 5
            volper = smoothness * round(volper/smoothness)
            #Check Fingers Up
            finger = detection.fingerUp()
            if finger[4]==0:
                volume.SetMasterVolumeLevelScalar(volper/100, None)
                c.circle(img, (lineInfo[4], lineInfo[5]), 10, (255, 0, 0), c.FILLED)
            # if finger[0]==0 and finger[1]==1 and finger[2]==1 and finger[3]==1 and finger[4]==1:
            if finger == [0,1,1,1,1]:
                break
            



    cTime = time.time()
    fps = 1/(cTime-pTime)
    pTime = cTime
    c.putText(img, 'FPS :'+str(int(fps)), (40, 50),
              c.FONT_HERSHEY_COMPLEX, 1, (0, 0, 0), 2)
    c.imshow('Vid', img)
    if c.waitKey(1) == ord('q'):
        break

cap.release()
c.destroyAllWindows()
