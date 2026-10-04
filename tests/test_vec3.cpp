#include <gtest/gtest.h>

#include "Vec3.h"

TEST(Vec3Test, ConstructsWithGivenComponents) {
    Vec3 v(1.0, 2.0, 3.0);

    EXPECT_DOUBLE_EQ(v.x(), 1.0);
    EXPECT_DOUBLE_EQ(v.y(), 2.0);
    EXPECT_DOUBLE_EQ(v.z(), 3.0);
}

TEST(Vec3Test, AddsTwoVectors) {
    Vec3 a(1.0, 2.0, 3.0);
    Vec3 b(4.0, 5.0, 6.0);

    Vec3 result = a + b;

    EXPECT_DOUBLE_EQ(result.x(), 5.0);
    EXPECT_DOUBLE_EQ(result.y(), 7.0);
    EXPECT_DOUBLE_EQ(result.z(), 9.0);
}

TEST(Vec3Test, SubtractsTwoVectors) {
    Vec3 a(4.0, 5.0, 6.0);
    Vec3 b(1.0, 2.0, 3.0);

    Vec3 result = a - b;

    EXPECT_DOUBLE_EQ(result.x(), 3.0);
    EXPECT_DOUBLE_EQ(result.y(), 3.0);
    EXPECT_DOUBLE_EQ(result.z(), 3.0);
}

TEST(Vec3Test, MultipliesByScalar) {
    Vec3 v(1.0, 2.0, 3.0);

    Vec3 result = v * 2.0;

    EXPECT_DOUBLE_EQ(result.x(), 2.0);
    EXPECT_DOUBLE_EQ(result.y(), 4.0);
    EXPECT_DOUBLE_EQ(result.z(), 6.0);
}

TEST(Vec3Test, DividesByScalar) {
    Vec3 v(2.0, 4.0, 6.0);

    Vec3 result = v / 2.0;

    EXPECT_DOUBLE_EQ(result.x(), 1.0);
    EXPECT_DOUBLE_EQ(result.y(), 2.0);
    EXPECT_DOUBLE_EQ(result.z(), 3.0);
}

TEST(Vec3Test, CalculatesDotProduct) {
    Vec3 a(1.0, 2.0, 3.0);
    Vec3 b(4.0, 5.0, 6.0);

    double result = a.dot(b);

    EXPECT_DOUBLE_EQ(result, 32.0);
}

TEST(Vec3Test, CalculatesCrossProduct) {
    Vec3 a(1.0, 0.0, 0.0);
    Vec3 b(0.0, 1.0, 0.0);

    Vec3 result = a.cross(b);

    EXPECT_DOUBLE_EQ(result.x(), 0.0);
    EXPECT_DOUBLE_EQ(result.y(), 0.0);
    EXPECT_DOUBLE_EQ(result.z(), 1.0);
}

TEST(Vec3Test, CalculatesLength) {
    Vec3 v(3.0, 4.0, 0.0);

    EXPECT_DOUBLE_EQ(v.lengthSquared(), 25.0);
    EXPECT_DOUBLE_EQ(v.length(), 5.0);
}

TEST(Vec3Test, NormalizesVector) {
    Vec3 v(3.0, 4.0, 0.0);

    Vec3 result = v.normalized();

    EXPECT_DOUBLE_EQ(result.x(), 0.6);
    EXPECT_DOUBLE_EQ(result.y(), 0.8);
    EXPECT_DOUBLE_EQ(result.z(), 0.0);
}
