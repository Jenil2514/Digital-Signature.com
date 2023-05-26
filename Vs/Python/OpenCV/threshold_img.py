import cv2
img = cv2.imread('gradient.png',0)

_,th1 = cv2.threshold(img,50,255,cv2.THRESH_BINARY)
_,th2 = cv2.threshold(img,50,255,cv2.THRESH_BINARY_INV)
_,th3 = cv2.threshold(img,50,255,cv2.THRESH_TRUNC)
_,th4 = cv2.threshold(img,50,255,cv2.THRESH_MASK)
_,th5 = cv2.threshold(img,50,255,cv2.THRESH_OTSU)
_,th6 = cv2.threshold(img,50,255,cv2.THRESH_TOZERO)
_,th7 = cv2.threshold(img,50,255,cv2.THRESH_TOZERO_INV)
cv2.imshow('Lol',img)
cv2.imshow('Lol1',th1)
cv2.imshow('Lol2',th2)
cv2.imshow('Lol3',th3)
cv2.imshow('Lol4',th4)
cv2.imshow('Lol5',th5)
cv2.imshow('Lol6',th6)
cv2.imshow('Lol7',th7)


k = cv2.waitKey(0) 

if k == 27:
    cv2.destroyAllWindows()
    