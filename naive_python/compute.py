def compute(resolution, view, max_iterations):
    width, height = resolution
    size = max(width, height)

    (center_x, center_y), zoom = view
    scale = 3 / zoom

    iterations = [[0] * height for _ in range(0, width)]
    for y in range(0, height):
        for x in range(0, width):
            c = complex((x + .5 - width / 2) / size * scale + center_x, (y + .5 - height / 2) / size * scale + center_y)
            z = complex(0, 0)

            for iteration in range(0, max_iterations):
                z = z * z + c
                if z.real * z.real + z.imag * z.imag > 2:
                    break

            iterations[x][y] = iteration

    return iterations
