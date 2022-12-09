import random
import numpy as np
import matplotlib.pyplot as plt

n = int(input("Enter number of steps:"))

xc = 0
x = [xc]
for i in range(n):
    xc += 2*random.randint(0,1) - 1
    x.append(xc)
plt.plot(x, marker='')

plt.savefig("rw1D.png")
plt.show()