#!/bin/python3
# python script to plot a 2D lattice given some basis

import numpy as np
import matplotlib.pyplot as plt

def sample_lattice(generator_matrix, coefficient_sampler, filter_func, n_draws):
	pts = set()
	for i in range(n_draws):
	    n_i = coefficient_sampler()
	    lat_pt = np.dot(generator_matrix, n_i)
	    if filter_func(lat_pt):
		    pts.add(tuple(lat_pt))
	    
	return np.array(list(pts))


z2_generator = np.eye(2).astype(int)

pts_z2 = sample_lattice(z2_generator, coefficient_sampler = lambda : np.random.randint(-3, 3+1, (2,)), filter_func = lambda x: True, n_draws=1000)

plt.scatter(pts_z2[:, 0], pts_z2[:, 1], alpha=0.8, s=80)
plt.show()
