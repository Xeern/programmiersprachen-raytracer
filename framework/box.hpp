#ifndef BOX_BUW_HPP
#define BOX_BUW_HPP

#include "shape.hpp"

class Box : public Shape
{
public:
    Box();
    Box(glm::vec3 const& minimum, glm::vec3 const& maximum);
    Box(glm::vec3 const& minimum, glm::vec3 const& maximum, Color const& rgb,
        std::string const& name);
    //~Box();
    glm::vec3 const& minimum() const;
    glm::vec3 const& maximum() const;
    float lenght() const;
    float height() const;
    float width() const;
    float area() const override;
    float volume() const override;
    std::ostream& print(std::ostream& os) const override;

private:
    glm::vec3 min_;
    glm::vec3 max_;
};

#endif
