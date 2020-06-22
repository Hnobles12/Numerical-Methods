import scipy.misc as sc
#Finite Differences
#Simple finitie difference derivative
def numDerivative(x,y):
    if len(x) != len(y):
        raise Exception("Input array lengths do not match.")
    if len(x) < 2:
        raise Exception("Input array is too short. Must have a lenth of at least 2.")

    data = []
    ret_x = []

    for i in range(len(x)-1):
        avg_x = (x[i+1]+x[i])/2
        dx = x[i+1]-x[i]
        dy = y[i+1]-y[i]

        if dx == 0:
            raise Warning('Two identical independent variables encountered in array, skipping iteration.')
        else:
            data.append(dy/dx)
            ret_x.append(avg_x)
    return ret_x, data


#test...
def funcDerivative(func, x, TOL=1e-6):
    return sc.derivative(func,x,TOL)