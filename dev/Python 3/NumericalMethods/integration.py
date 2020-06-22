import numpy as np

def numIntegral(x, y):
    if len(x) != len(y):
        raise Exception('Input array lengths do not match.')
    if len(x) < 2:
        raise Exception('Input arrays too short, must have minimum length of 2.')
    
    area = 0
    for i in range(len(x)-1):
        h = x[i+1]-x[i]
        area += (y[i+1]+y[i])*(h/2)
    return area

def funcIntegral(func, bounds, divs=100000):
    a,b,area = bounds[0],bounds[1],0
    data = np.linspace(a,b,divs)
    y = []

    for i in data:
        y.append(func(i))
    
    for i in range(len(data)-1):
        h = (abs(b-a)/divs)
        area += (y[i+1]+y[i])*h*0.5
    return area
        