from NumericalMethods.Roots import *
import seaborn as sns
from matplotlib import pyplot as plt
import numpy as np

def func(x):
    return x**2+2*x-10

val = newton(func, 2.5,6.5)
print("No Data test >")
print("root: ", val)
print("eval: ", func(val))

print('')
print('Data Test >')
val, data, it, err = newton(func, 2.5,6.5, return_data=True)
print('Root: ', val)
print('Error: ', err[len(err)-1])
print('eval: ', func(val))
print('Iterations: ', it)
print("Data: ", data)
q