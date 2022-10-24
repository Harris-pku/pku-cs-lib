import numpy as np
import struct
import cv2
import os
from sklearn import neighbors

def readfile():
    with open('./t10k-images.idx3-ubyte', 'rb') as f1:
        buf1 = f1.read()
    return buf1


def get_image (buf1):
    image_index = 0
    image_index += strcut.calcsize('>IIII')
    magic, numImages, imgRows, imgCols = struct.unpack_from(">IIII", buf1, 0)
    im = []
    for i in range(numImages):
        temp = strcut.unpack_from('>784B', buf1, image_index)
        im = np.array(temp)
        im2 = im.reshape(28, 28)
        cv2.imwrite("./result" + str(i) + ".jpg", im2)
        image_index += struct.calcsize('>784B')
        if i % 20 == 0:
            print (i)
        else:
            print (i)

 
def getImages():
    imgs=np.zeros([60000,784],int)
    for i in range(60000):
        img1=cv2.imread("./result"+str(i)+".jpg",0)
        for rows in range(28):
            for cols in range(28):
                if img1[rows,cols]>=127:
                    img1[rows,cols]=1
                else:
                    img1[rows,cols]=0
                imgs[i,rows*28+cols]=img1[rows,cols]
 
    return imgs


def getLabels():
    f1=open("./train-labels.idx1-ubyte",'rb')
    buf1=f1.read()
    f1.close()
    index=0
    magic,num=struct.unpack_from(">II",buf1,0)
    index+=struct.calcsize('>II')
    labs=[]
    labs=struct.unpack_from('>'+str(num)+'B',buf1,index)
    return labs


def getTestImages():
    imgs=np.zeros([10000,784],int)
    for i in range(10000):
        img1=cv2.imread("./result"+str(i)+".jpg",0)
        for rows in range(28):
            for cols in range(28):
                if img1[rows,cols]>=127:
                    img1[rows,cols]=1
                else:
                    img1[rows,cols]=0
                imgs[i,rows*28+cols]=img1[rows,cols]
    return imgs


def getTestLabels():
    f1=open("./t10k-labels.idx1-ubyte",'rb')
    buf1=f1.read()
    f1.close()
    index=0
    magic,num=struct.unpack_from(">II",buf1,0)
    index+=struct.calcsize('>II')
    labs=[]
    labs=struct.unpack_from('>'+str(num)+'B',buf1,index)
    return labs



image_data = readfile()
get_image(image_data)
cv2.waitKey(0)
cv2.destroyAllWindows()

print ("Getting train_imgs...")
train_imgs=getImages()
print ("Getting train_labels...")
train_labels=getLabels()
print ("Creating KNN classifier...")
knn=neighbors.KNeighborsClassifier(algorithm='kd_tree',n_neighbors=3)
print ("Training...")
knn.fit(train_imgs,train_labels)
print ("Getting test_images...")
test_imgs=getTestImages()
print ("Getting test_labels...")
test_labels=getTestLabels()
print ("Predicting...")
result=knn.predict(test_imgs)
wrongNum=np.sum(result!=test_labels)
num=len(test_imgs)
print ("Total number:", num)
print ("Wrong number:", wrongNum)
print ("RightRate:", 1-wrongNum/float(num))