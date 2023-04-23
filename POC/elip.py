#!/usr/bin/python3

import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
from scipy.stats import multivariate_normal

# Define mean vector and covariance matrix
mean = [0, 0]
cov = [[4, 0], [0, 0.5]]

# Create a grid of x and y values
x, y = np.meshgrid(np.linspace(-6, 6, 40), np.linspace(-6, 6, 40))
pos = np.empty(x.shape + (2,))
pos[:, :, 0] = x
pos[:, :, 1] = y

# Compute the PDF at each point on the grid
rv = multivariate_normal(mean, cov)
z = rv.pdf(pos)

# Convert the grid points and PDF values to 1D arrays
x = x.flatten()
y = y.flatten()
z = z.flatten()

# Create a 3D plot
fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')
ax.scatter(x, y, z, marker=".")

# Plot vertical lines connecting z points with x, y plane
for i in range(len(x)):
    ax.plot([x[i], x[i]], [y[i], y[i]], [0, z[i]], color='blue', linewidth=0.1)

# Set the viewing angle
ax.view_init(elev=30, azim=120)

# Remove the axis labels
ax.set_xticklabels([])
ax.set_yticklabels([])
ax.set_zticklabels([])


# Set the axis labels and title
ax.set_xlabel('x')
ax.set_ylabel('y')
ax.set_zlabel('PDF')
#ax.set_title('2D Gaussian Distribution')

#plt.show()
plt.savefig('../images/elip.png', dpi=200, format='png', transparent=True)
