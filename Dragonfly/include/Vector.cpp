#include <math.h>

#include "Vector.h"


df::Vector::Vector(float init_x, float init_y)
    :m_x(init_x)
    ,m_y(init_y)
{
}

df::Vector::Vector()
    :m_x(0.f)
    ,m_y(0.f)
{

}

void df::Vector::setX(float new_x)
{
    m_x = new_x;
}

void df::Vector::setY(float new_y)
{
    m_y = new_y;
}

void df::Vector::setXY(float new_x, float new_y)
{
    setX(new_x);
    setY(new_y);
}

float df::Vector::getMagnitude() const
{
    float mag = sqrt(m_x * m_x + m_y * m_y);
    return mag;
}

void df::Vector::normalize()
{
    float lenth = getMagnitude();

    if (lenth > 0)
    {
        m_x = m_x / lenth;
        m_y = m_y / lenth;
    }
}

void df::Vector::scale(float s)
{
    m_y *= s;
    m_x *= s;
}

df::Vector df::Vector::operator+(const Vector& other) const
{
    Vector v;

    v.m_x = m_x + other.m_x;
    v.m_y = m_y + other.m_y;

    return v;
}

bool df::Vector::operator!=(const Vector& other) const
{
    if (this->m_x == other.m_x && this->m_y == other.m_y)
    {
        return false;
    }
    return true;
}

bool df::Vector::operator==(const Vector& other) const
{
    return !df::Vector::operator!=(other);
}

df::Vector df::Vector::operator*(const float& other) const
{
    Vector product(m_x * other, m_y * other);
    return product;
}
