import numpy as np

# attributes

a = np.array([[1, 2, 3], [2, 3, 4], [3, 4, 5]])  # using a list
print(a.ndim)
print(a.shape)
print(a.size)
print(a.dtype)
print(a.itemsize)  # sizeof(dtype), bytes
print(a.data)  # ? what for?

# array creation

# ? how to figure out all the enums?
a = np.array([1, 2, 3, 4, 5], dtype=complex)
print(a)

print(np.zeros((3, 4)))  # using a tuple
print(np.ones((3, 4)))
print(np.empty((3, 4)))  # with digits on memory
print(np.empty((3, 4)).dtype)  # default : float64

# matlab-like style, no ending number, default : int32
print(np.arange(10, 30, 5))
# bad at predict number of elements while using float64, due to finite precision
print(np.arange(0, 2.1, 0.3))

# thus, linspace would be better as number of elements is provided
print(np.linspace(0, 2, 9))
print(np.linspace(0, 3, 4).dtype)  # default : float64

print(np.random.rand(1, 2, 3))  # uniform, [0, 1)
print(np.random.randint(0, 10, (1, 2, 3)))  # uniform, [0, 10), int
print(np.random.randn(1, 2, 3))  # normal, [0, 1)
# insight 应当复习线性代数和概率统计
# ? other distributions?


# basic operations
# + - * / @
a = np.arange(0, 10, 1)
b = np.arange(9, -1, -1)

print(a)
print(b)
print("elementwise")
print("a + b", a + b)
print("a - b", a - b)
print("a * b", a * b)
print("a / b", a / b)
# matrix multiplicaton / inner product when ndim = 1 for both
print("a @ b", a @ b)

a = np.array([[1, 2, 3], [3, 4, 5]])
b = np.array([[5, 6], [7, 7], [8, 9]])

print(a @ b)

print(a.prod())

a = np.array([1, 2, 3, 4])
b = a[::-1]
print(b)

a = np.array([[1, 2], [3, 4]])
a.flatten()
print(a)
