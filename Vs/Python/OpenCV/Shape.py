import cv2 as c



shape = c.imread('shapes.png')

gray = c.cvtColor(shape,c.COLOR_BGR2GRAY)
_,thresh = c.threshold(gray,230,255,c.THRESH_BINARY)

contours , _ = c.findContours(thresh,c.RETR_TREE,c.CHAIN_APPROX_SIMPLE)
c.drawContours(shape,contours,-1,(0,255,0),2)
c.imshow('shape',thresh)
c.waitKey(0)
c.destroyAllWindows()