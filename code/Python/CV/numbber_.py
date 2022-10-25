import os
import cv2
import struct
import numpy as np
import matplotlib.pyplot as plt
from sklearn import neighbors


def load_mnist(path, kind='train'):
    labels_path = os.path.join(path, '%s-labels.idx1-ubyte' % kind)
    with open(labels_path, 'rb') as lbpath:
        magic, n = struct.unpack('>II', lbpath.read(8))
        labels = np.fromfile(lbpath, dtype=np.uint8)
    return labels


def getImages():
    imgs = np.zeros([60000,784], int)
    for i in range(60000):
        img1 = cv2.imread('D:/Windows/Windows/Desktop/pku code/pku code/Python/CV/number/trainimages/train' + str(i) + '.jpg', 0)
        for rows in range(28):
            for cols in range(28):
                if  img1[rows, cols] >= 127:
                    img1[rows, cols] = 1
                else:
                    img1[rows, cols] = 0
                imgs[i, rows*28 + cols] = img1[rows, cols]
    return imgs


def getTestImages():
    imgs = np.zeros([10000, 784], int)
    for i in range(10000):
        img1 = cv2.imread('D:/Windows/Windows/Desktop/pku code/pku code/Python/CV/number/t10kimages/t10k' + str(i) + '.jpg', 0)
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

X_train = getImages()
X_test = getTestImages()

from sklearn import svm
from sklearn import metrics

clf = svm.SVC(kernel='linear', C=0.8)
clf.fit(X_train, y_train)
y_pred = clf.predict(X_test)

print("Accuracy:{:.6f}".format(metrics.accuracy_score(y_test, y_pred)))