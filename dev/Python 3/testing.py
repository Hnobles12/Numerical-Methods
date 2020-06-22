from NumericalMethods.differentiation import *
from NumericalMethods.Roots import *
from NumericalMethods.misc import *
from NumericalMethods.integration import *
import numpy as np

func = lambda x: 3*x**4 + 2*x**2 + 10*x + 4

x = np.linspace(0,2, 100000)
y = []

for i in x:
    y.append(func(i))

integral1 = numIntegral(x,y)
integral2 = funcIntegral(func,[0,2])
print('Numerical Integral :', integral1)
print('Functional Integral: ', integral2)