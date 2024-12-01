//
// Created by Светлана Пислякова on 28.11.2024.
//

#include "Vector3D.h"
#include <limits>
#include <cmath>

Vector3D::Vector3D(double x, double y, double z) : x_(x), y_(y), z_(z) {}

Vector3D::~Vector3D() {}

Vector3D Vector3D::operator-(const Vector3D &other) const {
    return Vector3D(x_ - other.x_, y_ - other.y_, z_ - other.z_);
}

Vector3D Vector3D::operator+(const Vector3D &other) const {
    return Vector3D(x_ + other.x_, y_ + other.y_, z_ + other.z_);
}

Vector3D Vector3D::operator*(const double scalar) const {
    return Vector3D(x_ * scalar, y_ * scalar, z_ * scalar);
}

bool Vector3D::operator==(const Vector3D &other) const {
    return x_ == other.x_ && y_ == other.y_ && z_ == other.z_;
}

Vector3D Vector3D::VectorMult(const Vector3D &other) const {
    Vector3D result(y_ * other.z_ - z_ * other.y_, z_ * other.x_ - x_ * other.z_, x_ * other.y_ - y_ * other.x_);
    return result;
}

double Vector3D::ScalarMult(const Vector3D &other) const {
    return x_ * other.x_ + y_ * other.y_ + z_ * other.z_;
}

double Vector3D::MixedMult(const Vector3D &first, const Vector3D &second) const {
    return ScalarMult(first.VectorMult(second));
}

bool Vector3D::IsCollinear(const Vector3D &other) const {
    Vector3D temp = VectorMult(other);
    return fabs(temp.x_) < std::numeric_limits<double>::epsilon() &&
           fabs(temp.y_) < std::numeric_limits<double>::epsilon() &&
           fabs(temp.z_) < std::numeric_limits<double>::epsilon();
}

double Vector3D::GetX() const { return x_; }

double Vector3D::GetY() const { return y_; }

double Vector3D::GetZ() const { return z_; }
