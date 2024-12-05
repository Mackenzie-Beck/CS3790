# Banker's Algorithm Project

This project implements the Banker's Algorithm, which is used in operating systems to avoid deadlock by allocating resources to processes in a safe manner.

## Files

- `bankersAlg.cpp`: Contains the implementation of the Banker's Algorithm, including functions to check resource allocation, process needs, and the safety algorithm.

## How to Compile

To compile the project, use the following command:

```
make
```

## How to Run Tests

To compile the tests, use the following command:

```
make test
```
and then run the tests with:

```
./tests
```

## How to Run

To run the program, use the following command:

```
./bankersAlg inputfile
```

Where `inputfile` is the name of the input file containing:

- The number of processes
- The number of resources
- The MAX matrix
- the AVAILABLE vector