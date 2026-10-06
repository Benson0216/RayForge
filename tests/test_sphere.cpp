#include <gtest/gtest.h>

#include "Ray.h"
#include "Sphere.h"

TEST(SphereTest, RayMissesSphere) {
    Sphere sphere(1.0);
    Ray ray(Vec3(0.0, 0.0, -5.0), Vec3(0.0, 1.0, 0.0));

    EXPECT_FALSE(sphere.intersects(ray));
}

TEST(SphereTest, RayIntersectsSphere) {
    Sphere sphere(1.0);
    Ray ray(Vec3(0.0, 0.0, -5.0), Vec3(0.0, 0.0, 1.0));

    EXPECT_TRUE(sphere.intersects(ray));
}

TEST(SphereTest, RayTangentToSphere) {
    Sphere sphere(1.0);
    Ray ray(Vec3(1.0, 0.0, -5.0), Vec3(0.0, 0.0, 1.0));

    EXPECT_TRUE(sphere.intersects(ray));
}

TEST(SphereTest, RayOriginatesInsideSphere) {
    Sphere sphere(1.0);
    Ray ray(Vec3(0.0, 0.0, 0.0), Vec3(0.0, 0.0, 1.0));

    EXPECT_TRUE(sphere.intersects(ray));
}

TEST(SphereTest, ReturnsIntersectionValues) {
    Sphere sphere(1.0);
    Ray ray(Vec3(0.0, 0.0, -5.0), Vec3(0.0, 0.0, 1.0));

    auto intersections = sphere.intersections(ray);

    ASSERT_EQ(intersections.size(), 2);
    EXPECT_DOUBLE_EQ(intersections[0], 4.0);
    EXPECT_DOUBLE_EQ(intersections[1], 6.0);
}

TEST(SphereTest, ReturnsNoIntersectionsWhenRayMissesSphere) {
    Sphere sphere(1.0);
    Ray ray(Vec3(0.0, 0.0, -5.0), Vec3(0.0, 1.0, 0.0));

    auto intersections = sphere.intersections(ray);

    EXPECT_TRUE(intersections.empty());
}

TEST(SphereTest, ReturnsTangentIntersectionValue) {
    Sphere sphere(1.0);
    Ray ray(Vec3(1.0, 0.0, -5.0), Vec3(0.0, 0.0, 1.0));

    auto intersections = sphere.intersections(ray);

    ASSERT_EQ(intersections.size(), 2);
    EXPECT_DOUBLE_EQ(intersections[0], 5.0);
    EXPECT_DOUBLE_EQ(intersections[1], 5.0);
}

TEST(SphereTest, ReturnsIntersectionsWhenRayOriginatesInsideSphere) {
    Sphere sphere(1.0);
    Ray ray(Vec3(0.0, 0.0, 0.0), Vec3(0.0, 0.0, 1.0));

    auto intersections = sphere.intersections(ray);

    ASSERT_EQ(intersections.size(), 1);
    EXPECT_DOUBLE_EQ(intersections[0], 1.0);
}

TEST(SphereTest, IgnoresIntersectionsBehindRayOrigin) {
    Sphere sphere(1.0);
    Ray ray(Vec3(0.0, 0.0, 5.0), Vec3(0.0, 0.0, 1.0));

    auto intersections = sphere.intersections(ray);

    EXPECT_TRUE(intersections.empty());
}
