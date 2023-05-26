import cv2
# way = (int(input("Enter Way of Image 1|0|-1  :")))
img = cv2.imread('lena.jpg',0)# 0 for Gray 1 for colored -1 for alpha with colored
print(img)
cv2.imshow('Lol',img)
k = cv2.waitKey(1)# time in milisec. 
# if k == 27:# by pressing esc key destroys window
#     cv2.destroyAllWindows()
# elif k== ord('s'):# by pressing s key saves image
#     cv2.imwrite('Lena_copy.jpg',img)
#     cv2.destroyAllWindows()