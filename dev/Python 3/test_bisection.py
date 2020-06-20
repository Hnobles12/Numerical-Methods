from NumericalMethods.Roots import *
from matplotlib import pyplot as plt
import seaborn as sns

f = lambda x: x**2 + 2*x
num, data, it = bisection(f,[-1,2], return_data=True)
print(num)
print(f(num))


#sns.set('tips')
x = []
for i in range(it):
    x.append(i)
sns.scatterplot(x, data[][0], data[][1])
plt.show()