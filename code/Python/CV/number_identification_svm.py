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

from sklearn import svm
from sklearn import metrics

clf = svm.SVC(kernel='linear', C=1.0)
clf.fit(X_train, y_train)
y_pred = clf.predict(X_test)

print("Accuracy:{:.6f}".format(metrics.accuracy_score(y_test, y_pred)))
