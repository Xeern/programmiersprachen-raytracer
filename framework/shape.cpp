#include "shape.hpp"

std::string Shape::name() const {
    return name_;
}
Color Shape::color() const {
    return color_;
}
Shape::Shape() :
    color_( Color{} ),
    name_( "no name" ) {
        std::cout << "Shape() class" << std::endl;
    }

Shape::Shape(Color const& rgb, std::string const& name) :
    color_( rgb ),
    name_( name ) {
        std::cout << "Shape( stuff ) class" << std::endl;
    }

Shape::~Shape() {
    std::cout << "~Shape() class" << std::endl;
}

std::ostream& Shape::print(std::ostream& os) const {
    os << "Color:    " << color() << std::endl << "Name:     "
    << name() << std::endl;
    return os;
}

std::ostream& operator<<(std::ostream& os, Shape const& s){
    return s.print(os);
}
