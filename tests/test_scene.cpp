#include <gtest/gtest.h>

#include "Scene.h"
#include "Sphere.h"

TEST(SceneTest, StartsEmpty) {
    Scene scene;

    EXPECT_TRUE(scene.empty());
}

TEST(SceneTest, AddsHittableObject) {
    Scene scene;

    auto sphere = std::make_unique<Sphere>(1.0);

    scene.add(std::move(sphere));

    EXPECT_FALSE(scene.empty());
}

TEST(SceneTest, IntersectsWithObject) {
    Scene scene;

    auto sphere = std::make_unique<Sphere>(1.0);
    scene.add(std::move(sphere));

    Ray ray(
        Vec3(0.0, 0.0, -5.0),
        Vec3(0.0, 0.0, 1.0)
    );

    EXPECT_TRUE(scene.intersects(ray));
}

TEST(SceneTest, IntersectsWithAnyObject) {
    Scene scene;

    auto firstSphere = std::make_unique<Sphere>(1.0);
    auto secondSphere = std::make_unique<Sphere>(2.0);

    scene.add(std::move(firstSphere));
    scene.add(std::move(secondSphere));

    Ray ray(
        Vec3(0.0, 0.0, -5.0),
        Vec3(0.0, 1.0, 0.0)
    );

    EXPECT_FALSE(scene.intersects(ray));
}

TEST(SceneTest, IntersectsWhenAnyObjectIsHit) {
    Scene scene;

    auto firstSphere = std::make_unique<Sphere>(1.0);
    auto secondSphere = std::make_unique<Sphere>(1.0);

    scene.add(std::move(firstSphere));
    scene.add(std::move(secondSphere));

    Ray ray(
        Vec3(0.0, 0.0, -5.0),
        Vec3(0.0, 0.0, 1.0)
    );

    EXPECT_TRUE(scene.intersects(ray));
}
