#pragma once

namespace df
{
	class Vector
	{
	private:
		float m_x;
		float m_y;

	public:
		Vector();

		Vector(float init_x, float init_y);

		Vector operator+(const Vector& other) const;

		bool operator!=(const Vector& other) const;

		bool operator==(const Vector& other) const;

		Vector operator*(const float& other) const;

		void setX(float new_x);

		inline float getX() const { return m_x; }

		void setY(float new_y);
		inline float getY() const { return m_y; };

		void setXY(float new_x, float new_y);

		float getMagnitude() const;

		void normalize();

		void scale(float s);




	};

}


