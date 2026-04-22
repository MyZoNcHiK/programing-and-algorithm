#include <iostream>
#include <cmath>

class Point3D;

class Vector3D {
    double m_x;
    double m_y;
    double m_z;

    double length(double x, double y, double z) {
        return sqrt(x * x + y * y + z * z);
    }

    double length() {
        return sqrt(m_x * m_x + m_y * m_y + m_z * m_z);
    }

public:
    Vector3D(double x = 0.0, double y = 0.0, double z = 0.0)
        : m_x(x), m_y(y), m_z(z) {}

    bool isVectorBetweenPointsNormalized(const Point3D& p);

    void normalize() {
        double len = length();
        if (len > 1e-9) {
            m_x /= len;
            m_y /= len;
            m_z /= len;
        }
    }

    void print() {
        std::cout << "Vector("
                  << m_x << ", "
                  << m_y << ", "
                  << m_z << ")" << std::endl;
    }
};

class Point3D {
    double m_x;
    double m_y;
    double m_z;

public:
    Point3D(double x = 0.0, double y = 0.0, double z = 0.0)
        : m_x(x), m_y(y), m_z(z) {}

    friend bool Vector3D::isVectorBetweenPointsNormalized(const Point3D& p);

    void print() {
        std::cout << "Point("
                  << m_x << ", "
                  << m_y << ", "
                  << m_z << ")" << std::endl;
    }
};

bool Vector3D::isVectorBetweenPointsNormalized(const Point3D& p) {
    double x = p.m_x - m_x;
    double y = p.m_y - m_y;
    double z = p.m_z - m_z;

    return fabs(length(x, y, z) - 1.0) < 1e-9;
}

int main() {
    Vector3D v(0, 0, 0);
    Point3D p(1, 0, 0);

    v.print();
    p.print();

    if (v.isVectorBetweenPointsNormalized(p)) {
        std::cout << "Вектор нормалізований (довжина = 1)" << std::endl;
    } else {
        std::cout << "Вектор НЕ нормалізований" << std::endl;
    }

    return 0;
}
