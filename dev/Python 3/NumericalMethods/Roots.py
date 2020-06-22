#Root solving
import math as m
import numpy as np
#import sympy as sp
import scipy.misc as sc

#Bisection
##Passed Checks
def bisection(func, bounds, TOL=10e-16, return_data=False):
    if np.sign(bounds[0])==np.sign(bounds[1]):
        #error.err('Root is not Bracketed')
        raise Exception('Root is not Bracketed')
    elif bounds[1] < bounds[0]:
        raise Exception('Bound 1 is less than bound 0, please reverse bounds.')
        #error.err('Bound 1 is less than bound 0, please reverse bounds.')
    elif np.sign(func(bounds[0])) == np.sign(func(bounds[1])):
        raise Exception('The Root is not bracketed, the sign of the function is the same for both bounds.')
    
    data = []
    IT = 0
    xmid = xmid = (bounds[0]+bounds[1])/2
    err = func(xmid)
    data = [[xmid,err]]
    IT += 1

    while abs(err) > TOL:
        xmid = (bounds[0]+bounds[1])/2
        err = func(xmid)
        data.append([xmid,err])
        IT += 1
        if err > 0:
            bounds[1] = xmid
        else:
            bounds[0] = xmid
    if return_data is False:
        return xmid
    elif return_data is True:
        return [xmid, data, IT]


#Translated Newton Method
def newton(func, val, translated_root=0, TOL=10e-16, return_data=False, max_iter=100):
    func2 = lambda x: func(x) - translated_root
    x = val
    data = [x]
    i=0
    it = [i]
    err = []

    while abs(func2(x)) > TOL:
        diff = sc.derivative(func2, x, 1e-6)
        if diff == 0:
            raise Exception('Division by zero error, check derivative.')
        x = x - (func2(x)/diff)
        i+=1
        it.append(i)
        data.append(x)
        err.append(abs(func2(x)))
        if i > max_iter:
            raise Exception('Maximum number of iterations reached.')
    if return_data is True:
        return [x, data, it, err]
    else:
        return x