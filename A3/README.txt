# Prime Number Range Server and Client

This project consists of a server and a client that communicate through a named pipe to compute prime numbers within a specified range.

## Files

- `server.py`: Contains the server code that listens for requests, computes prime numbers in the given range, and sends the response back to the client.
- `client.py`: Contains the client code that sends a range request to the server and receives the list of prime numbers in that range.
- `server_test.py`: Contains the unit tests for the server code.
## How to Run

### Server

1. Run the server script:
    ```sh
    python server.py
    ```
   The server will create a named pipe at `/tmp/pipe` and start listening for requests.

### Client

1. Run the client script:
    ```sh
    python client.py
    ```
   The client will prompt you to enter the lower and upper bounds of the range. It will then send the request to the server and print the list of prime numbers in that range.

## Example

1. Start the server:
    ```sh
    python server.py
    ```

2. In another terminal, start the client:
    ```sh
    python client.py
    ```

3. Enter the lower and upper bounds when prompted:
    ```
    Enter the lower bound of the range: 10
    Enter the upper bound of the range: 20
    ```

4. The client will display the response from the server:
    ```
    Primes in range 10-20: [11, 13, 17, 19]
    ```



## Running Unit Tests

To ensure that the server code is working correctly, you can run the unit tests provided in `server_test.py`.

1. Run the unit tests:
    ```sh
    python -m unittest server_test.py
    ```

2. The output will show the results of the tests, indicating whether the functions `is_prime` and `compute_primes` are working as expected.

Make sure to run the unit tests after making any changes to the server code to verify that everything is still functioning correctly.




## Notes

- Ensure that the named pipe `/tmp/pipe` does not already exist before starting the server. If it does, you can remove it using:
    ```sh
    rm /tmp/pipe
    ```
- The server will continue to run and listen for requests until it is manually stopped.

## License

This project is licensed under the MIT License.
