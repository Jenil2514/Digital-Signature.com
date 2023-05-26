import cv2 as c
import numpy as np

cap = c.VideoCapture('vtest.avi')
ret,frame1 = cap.read()
# c.imshow('f1',frame1)
ret,frame2 = cap.read()
# c.imshow('f2',frame2)
while cap.isOpened():
        diff = c.absdiff(frame1,frame2)
        gray = c.cvtColor(diff,c.COLOR_BGR2GRAY)
        blur = c.GaussianBlur(gray,(5,5),0)
        _,thresh = c.threshold(blur,20,255,c.THRESH_BINARY)
        dilated = c.dilate(thresh,None,iterations=3)
        contours, _ = c.findContours(dilated,c.RETR_TREE,c.CHAIN_APPROX_SIMPLE)
        # c.drawContours(frame1,contours,-1,(0,255,0),3)
        for contour in contours:
              (x,y,w,h) = c.boundingRect(contour)

              if c.contourArea(contour) < 900:
                continue
              c.rectangle(frame1,(x,y),(x+w,y+h),(0,255,0),3)
        c.imshow('Vid',frame1)
        frame1=frame2
        ret,frame2 = cap.read()

        if c.waitKey(40) == 27:
            break

c.destroyAllWindows()
cap.release()

