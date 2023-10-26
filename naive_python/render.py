scale = None

def f(iterations):
    i = int(iterations * scale)
    return (i, i, i)

def render(iterations, max_iterations):
    global scale
    scale = 255 / max_iterations
    return list(map(lambda x: list(map(lambda y: f(y), x)), iterations))
