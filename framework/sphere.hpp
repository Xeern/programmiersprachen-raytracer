#ifndef SPHERE_BUW_HPP
#define SPHERE_BUW_HPP
#define _USE_MATH_DEFINES
#include "shape.hpp"

class Sphere : public Shape
{
public:
    Sphere();
    Sphere(glm::vec3 const& center, float r);
    Sphere(glm::vec3 const& center, float r, Color const& rgb,
        std::string const& name);
    //~Sphere();
    glm::vec3 const& center() const;
    float radius() const;
    float area() const override;
    float volume() const override;
    std::ostream& print(std::ostream& os) const override;

private:
    glm::vec3 mid_;
    float rad_;
};

#endif
