#include "box.hpp"

Box::Box() :
Box::Shape(),
    min_{0.0, 0.0, 0.0},
    max_{0.0, 0.0, 0.0} {}

Box::Box(glm::vec3 const& minimum, glm::vec3 const& maximum) :
Box::Shape(),
    min_{ minimum },
    max_{ maximum } {}

Box::Box(glm::vec3 const& minimum, glm::vec3 const& maximum, Color const& rgb,
    std::string const& name) :
Box::Shape(rgb, name),
    min_{ minimum },
    max_{ maximum } {}

glm::vec3 const& Box::minimum() const{
    return min_;
}

glm::vec3 const& Box::maximum() const {
    return max_;
}

float Box::lenght() const{
    return max_.x - min_.x;
}

float Box::height() const{
    return max_.y - min_.y;
}

float Box::width() const{
    return max_.z - min_.z;
}

float Box::area() const {
    return 2 * (height() * lenght()) + 2 * (height() * width()) +
            2 * (lenght() * width());
}

float Box::volume() const {
    return lenght() * height() * width();
}

std::ostream& Box::print(std::ostream& os) const {
    std::cout << "Box stats:" << std::endl;
    Shape::print(os) << "Minimum:  (" << minimum().x << ", " <<
        minimum().y << ", " << minimum().z << ")" << std::endl;
    os << "Maximum:  (" << maximum().x << ", " <<
        maximum().y << ", " << maximum().z << ")" << std::endl;
    os << "Lenght:   " << lenght() << std::endl;
    os << "Height:   " << height() << std::endl;
    os << "Width:    " << width() << std::endl;
    os << "Area:     " << area() << std::endl;
    os << "Volume:   " << volume() << std::endl;
    return os;
}
