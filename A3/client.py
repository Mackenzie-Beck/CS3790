import os

pipe_path = '/tmp/pipe'

def send_request(lower, upper):
    with open(pipe_path, 'w') as pipe:
        pipe.write(f"RANGE {lower} {upper}\n")

def receive_response():
    with open(pipe_path, 'r') as pipe:
        response = pipe.read()
        print(response)

if __name__ == "__main__":
    while True:
        try:
            lower = input("Enter the lower bound of the range: ")
            upper = input("Enter the upper bound of the range: ")
            send_request(lower, upper)
            receive_response()
        except ValueError:
            print("Please enter valid integers for the range.")

