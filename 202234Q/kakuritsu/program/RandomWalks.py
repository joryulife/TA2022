import random
import numpy as np
import matplotlib.pyplot as plt

w = int(input("Enter number of walkers:"))
n = int(input("Enter number of steps:"))

var = np.zeros(n);

for j in range(w):
    xc = 0
    x = [xc]
    for i in range(n):
        xc += 2*random.randint(0,1) - 1
        x.append(xc)
        var[i] += xc*xc
    if j%50 == 0: plt.plot(x, marker='')

plt.savefig("rws1D.png")
plt.show()

plt.plot(var/w)
plt.savefig("msd.png")
plt.show()