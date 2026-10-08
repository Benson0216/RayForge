#pragma once

#include <memory>
#include <vector>

#include "Hittable.h"

class Scene {
public:
    bool empty() const {
        return objects_.empty();
    }

    void add(std::unique_ptr<Hittable> object) {
        objects_.push_back(std::move(object));
    }

    bool intersects(const Ray& ray) const {
        for (const auto& object : objects_) {
            if (object->intersects(ray)) {
                return true;
            }
        }

        return false;
    }

private:
    std::vector<std::unique_ptr<Hittable>> objects_;
};