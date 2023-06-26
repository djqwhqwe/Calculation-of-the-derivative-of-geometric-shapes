#pragma once

struct vector3 { double x, y, z; };

class Curves {
	public:
		virtual vector3 getPoint(const double t) const noexcept = 0;
		virtual vector3 getDerivative(const double t) const noexcept = 0;
		virtual ~Curves() {}
};

class Circle : public Curves {
	public:
		Circle(const double radius) : m_radius{ radius } {}
		vector3 getPoint(const double t) const noexcept override;
		vector3 getDerivative(const double t) const noexcept override;
		~Circle() {};
		double getRadius() const noexcept;

	private:
		double m_radius;
};

class Ellipse : public Curves {
	public:
		Ellipse(const double radius_x, const double radius_y) : m_radius_x{ radius_x }, m_radius_y{ radius_y } {}
		vector3 getPoint(const double t) const noexcept override;
		vector3 getDerivative(const double t) const noexcept override;
		~Ellipse() {};
	private:
		double m_radius_x, m_radius_y;
};

class Helix : public Curves {
	public:
		Helix(const double radius_x, const double step) : m_radius{ radius_x }, m_step{ step } {}
		vector3 getPoint(const double t) const noexcept override;
		vector3 getDerivative(const double t) const noexcept override;
		~Helix() {};

	private:
	double m_radius, m_step;
};
