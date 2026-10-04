#pragma once

#include <cmath>

class Vec3 {
public:
    Vec3(double x, double y, double z)
        : x_(x), y_(y), z_(z) {}

    Vec3 operator+(const Vec3& other) const {
        return Vec3(
            x_ + other.x_,
            y_ + other.y_,
            z_ + other.z_
        );
    }

    Vec3 operator/(double scalar) const {
        return Vec3(
            x_ / scalar,
            y_ / scalar,
            z_ / scalar
        );
    }

    Vec3 operator*(double scalar) const {
        return Vec3(
            x_ * scalar,
            y_ * scalar,
            z_ * scalar
        );
    }

    Vec3 operator-(const Vec3& other) const {
        return Vec3(
            x_ - other.x_,
            y_ - other.y_,
            z_ - other.z_
        );
    }

    Vec3 normalized() const {
        return *this / length();
    }

    double length() const {
        return std::sqrt(lengthSquared());
    }

    double lengthSquared() const {
        return x_ * x_ + y_ * y_ + z_ * z_;
    }

    Vec3 cross(const Vec3& other) const {
        return Vec3(
            y_ * other.z_ - z_ * other.y_,
            z_ * other.x_ - x_ * other.z_,
            x_ * other.y_ - y_ * other.x_
        );
    }

    double dot(const Vec3& other) const {
        return x_ * other.x_
             + y_ * other.y_
             + z_ * other.z_;
    }

    double x() const {
        return x_;
    }

    double y() const {
        return y_;
    }

    double z() const {
        return z_;
    }

private:
    double x_;
    double y_;
    double z_;
};
