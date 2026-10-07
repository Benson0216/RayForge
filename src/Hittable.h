#pragma once

#include "Ray.h"

class Hittable {
public:
    virtual ~Hittable() = default;

    virtual bool intersects(const Ray& ray) const = 0;
};
