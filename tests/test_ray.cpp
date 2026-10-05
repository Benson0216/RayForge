#include <gtest/gtest.h>

#include "Ray.h"

TEST(RayTest, ConstructsWithOriginAndDirection) {
    Vec3 origin(1.0, 2.0, 3.0);
    Vec3 direction(4.0, 5.0, 6.0);

    Ray ray(origin, direction);

    EXPECT_DOUBLE_EQ(ray.origin().x(), 1.0);
    EXPECT_DOUBLE_EQ(ray.origin().y(), 2.0);
    EXPECT_DOUBLE_EQ(ray.origin().z(), 3.0);

    EXPECT_DOUBLE_EQ(ray.direction().x(), 4.0);
    EXPECT_DOUBLE_EQ(ray.direction().y(), 5.0);
    EXPECT_DOUBLE_EQ(ray.direction().z(), 6.0);
}

TEST(RayTest, EvaluatesPointAtParameter) {
    Vec3 origin(1.0, 2.0, 3.0);
    Vec3 direction(4.0, 5.0, 6.0);

    Ray ray(origin, direction);

    Vec3 point = ray.at(2.0);

    EXPECT_DOUBLE_EQ(point.x(), 9.0);
    EXPECT_DOUBLE_EQ(point.y(), 12.0);
    EXPECT_DOUBLE_EQ(point.z(), 15.0);
}
