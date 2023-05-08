#!/usr/bin/python3
# this is a small sript to plot a 2D lattice given a basis
import matplotlib.pyplot as plt
from matplotlib import rc
import numpy as np

# Set the latex font
rc('font', **{'family': 'serif', 'serif': ['Computer Modern']})
rc('text', usetex=True)

# Define basis vectors
#v2 = np.array([0.5, 0])
#v1 = np.array([0, 1])
# The dual
v2 = np.array([1, 1])
v1 = np.array([-1, 1])


# Define the number of points
n_points = 10

# Generate lattice points
lattice_points = np.zeros((16*n_points**2, 2))
k = 0
for i in range(-n_points*2, n_points*2):
    for j in range(-n_points*2, n_points*2):
        lattice_points[k] = i*v1 + j*v2
        k += 1
        #lattice_points.append(i*v1 + j*v2)

# Plot lattice points
fig, ax = plt.subplots()
ax.scatter([p[0] for p in lattice_points], [p[1] for p in lattice_points], color='black', s=10)

# Set x and y axis limits to be symmetric around zero

#ax.set_xlim(-n_points n_points)
#ax.set_ylim(-n_points, n_points)
ax.set_xlim(-3.5, 3.5)
ax.set_ylim(-3.5, 3.5)

# plot the basis
plt.arrow(0, 0, v1[0], v1[1], head_width=0.1, head_length=0.1, color='r', linewidth=2)
plt.arrow(0, 0, v2[0], v2[1], head_width=0.1, head_length=0.1, color='r', linewidth=2)

# annotate the points
plt.annotate('$(1,1)$', xy=(1, 1), xytext=(1.3, 1.3), fontsize=14)
plt.annotate('$(\sqrt{-1},-\sqrt{-1})$', xy=(-1, 1), xytext=(-2, 1.3), fontsize=14)

# plot the standard basis for Z^2
plt.arrow(0, 0, n_points, 0, head_width=0, head_length=0, color='k', alpha=0.5,)
plt.arrow(0, 0, 0, n_points, head_width=0, head_length=0, color='k', alpha=0.5,)
plt.arrow(0, 0, -n_points, 0, head_width=0, head_length=0, color='k', alpha=0.5)
plt.arrow(0, 0, 0, -n_points, head_width=0, head_length=0, color='k', alpha=0.5)


plt.gca().spines['right'].set_visible(False)
plt.gca().spines['top'].set_visible(False)
plt.gca().spines['bottom'].set_visible(False)
plt.gca().spines['left'].set_visible(False)

ax.tick_params(axis='both', which='both', length=0)
ax.spines['bottom'].set_visible(False)
ax.spines['right'].set_visible(False)

# Show plot
#plt.show()
plt.savefig('../images/ex_lattice.png', dpi=200, format='png', transparent=True)
