#include "compute.hpp"

#include <complex>
#include <algorithm>


int* compute(Resolution resolution, View view, int maxIterations) {
	int size = std::max(resolution.Width, resolution.Height);
	double scale = 3 / view.zoom;

	int* iterations = new int[resolution.Width * resolution.Height];

	int index = 0;
	for (int y = 0; y < resolution.Height; y++) {
		for (int x = 0; x < resolution.Width; x++) {
			std::complex<double> c = std::complex<double>(
				(x + .5 - resolution.Width / 2) / size * scale + view.center_x,
				(y + .5 - resolution.Height / 2) / size * scale + view.center_y
			);
			std::complex<double> z;

			int iteration;
			for (iteration = 0; iteration < maxIterations; iteration++) {
				z = z * z + c;
				if (z.real() * z.real() + z.imag() * z.imag() > 2) {
					break;
				}
			}

			iterations[index++] = iteration;
		}
	}

	return iterations;
}
