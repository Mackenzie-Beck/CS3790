import os


pipe_path = 'tmp/pipe'
#create a named pipe
try:
    os.mkfifo("pipe")
except FileExistsError:
    print(f"Pipe {pipe_path} already exists")

