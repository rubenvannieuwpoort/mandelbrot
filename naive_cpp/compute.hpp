#pragma once

struct Resolution {
	int Width, Height;
};

struct View {
	double center_x, center_y;
	double zoom;
};

int* compute(Resolution resolution, View view, int maxIterations);
