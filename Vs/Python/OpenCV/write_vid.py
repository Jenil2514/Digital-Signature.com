import cv2 as c
import datetime
capture = c.VideoCapture(0)

width = capture.get(c.CAP_PROP_FRAME_WIDTH)# same as capture.get(3)
height = capture.get(c.CAP_PROP_FRAME_HEIGHT)# same as capture.get(4)

capture.set(3,1920)
capture.set(4,1080)

while(capture.isOpened()):
    ret,frame = capture.read()

    font = c.FONT_HERSHEY_SIMPLEX
    # text = 'Width'+str(width)+' Height'+str(height)
    text = str(datetime.datetime.now())
    frame = c.putText(frame,text,(10,50),font,1,(0,255,252),4,c.LINE_AA)
    c.imshow('frame',frame)

    if c.waitKey(1)==ord('q'):
        break

capture.release()
c.destroyAllWindows()