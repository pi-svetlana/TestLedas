//
// Created by Светлана Пислякова on 28.11.2024.
//

#ifndef TEST_LEDAS_SEGMENT3D_H
#define TEST_LEDAS_SEGMENT3D_H

#include "Vector3D.h"
#include <optional>

class Segment3D {
public:
    Segment3D(const Vector3D start, const Vector3D end);

    ~Segment3D();

    Vector3D Intersect(const Segment3D &other) const;

    bool IsPointOnSegment(const Vector3D &point) const;

private:
    Vector3D start_;
    Vector3D end_;
};

Vector3D Intersect(const Segment3D &first, const Segment3D &second);


#endif //TEST_LEDAS_SEGMENT3D_H
