#include <gtest/gtest.h>

#include "Ray.h"
#include "Sphere.h"

TEST(HittableTest, SphereCanBeUsedAsHittable) {
    Sphere sphere(1.0);

    Hittable* hittable = &sphere;

    Ray ray(
        Vec3(0.0, 0.0, -5.0),
        Vec3(0.0, 0.0, 1.0)
    );

    EXPECT_TRUE(hittable->intersects(ray));
}
