#pragma once
class Vector
{
private:
	float m_x;
	float m_y;

public:
	Vector(float init_x, float init_y);

	Vector();

	void setX(float new_x);
	inline float getX() const { return m_x; }
	
	
	void setY(float new_y);
	inline float getY() const { return m_y; } ;

	void setXY(float new_x, float new_y);

	float getMagnitude() const;

	void normalize();

	void scale(float s);

	Vector operator+(const Vector& other) const;


};

