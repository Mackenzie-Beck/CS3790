import os




def is_prime(n):
    """Check if a number is prime."""
    if n <= 1:
        return False
    if n <= 3:
        return True
    if n % 2 == 0 or n % 3 == 0:
        return False
    i = 5
    while i * i <= n:
        if n % i == 0 or n % (i + 2) == 0:
            return False
        i += 6
    return True

def compute_primes(lower, upper):
    """Compute all prime numbers in the given range."""
    return [n for n in range(lower, upper + 1) if is_prime(n)]



def main():
    pipe_path = '/tmp/pipe'

    # Create a named pipe
    try:
        os.mkfifo(pipe_path)
    except FileExistsError:
        print(f"Named pipe {pipe_path} already exists.")

    print(f"Server listening on {pipe_path}...")

    try:
        while True:
            with open(pipe_path, 'r') as pipe:
                request = pipe.read().strip()
                print(f"Received request: {request}")
                if request.startswith("RANGE"):
                    try:
                        _, lower, upper = request.split()
                        lower, upper = int(lower), int(upper)
                        primes = compute_primes(lower, upper)
                        response = f"Primes in range {lower}-{upper}: {primes}\n"
                    except ValueError:
                        response = "malformed request\n"
                else:
                    response = "malformed request\n"

                # Write the response back to the pipe
                with open(pipe_path, 'w') as pipe:
                    print(f"Sending response: {response}")
                    pipe.write(response)

    finally:
        os.remove(pipe_path)

if __name__ == "__main__":
    main()
