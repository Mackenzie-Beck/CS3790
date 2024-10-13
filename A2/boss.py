import os
import sys


"""The boss process will try to find all primes from 1 to some upper bound by using the worker processes to search subsets of that range. 
The boss process will be given two integers as command line arguments : the first will be the number of workers processes to create; the second will be the upper bound.
The worker process will also be given two integers as command line arguments and will try to find all primes between those two values."""




if __name__ == "__main__":
    if len(sys.argv) != 3:
        #check if the number of arguments is correct
        print(f"Boss process, {os.getpid()}: Incorrect number of arguments")
        sys.exit(1)

    #check if the arguments are valid integers
    try:
        num_workers = int(sys.argv[1])
        upper_bound = int(sys.argv[2])
    except ValueError:
        print(f"Boss process, {os.getpid()}: Invalid arguments")
        sys.exit(1)

    #create the worker processes
    for i in range(num_workers):
        #create the worker process, parent will receive a pid, child will receive 0
        worker_pid = os.fork()
        if worker_pid == 0:
            #child process
            worker_script = "worker.py"
            worker_lower_bound = i * (upper_bound // num_workers)
            worker_upper_bound = (i + 1) * (upper_bound // num_workers)


            """use sys.executable to get the path to the Python interpreter and pass the worker script and arguments to it
            first arguement is the path to the interpreter
            Second arguement is the name of the program (python interpreter)
            Third arguement is the name of the script to execute (worker.py)
            The remaining arguements are the arguments to the script (str(i), str(upper_bound))"""
            os.execl(sys.executable, sys.executable, worker_script, str(worker_lower_bound), str(worker_upper_bound))
        elif worker_pid < 0:
            print(f"Boss process, {os.getpid()}: Failed to create worker process")
            sys.exit(1)
        else:
            print(f"Boss process, {os.getpid()}: Created worker process {worker_pid}")

    #wait for all the worker processes to finish
    for i in range(num_workers):
        os.wait()

    print(f"Boss process, {os.getpid()}: All worker processes have finished")
