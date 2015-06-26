#include "shape.hpp"

std::string Shape::name() const {
    return name_;
}
Color Shape::color() const {
    return color_;
}

Shape::Shape() :
    color_( Color{} ),
    name_( "no name" ) {}

Shape::Shape(Color const& rgb, std::string const& name) :
    color_( rgb ),
    name_( name ) {}

std::ostream& Shape::print(std::ostream& os) const {
    os << "Color:    " << color() << std::endl << "Name:     "
    << name() << std::endl;
    return os;
}

std::ostream& operator<<(std::ostream& os, Shape const& s){
    return s.print(os);
}
