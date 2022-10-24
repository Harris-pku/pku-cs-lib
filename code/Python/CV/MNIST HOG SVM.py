import numpy as np
import cv2
import os
import struct
import matplotlib.pyplot as plt
from sklearn import neighbors

hog = cv2.HOGDescriptor(
    (28, 28), (14, 14), (7, 7), (7, 7), 9, 1, 4., 0, 2, 0, 64
)

ftrain = []
for item in train_data:
    ftrain.append(hog.compute(item))
train_data = np.array(ftrain)

ftest = []
for item in test_data:
    ftest.append(hog.compute(item))
test_data = np.array(ftest)

clf = svm.LinearSVC()
X = train_data.reshape((60000, -1))
Y = train_label
clf.fit(X, Y)
x = test_data.reshape((10000, -1))
y = test_label
print('Linear SVM score %.3f' %  (clf.score(x, y)))
