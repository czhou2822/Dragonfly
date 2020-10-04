#include <math.h>

#include "Vector.h"


Vector::Vector(float init_x, float init_y)
    :m_x(init_x)
    ,m_y(init_y)
{
}

Vector::Vector()
    :m_x(0.f)
    ,m_y(0.f)
{

}

void Vector::setX(float new_x)
{
    m_x = new_x;
}

void Vector::setY(float new_y)
{
    m_y = new_y;
}

void Vector::setXY(float new_x, float new_y)
{
    setX(new_x);
    setY(new_y);
}

float Vector::getMagnitude() const
{
    float mag = sqrt(m_x * m_x + m_y * m_y);
    return mag;
}

void Vector::normalize()
{
    float lenth = getMagnitude();

    if (lenth > 0)
    {
        m_x = m_x / lenth;
        m_y = m_y / lenth;
    }
}

void Vector::scale(float s)
{
    m_y *= s;
    m_x *= s;
}

Vector Vector::operator+(const Vector& other) const
{
    Vector v;

    v.m_x = m_x + other.m_x;
    v.m_y = m_y + other.m_y;

    return v;
}
