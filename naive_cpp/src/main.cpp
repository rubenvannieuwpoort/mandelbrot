#include "compute.hpp"
#include "render.hpp"
#include "display.hpp"

#include "stopwatch.hpp"

#include <iostream>


int main(int argc, char* argv[]) {
	int max_iterations = 256;
	Resolution resolution = { 1024, 1024 };

	double zoom = 1;
	View view = { -1, 0, zoom };

	Stopwatch stopwatch;

	stopwatch.Start();
	int* iterations = compute(resolution, view, max_iterations);
	stopwatch.Stop();

	Uint32* image = render(resolution, iterations, max_iterations);
	display("Mandelbrot", image, resolution);

	std::cout << stopwatch.Time << '\n';
	return 0;
}
