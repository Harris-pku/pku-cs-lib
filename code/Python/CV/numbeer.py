import os
import cv2
import struct
import numpy as np
import matplotlib.pyplot as plt


def load_mnist(path, kind='train'):
    labels_path = os.path.join(path, '%s-labels.idx1-ubyte' % kind)
    with open(labels_path, 'rb') as lbpath:
        magic, n = struct.unpack('>II', lbpath.read(8))
        labels = np.fromfile(lbpath, dtype=np.uint8)
    return labels


def getImages(tot, kind = 'train'):
    imgs = np.zeros([tot,784], int)
    for i in range(tot):
        img1 = cv2.imread('D:/Windows/Windows/Desktop/pku code/pku code/Python/CV/number/%simages' % kind + '/%s' % kind + str(i) + '.jpg', 0)
        for rows in range(28):
            for cols in range(28):
                if  img1[rows, cols] >= 127:
                    img1[rows, cols] = 1
                else:
                    img1[rows, cols] = 0
                imgs[i, rows*28 + cols] = img1[rows, cols]
    return imgs


y_train = load_mnist('D:/Windows/Windows/Desktop/pku code/pku code/Python/CV/number')
y_test = load_mnist('D:/Windows/Windows/Desktop/pku code/pku code/Python/CV/number', 't10k')

X_train = getImages(60000)
X_test = getImages(10000, 't10k')

from skimage.feature import hog
train_x = []
for img in X_train:
    fd=hog(img, pixels_per_cell=(28,28),cells_per_block=(28,28),multichannel=False,feature_vector=True)
    train_x.append(fd)


train_x = np.array(train_x)
train_y = np.reshape(np.array(y_train), (-1, ))
clf = svm.SVC(kernel='linear',C=0.1)
clf.fit(train_x, train_y)

testx = []
for img in X_test:
    fd=hog(img,pixels_per_cell=(4,4),cells_per_block=(2,2),multichannel=False,feature_vector=True)
    texsx.append(fd)


testX = np.array(testX)
testY = np.reshape(np.array(test_y), (-1, ))

print('HOG: ',clf.score(testX, testY))