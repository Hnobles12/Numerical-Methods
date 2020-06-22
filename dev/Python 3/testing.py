from NumericalMethods.differentiation import *
from NumericalMethods.Roots import *
from NumericalMethods.misc import *
import numpy as np

func = lambda x: 3*x**4 + 2*x**2 + 10*x + 4

x = np.linspace(3.5,4.5, 5)
y = []

for i in x:
    y.append(func(i))

x, diff = numDerivative(x,y)
index = closestValue(x, 4)

print('Functional Derivative at 4: ', funcDerivative(func, 4))
print('Numerical Derivative at 4: ', diff[index])