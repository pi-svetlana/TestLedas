//
// Created by Светлана Пислякова on 28.11.2024.
//

#include "Segment3D.h"
#include <iostream>

Segment3D::Segment3D(const Vector3D start, const Vector3D end) : start_(start), end_(end) {}

Segment3D::~Segment3D() {}

bool Segment3D::IsPointOnSegment(const Vector3D &point) const {
    if ((point - start_).IsCollinear(end_ - start_)) {
        if (std::min(start_.GetX(), end_.GetX()) <= point.GetX() &&
            std::max(start_.GetX(), end_.GetX()) >= point.GetX() &&
            std::min(start_.GetY(), end_.GetY()) <= point.GetY() &&
            std::max(start_.GetY(), end_.GetY()) >= point.GetY() &&
            std::min(start_.GetZ(), end_.GetZ()) <= point.GetZ() &&
            std::max(start_.GetZ(), end_.GetZ()) >= point.GetZ())
            return true;
    }
    return false;
}

Vector3D Segment3D::Intersect(const Segment3D &other) const {
    if (end_ == start_ && other.end_ == other.start_) {
        if (end_ == other.end_) return end_;
        throw std::runtime_error("Оба отрезка вырождены в точку и не совпадают");
    }
    if (end_ == start_) {
        if (other.IsPointOnSegment(end_)) return end_;
        throw std::runtime_error("Один из отрезков вырожден в точку и не совпадает со вторым");
    }
    if (other.end_ == other.start_) {
        if (IsPointOnSegment(other.end_)) return other.end_;
        throw std::runtime_error("Один из отрезков вырожден в точку и не совпадает со вторым");
    }
    Vector3D first = end_ - start_;
    Vector3D second = other.end_ - other.start_;
    Vector3D temp = start_ - other.start_;
    if (fabs(first.MixedMult(second, temp)) < std::numeric_limits<double>::epsilon()) {
        if (!first.IsCollinear(second)) {
            double t, det, det_t;
            det = first.GetX() * (-second.GetY()) - (-second.GetX()) * first.GetY();
            det_t = (other.start_.GetX() - start_.GetX()) * (-second.GetY()) -
                    (other.start_.GetY() - start_.GetY()) * (-second.GetX());
            t = det_t / det;
            if (t >= 0 && t <= 1) {
                return start_ + first * t;
            } else throw std::runtime_error("Отрезки не пересекаются");

        } else {
            if (IsPointOnSegment(other.start_) || IsPointOnSegment(other.end_) || other.IsPointOnSegment(start_)) {
                if ((start_ == other.start_ && !IsPointOnSegment(other.end_) && !other.IsPointOnSegment(end_)) ||
                    (start_ == other.end_ && !IsPointOnSegment(other.start_) && !other.IsPointOnSegment(end_)))
                    return start_;
                if ((end_ == other.start_ && !IsPointOnSegment(other.end_) && !other.IsPointOnSegment(start_)) ||
                    (end_ == other.end_ && !IsPointOnSegment(other.start_) &&
                     !other.IsPointOnSegment(start_)))
                    return end_;
                throw std::runtime_error("Отрезки совпадают полностью либо частично");
            }
            throw std::runtime_error("Отрезки не пересекаются");
        }
    } else {
        throw std::runtime_error("Отрезки не пересекаются");
    }
}

Vector3D Intersect(const Segment3D &first, const Segment3D &second) {
    try {
        return first.Intersect(second);
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return {NAN, NAN, NAN};
    }
}
