def closestValue(x_list, val):
    #Returns the index of a point in a list closest to the value given.
    if len(x_list) < 2:
        raise Exception("Input array is too short. Must have a lenth of at least 2.")

    if val in x_list:
        index = x_list.index(val)
        return index
    else:
        error = []
        for x in x_list:
            error.append(abs(x-val))
        minimum = min(error)
        index = error.index(minimum)
        return index