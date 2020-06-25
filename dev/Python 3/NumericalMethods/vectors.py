def dot(v1, v2):
    if len(v1)!=len(v2):
        raise Exception("Vector lengths do not match.")

    res = []
    add = 0
    for i in range(len(v1)):
        res.append(v1[i]*v2[i])
    for i in res:
        add += i
    return add

def cross(v1, v2):
    if (len(v1)!=3) or (len(v2)!=3):
        raise Exception('Vector must have length of 3.')
    
    res = [0,0,0]

    res[0] = v1[1]*v2[2] - v1[2]*v2[1]
    res[1] = v1[2]*v2[0] - v1[0]*v2[2]
    res[2] = v1[0]*v2[1] - v1[1]*v2[0]

    return res