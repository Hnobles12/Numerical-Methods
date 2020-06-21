import seaborn as sns
from matplotlib import pyplot as plt
import numpy as np

sns.set()
x = np.linspace(1,10,10)
y = np.linspace(2,5000,10)

print(x)
print(' ')
print(y)
sns.lineplot(x,y)
plt.show()

