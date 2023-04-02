#!/usr/bin/python3

import numpy as np
import matplotlib.pyplot as plt

# Define our parameters
# Set n arbitrarily big, in this case 50 to not blow up my laptop
n = 100
q = 1.5*n**2

# Define the x values
x = np.linspace(-q/2, q/2, 1000)

# Define the standard deviation
sigma = q/np.log(n)

# Compute the probability density function (PDF)
pdf = 1 / (sigma * np.sqrt(2 * np.pi)) * np.exp(-x**2 / (2 * sigma**2))

# Create a plot
plt.plot(x, pdf)

# Add a vertical line at x=1
plt.axvline(x=q/4, color='red')
plt.axvline(x=-q/4, color='red')

# Set the title and axis labels
plt.title('Standard Normal Distribution')
plt.xlabel('x')
plt.ylabel('Probability density')

plt.show()

