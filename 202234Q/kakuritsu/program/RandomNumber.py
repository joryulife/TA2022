import random
import numpy as np
import matplotlib.pyplot as plt

n = int(input("Enter number of steps:"))

x = np.random.randint(10, size = n)

plt.hist(x, range = (0,10), rwidth = 0.9, align = 'left')

plt.savefig("rd.png")
plt.show()