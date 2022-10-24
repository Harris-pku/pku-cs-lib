import os
import cv2
import struct
import numpy as np
import matplotlib.pyplot as plt
from sklearn import neighbors


def load_mnist(path, kind = 'train'):
    labels_path = os.path.join(path, '%s-labels.idx1-ubyte' % kind)
    images_path = os.path.join(path, '%s-images.idx3-ubyte' % kind)
    with open(labels_path, 'rb') as lbpath:
        magic, n = struct.unpack('>II', lbpath.read(8))
        labels = np.fromfile(lbpath, dtype=np.uint8)
    with open(images_path, 'rb') as imgpath:
        magic, num, rows, cols = struct.unpack('>IIII', imgpath.read(16))
        images = np.fromfile(imgpath, dtype=np.uint8).reshape(len(labels), 784)
        for i in range(num):
            im2 = images[i].reshape(28,28)
            cv2.imwrite('D:/Windows/Windows/Desktop/pku code/pku code/Python/CV/number/%simages' % kind + '/%s' % kind + str(i) + '.jpg', im2)
    return images, labels


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

X_train, y_train = load_mnist('D:/Windows/Windows/Desktop/pku code/pku code/Python/CV/number')
X_test, y_test = load_mnist('D:/Windows/Windows/Desktop/pku code/pku code/Python/CV/number', 't10k')

X_train = getImages(60000)
X_test = getImages(10000, 't10k')

knn = neighbors.KNeighborsClassifier(algorithm='kd_tree', n_neighbors=3)
knn.fit(X_train, y_train)
result = knn.predict(X_test)
wrongNum = np.sum(result != y_test)

num = len(X_test)
print("Total number: ", num)
print("Wrong number: ", wrongNum)
print("RightRate: ", 1-wrongNum/float(num))
