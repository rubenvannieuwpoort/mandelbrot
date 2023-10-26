#pragma once
#include <SDL2/SDL.h>

#include "compute.hpp"
#include <cstdint>


Uint32 *render(Resolution resolution, int *iterations, int max_iterations) {
	double scale = 255.0 / max_iterations;
	Uint32 *image = new Uint32[resolution.Width * resolution.Height];

	int index = 0;
	for (int y = 0; y < resolution.Height; y++) {
		for (int x = 0; x < resolution.Width; x++) {
			uint8_t i = static_cast<uint8_t>(iterations[index] * scale);
			image[index++] = (i << 16) + (i << 8) + i;
		}
	}

	return image;
}
