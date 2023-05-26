import sys

import matplotlib.pyplot as plt

 

def space_complexity(n):

    T = 1

    for i in range(n):

        T = T * A[i]

    return sys.getsizeof(T)

 

A = [8] * 10

 

sizes = []

for i in range(1, len(A) + 1):

    sizes.append(space_complexity(i))

 

plt.plot(range(1, len(A) + 1), sizes)

plt.xlabel('Input size')

plt.ylabel('Memory usage (bytes)')

plt.show()