import cv2 as c
import numpy as np

img = c.imread('pic5.png')
img2 = c.cvtColor(img, c.COLOR_BGR2GRAY)
ret,threshold = c.threshold(img2, 127 , 255, 0)
contour,hierarchy = c.findContours(threshold,c.RETR_TREE,c.CHAIN_APPROX_SIMPLE)

c.drawContours(img,contour,-1,(0,255,0),1)
c.imshow('con',img)
c.waitKey(0)
c.destroyAllWindows()