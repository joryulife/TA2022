import random
import numpy as np
import matplotlib.pyplot as plt
import matplotlib.patches as patches

plt.figure(figsize = (5,5))
ax = plt.axes()

n = int(input("Enter number of steps:"))

cnt = 0

for i in range(n):
    x = np.random.rand()
    y = np.random.rand()   
    if x*x + y*y < 1.0:
        cnt = cnt + 1
        plt.plot(x, y, marker = ',', color = 'r')
    else:
        plt.plot(x, y, marker = ',', color = 'b')

print(4*cnt/n)

circle = patches.Arc(xy = (0, 0), width = 2.0, height = 2.0, theta1 = 0.0, theta2 = 90.0, color = 'black')
ax.add_patch(circle)

plt.grid()
plt.axis()
plt.text(0.01, 0.01, str(n)+" steps  "+"pi ~ "+str(4*cnt/n))
plt.savefig("mc.png")
plt.show()