//
// Created by Светлана Пислякова on 28.11.2024.
//

#ifndef TEST_LEDAS_VECTOR3D_H
#define TEST_LEDAS_VECTOR3D_H


class Vector3D {
public:
    Vector3D(double x = 0, double y = 0, double z = 0);

    ~Vector3D();

    Vector3D operator-(const Vector3D &other) const;

    Vector3D operator+(const Vector3D &other) const;

    Vector3D operator*(const double scalar) const;

    bool operator==(const Vector3D &other) const;

    Vector3D VectorMult(const Vector3D &other) const;

    double ScalarMult(const Vector3D &other) const;

    double MixedMult(const Vector3D &first, const Vector3D &second) const;

    bool IsCollinear(const Vector3D &other) const;

    double GetX() const;

    double GetY() const;

    double GetZ() const;

private:
    double x_;
    double y_;
    double z_;
};

#endif //TEST_LEDAS_VECTOR3D_H
