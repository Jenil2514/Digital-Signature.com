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
cap.set(3,Cwidth)
cap.set(4,Cheight)
cTime = 0
pTime = 0
detection = hm.HandDetector()
while True:
    sucess, img = cap.read()
    img = detection.findHands(img)
    lmlist,_ = detection.findPosition(img,draw=False)
    if len(lmlist) != 0:
        # print(lmlist[4],lmlist[8])
        x1,y1 = (lmlist[4][1]),(lmlist[4][2])
        x2,y2 = (lmlist[8][1]),(lmlist[8][2])

        c.circle(img,(x1,y1),10,(0,0,255),c.FILLED)
        c.circle(img,(x2,y2),10,(0,0,255),c.FILLED)

        c.line(img,(x1,y1),(x2,y2),(0,255,0),2,c.BORDER_CONSTANT)
        cx,cy = (x1+x2)//2 , (y1+y2)//2
        c.circle(img,(cx,cy),10,(0,0,255),c.FILLED)

        length = math.hypot(x2-x1,y2-y1)
        # print(length)

        vol = np.interp(length,[30,210],[minvolume,maxvolume])
        print(int(length),vol)
        volume.SetMasterVolumeLevel(vol, None)


        if length<30 or length>210:
            c.circle(img,(cx,cy),10,(255,0,0),c.FILLED)

        



        

    cTime = time.time()
    fps = 1/(cTime-pTime)
    pTime = cTime
    c.putText(img,'FPS :'+str(int(fps)),(40,50),c.FONT_HERSHEY_COMPLEX,1,(0,0,0),2)
    c.imshow('Vid',img)
    if c.waitKey(1) == ord('q'):
        break

cap.release()
c.destroyAllWindows()