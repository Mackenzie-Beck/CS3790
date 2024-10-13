import os
import sys


"""The boss process will try to find all primes from 1 to some upper bound by using the worker processes to search subsets of that range. 
The boss process will be given two integers as command line arguments : the first will be the number of workers processes to create; the second will be the upper bound.
The worker process will also be given two integers as command line arguments and will try to find all primes between those two values."""
