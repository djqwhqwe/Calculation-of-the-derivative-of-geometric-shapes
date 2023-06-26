#define _USE_MATH_DEFINES

#include "curves.h"
#include <cmath>



vector3 Circle::getPoint(const double t) const noexcept {
	return { std::cos(t) * m_radius, std::sin(t) * m_radius, 0.0 };
}

vector3 Circle::getDerivative(const double t) const noexcept {
	return { -std::sin(t) * m_radius, std::cos(t) * m_radius, 0.0 };
}

vector3 Ellipse::getPoint(const double t) const noexcept {
	return { std::cos(t) * m_radius_x, std::sin(t) * m_radius_y, 0.0 };
}

vector3 Ellipse::getDerivative(const double t) const noexcept {
	return { -std::sin(t) * m_radius_x, std::cos(t) * m_radius_y, 0.0 };
}

vector3 Helix::getPoint(const double t) const noexcept {
	return { std::cos(t) * m_radius, std::sin(t) * m_radius, m_step * (t / (2 * M_PI)) };
}

vector3 Helix::getDerivative(const double t) const noexcept {
	return { -std::sin(t) * m_radius, std::cos(t) * m_radius, m_step / (2 * M_PI) };
}

double Circle::getRadius() const noexcept {
	return m_radius;
}