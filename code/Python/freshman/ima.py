import numpy as np
import matplotlib.pylab as plt

fig = plt.figure()
fig = plt.figure(figsize=(10,6))
colors = ['red', 'blue', 'green', 'orange', 'black']
for i in range(5):
    start_index = i*12
    end_index = (i+1)*12
    subset = unrate[start_index:end_index]
label = str(1948 + i)
plt.plot(subset['MONTH'], subset['VALUE'], c=colors[i], label=label)
#添加图例，loc='upper left表示图例位置在最左侧，一般也可以直接使用loc='best'
plt.legend(loc='upper left')
plt.xlabel('Month, Integer')
plt.ylabel('Unemployment Rate, Percent')
plt.title('Monthly Unemployment Trends, 1948-1952')
plt.show()