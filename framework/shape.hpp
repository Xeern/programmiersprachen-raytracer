#ifndef SHAPE_BUW_HPP
#define SHAPE_BUW_HPP

#include <glm/vec3.hpp>
#include <cmath>
#include <math.h>
#include "catch.hpp"
#include "color.hpp"

class Shape
{
public:
    virtual float area() const = 0;
    virtual float volume()const = 0;
    virtual std::ostream& print(std::ostream& os) const;
    std::string name() const;
    Color color() const;
    /*virtual*/ ~Shape();

protected:
    Shape();
    Shape(Color const& rgb, std::string const& name);

private:
    Color color_;
    std::string name_;
};

std::ostream& operator<<(std::ostream& os, Shape const& s);

#endif
