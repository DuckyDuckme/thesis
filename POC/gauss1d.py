#!/usr/bin/python3

import numpy as np
import matplotlib.pyplot as plt

# Define our parameters
# Set n arbitrarily big, in this case 50 to not blow up my laptop
n = 32768
q = 1.5*n**2

# Define the x values
x = np.linspace(-q/2, q/2, 1000)

# Define the standard deviation
sigma = q/np.log(n)

# Compute the probability density function (PDF)
pdf = 1 / (sigma * np.sqrt(2 * np.pi)) * np.exp(-x**2 / (2 * sigma**2))

# Specify the x-value where the vertical line should be drawn
x_line = q/4

# Compute the y-value of the PDF at the specified x-value
y_line = 1 / (sigma * np.sqrt(2 * np.pi)) * np.exp(-(x_line)**2 / (2 * sigma**2))

# Create a plot
plt.plot(x, pdf)

# Add a vertical line at q/4
plt.plot([x_line, x_line], [0, y_line], color='black')
plt.plot([-x_line, -x_line], [0, y_line], color='black')

plt.plot([-q/2, q/2], [0,0], color='black')

# Shade the region under the curve between 0 and x_line
plt.fill_between(x, 0, pdf, where=(x >= x_line) & (x <= q/2), color='gray', alpha=0.5)
plt.fill_between(x, 0, pdf, where=(x <= -x_line) & (x >= -q/2), color='gray', alpha=0.5)

# Set the title and axis labels
plt.title('Standard Normal 1D Distribution')
plt.xlabel('x')
plt.ylabel('Probability density')

plt.savefig('../images/gaussian1d-32768.png', dpi=200, format='png', transparent=True)
#plt.show()

