# Prime Number Finder Project
# Mackenzie Beck
# 5086546


## Overview
This project consists of a boss process and multiple worker processes to find all prime numbers within a given range. The boss process distributes the workload among the worker processes, which then search for prime numbers in their assigned subranges.

## Files
- `boss.py`: The main script that initiates the boss process, creates worker processes, and coordinates the overall prime number finding task.
- `worker.py`: The script executed by each worker process to find prime numbers within a specific subrange.

## How It Works
1. The boss process is executed with two command line arguments:
   - The number of worker processes to create.
   - The upper bound of the range within which to find prime numbers.
2. The boss process clears any existing `.txt` files in the current directory.
3. The boss process validates the command line arguments.
4. The boss process creates the specified number of worker processes using `os.fork()`.
5. Each worker process executes `worker.py` with its assigned subrange as arguments.
6. The worker processes find prime numbers in their subranges and write the results to `.txt` files.
7. The boss process waits for all worker processes to finish.
8. The boss process prints a message indicating that all worker processes have finished.

## Usage
To run the boss process, use the following command:
python boss.py <number_of_workers> <upper_bound>

To run the worker process, use the following command:
python worker.py <subrange_start> <subrange_end>

