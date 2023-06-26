#define _USE_MATH_DEFINES

#include <iostream>
#include <vector>
#include <random>
#include <cmath>
#include <algorithm>
#include <memory>
#include "curves.h"


double randomize(const double min, const double max) {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<double> dist(min, max);
	return dist(gen);
}

int main() {
	double t = M_PI / 4.0, total_radius = 0.0;
	std::vector<std::unique_ptr<Curves>> curves;
	std::vector<Circle*> circles;

	//Random populate
	for (int i = 0; i < 50; i++) {
		double rand = randomize(1.0, 10.0);
		if (rand > 1 && rand < 3) {
			curves.push_back(std::make_unique<Circle>(randomize(1.0, 10.0)));
		}
		else if (rand > 3 && rand < 7) {
			curves.push_back(std::make_unique<Ellipse>(randomize(1.0, 10.0), randomize(1.0, 10.0)));
		}
		else {
			curves.push_back(std::make_unique<Helix>(randomize(1.0, 10.0), randomize(1.0, 10.0)));
		}
	}

	//Output points and Derivatives
	for (const auto& curve : curves) {
		if (dynamic_cast<Circle*>(curve.get())) {
			std::cout << "Circle" << std::endl;
			std::cout << "Point: " << curve->getPoint(t).x << " " << curve->getPoint(t).y << " " << curve->getPoint(t).z << std::endl;
			std::cout << "Derivative: " << curve->getDerivative(t).x << " " << curve->getDerivative(t).y << " " << curve->getDerivative(t).z << std::endl;
		}
		else if (dynamic_cast<Ellipse*>(curve.get())) {
			std::cout << "Ellipse" << std::endl;
			std::cout << "Point: " << curve->getPoint(t).x << " " << curve->getPoint(t).y << " " << curve->getPoint(t).z << std::endl;
			std::cout << "Derivative: " << curve->getDerivative(t).x << " " << curve->getDerivative(t).y << " " << curve->getDerivative(t).z << std::endl;
		}
		else if (dynamic_cast<Helix*>(curve.get())) {
			std::cout << "Helix" << std::endl;
			std::cout << "Point: " << curve->getPoint(t).x << " " << curve->getPoint(t).y << " " << curve->getPoint(t).z << std::endl;
			std::cout << "Derivative: " << curve->getDerivative(t).x << " " << curve->getDerivative(t).y << " " << curve->getDerivative(t).z << std::endl;
		}
		//Filling the second container with pointers to circles from the first container
		if (Circle* circle = dynamic_cast<Circle*>(curve.get())) {
			circles.push_back(circle);
		}
	}
	//Sort
	std::sort(circles.begin(), circles.end(), [](Circle* a, Circle* b) { return a->getRadius() < b->getRadius(); });

	//Output
	std::cout << "\n\nSorted circles:" << std::endl;
	for (Circle* circle : circles) {
		std::cout << "Radius: " << circle->getRadius() << std::endl;
	}
	for (Circle* circle : circles) {
		total_radius += circle->getRadius();
	}
	std::cout << "Total radius sum is " << total_radius << std::endl;
	return 0;
}