#Root solving
import math as m
import numpy as np
#import error
#Bisection
def bisection(func, bounds, TOL=10e-6):
    if np.sign(bounds[0])==np.sign(bounds[1]):
        #error.err('Root is not Bracketed')
        raise Exception('Root is not Bracketed')
    elif bounds[1] < bounds[0]:
        raise Exception('Bound 1 is less than bound 0, please reverse bounds.')
        #error.err('Bound 1 is less than bound 0, please reverse bounds.')

    xmid = xmid = (bounds[0]+bounds[1])/2
    err = func(xmid)

    while abs(err) > TOL:
        xmid = (bounds[0]+bounds[1])/2
        err = func(xmid)
        if err > 0:
            bounds[1] = xmid
        else:
            bounds[0] = xmid
    
    return xmid


#Newton-Raphson