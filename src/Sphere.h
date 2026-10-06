#pragma once

#include <vector>
#include <cmath>

#include "Ray.h"


class Sphere {
public:
    explicit Sphere(double radius)
        : radius_(radius) {}

    bool intersects(const Ray& ray) const {
        Vec3 oc = ray.origin();

        double a = ray.direction().lengthSquared();
        double b = 2.0 * oc.dot(ray.direction());
        double c = oc.lengthSquared() - radius_ * radius_;

        double discriminant = b * b - 4.0 * a * c;

        return discriminant >= 0.0;
    }

    std::vector<double> intersections(const Ray& ray) const {
        Vec3 oc = ray.origin();

        double a = ray.direction().lengthSquared();
        double b = 2.0 * oc.dot(ray.direction());
        double c = oc.lengthSquared() - radius_ * radius_;

        double discriminant = b * b - 4.0 * a * c;

        if (discriminant < 0.0) {
            return {};
        }

        double sqrtDiscriminant = std::sqrt(discriminant);

        double t1 = (-b - sqrtDiscriminant) / (2.0 * a);
        double t2 = (-b + sqrtDiscriminant) / (2.0 * a);

        std::vector<double> intersections;

        if (t1 >= 0.0) {
            intersections.push_back(t1);
        }

        if (t2 >= 0.0) {
            intersections.push_back(t2);
        }

        return intersections;
    }

private:
    double radius_;
};
