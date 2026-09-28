/**
 * @file vector2d.cpp
 * @brief Implementation of a 2D vector class with operator overloading.
 */
#include <iostream>
#include <cmath>

/**
 * @class Vector2D
 * @brief Represents a 2D vector with x and y coordinates.
 */
class Vector2D
{
private:
    double x;
    double y;

public:

    Vector2D() : x(0.0), y(0.0) {}

    Vector2D(double x, double y) : x(x), y(y) {}

    double getX() const { return x; }
 
    double getY() const { return y; }

    void print() const
    {
        std::cout << '\n'
                  << "(" << this->getX() << ", " << this->getY() << ")" << std::endl;
    }

    double getMagnitude() const
    {
        return sqrt((x * x) + (y * y));
    }

    double getMagnitude(int precision) const;

    void operator+=(const Vector2D &vec)
    {
        this->x += vec.getX();
        this->y += vec.getY();
    }

    bool operator==(const Vector2D &vec) const;

    bool operator!=(const Vector2D &vec) const;
};

double Vector2D::getMagnitude(int precision) const
{
    double factor = std::pow(10.0, precision);
    double length = this->getMagnitude();
    return std::round(length * factor) / factor;
}

bool Vector2D::operator==(const Vector2D &vec) const
{
    const double EPSILON = 1e-9;
    return (std::fabs(x - vec.x) < EPSILON) &&
           (std::fabs(y - vec.y) < EPSILON);
}

bool Vector2D::operator!=(const Vector2D &vec) const
{
    const double EPSILON = 1e-9;
    return (std::fabs(x - vec.x) > EPSILON) ||
           (std::fabs(y - vec.y) > EPSILON);
}

Vector2D operator+(const Vector2D &vec_left, const Vector2D &vec_right)
{
    return Vector2D(vec_left.getX() + vec_right.getX(),
                    vec_left.getY() + vec_right.getY());
}

Vector2D operator*(int scalar, const Vector2D &vec)
{
    return Vector2D(scalar * vec.getX(), scalar * vec.getY());
}

Vector2D operator*(const Vector2D &vec, double scalar)
{
    return Vector2D(scalar * vec.getX(), scalar * vec.getY());
}

std::ostream &operator<<(std::ostream &outstream, const Vector2D &vec)
{
    outstream << "(" << vec.getX() << ", " << vec.getY() << ")";
    return outstream;
}

int main()
{
    // Part 2
    Vector2D vec1(4, 5);
    Vector2D vec2(1, 9);

    std::cout << vec1.getMagnitude() << std::endl;
    std::cout << vec1.getMagnitude(3) << std::endl;

    // Part 3
    Vector2D vec3 = vec1 + vec2;
    vec3.print();
    vec1 += vec2;
    vec1 = vec1 * 5;
    std::cout << vec1 << std::endl;

    // Part 4
    Vector2D vec4(1, 9);

    std::cout << (vec4 == vec2) << std::endl;
    std::cout << (vec1 != vec2) << std::endl;

    return 0;
}
