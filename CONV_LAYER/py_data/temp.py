import numpy as np

a = np.random.randint(1, 2, 3)
b = np.random.randint(1, 2, 3)

print(a)
print(b)
print(np.row_stack((a, b)))

np.savetxt('a.txt', a, fmt='{1.3f}')
