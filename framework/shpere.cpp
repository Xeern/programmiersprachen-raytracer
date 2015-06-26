#include "sphere.hpp"

Sphere::Sphere() :
Sphere::Shape(),
    mid_{0.0, 0.0, 0.0},
    rad_{0.0} {}

Sphere::Sphere(glm::vec3 const& center, float r) :
Sphere::Shape(),
    mid_{ center },
    rad_{ r } {}

Sphere::Sphere(glm::vec3 const& center, float r, Color const& rgb,
    std::string const& name) :
Sphere::Shape(rgb, name),
    mid_{ center },
    rad_{ r } {}

glm::vec3 const& Sphere::center() const {
    return mid_;
    }

float Sphere::radius() const {
    return rad_;
    }

float Sphere::area() const {
    return 4 * M_PI * rad_ * rad_;
}

float Sphere::volume() const {
    return (4 * M_PI * rad_ * rad_ * rad_) / 3;
}

std::ostream& Sphere::print(std::ostream& os) const {
    std::cout << "Sphere stats:" << std::endl;
    Shape::print(os) << "Center:   (" << center().x << ", " <<
        center().y << ", " << center().z << ")" << std::endl;
    os << "Radius:   " << radius() << std::endl;
    os << "Area:     " << area() << std::endl;
    os << "Volume:   " << volume() << std::endl;
    return os;
}
