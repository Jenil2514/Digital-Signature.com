import cv2 as c
capture = c.VideoCapture(0)

while(1):
    ret,frame = capture.read()

    c.imshow('frame',frame)

    if c.waitKey(1)==ord('q'):
        break

capture.release()
c.destroyAllWindows()