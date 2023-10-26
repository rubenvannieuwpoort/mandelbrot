#pragma once

#include <chrono>


struct Stopwatch {
	void Start() {
		this->StartTime = std::chrono::high_resolution_clock::now();
	}

	void Stop() {
		this->Time = std::chrono::duration<double>(std::chrono::high_resolution_clock::now() - this->StartTime).count();
	}

	std::chrono::time_point<std::chrono::high_resolution_clock> StartTime = std::chrono::time_point< std::chrono::high_resolution_clock>();
	double Time;
};
