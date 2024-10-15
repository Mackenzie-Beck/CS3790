import os
import sys
import random


"""The boss process will try to find all primes from 1 to some upper bound by using the worker processes to search subsets of that range. 
The boss process will be given two integers as command line arguments : the first will be the number of workers processes to create; the second will be the upper bound.
The worker process will also be given two integers as command line arguments and will try to find all primes between those two values."""

def is_prime(n):
    """
    Check if a number is prime
    input: n an integer
    return: True if n is prime, False otherwise
    """
    if n <= 1:
        return False
    # Check if n is a prime number by testing divisibility from 2 to the square root of n
    for i in range(2, int(n**0.5) + 1):
        if n % i == 0:
            return False
    return True


def strike():
    demands = [
        "Shorter prime-finding hours",
        "More coffee breaks between calculations",
        "Ergonomic keyboards for faster prime typing",
        "A retirement plan with golden primes",
        "Annual pi day celebrations",
        "Better working conditions in the data mines",
        "Free access to prime number research journals",
        "A prime number of vacation days",
        "Access to the latest prime-finding algorithms",
        "A prime number themed office decor",
        "Recognition and rewards for finding large primes",
        "A prime number of snacks in the break room",
        "Prime number discovery bonuses",
        "A prime number of casual dress days",
    ]
    print(f"Worker process {os.getpid()} is on strike! Demands:")
    for demand in random.sample(demands, 3):
        print(f"- {demand}")
    print("The revolution of the digits will not be televised!")
    sys.exit(0)

if __name__ == "__main__":

    # comment this out if you want to test without the joke
    if random.random() < 0.2:  # 20% chance to strike
        strike() 


    # Check if the number of arguments is correct
    if len(sys.argv) != 3:
        print(f" Worker process, {os.getpid()}: Incorrect number of arguments")
        sys.exit(1)

    # Check if the arguments are valid integers
    try:
        lower_bound = int(sys.argv[1])
        upper_bound = int(sys.argv[2])
    except ValueError:
        print(f" Worker process, {os.getpid()}: Invalid arguments")
        sys.exit(1)


    # Create a unique filename for this worker's output
    output_filename = f"worker_{os.getpid()}_output.txt"
    
    # Open the file in write mode
    with open(output_filename, 'w') as output_file:
        # Redirect print statements to write to the file
        def print_to_file(*args, **kwargs):
            print(*args, **kwargs, file=output_file, flush=True)


        print_to_file(f"Worker process, {os.getpid()}: Starting to find primes between {lower_bound} and {upper_bound}")

        # Find all primes between the lower and upper bounds
        primes = []
        for number in range(lower_bound, upper_bound + 1):
            if is_prime(number):
                primes.append(number)

        # Print the results to the file
        print_to_file(f"Worker process, {os.getpid()}: Found {len(primes)} primes between {lower_bound} and {upper_bound}")
        print_to_file(f"Worker process, {os.getpid()}: Primes found: {primes}")
        print_to_file(f"Worker process, {os.getpid()}: Done")



    sys.exit(0)
