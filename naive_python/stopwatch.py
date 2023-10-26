from time import time

class Stopwatch:
    def __init__(self):
        self.start_time = None
        self.time = None

    def start(self):
        self.start_time = time()

    def stop(self):
        self.time = time() - self.start_time
