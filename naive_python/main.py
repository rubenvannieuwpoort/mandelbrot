from compute import compute
from render import render
from display import display

from stopwatch import Stopwatch


max_iterations = 256
resolution = (1024, 1024)

zoom = 1
view = (-1, 0), zoom

stopwatch = Stopwatch()

stopwatch.start()
iterations = compute(resolution, view, max_iterations)
stopwatch.stop()

image = render(iterations, max_iterations)
display("Mandelbrot", image, resolution)

print(stopwatch.time)
