#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "shape.hpp"
#include "sphere.hpp"
#include "box.hpp"

TEST_CASE("Sphere","[testing_sphere]")
{
    std::cout << "  First test" << std::endl;
    Sphere sp1;
    glm::vec3 ur{};
    Color white{0.0, 0.0, 0.0};
    REQUIRE(sp1.radius() == (0.0));
    REQUIRE(sp1.center() == ur);
	REQUIRE(sp1.color() == white);
    REQUIRE(sp1.name() == "no name" );

    glm::vec3 c{3.0, 3.0, 3.0};
    Sphere sp2{c, 2.5};
    REQUIRE(sp2.center() == c );
    REQUIRE(sp2.center() == glm::vec3(3.0, 3.0, 3.0));
    REQUIRE(sp2.radius() == (2.5));
    REQUIRE(sp2.area() == Approx(78.5398));
    REQUIRE(sp2.volume() == Approx(65.4498));
    REQUIRE(sp2.color() == white);
    REQUIRE(sp2.name() == "no name");

    glm::vec3 d{5.0, 5.0, 5.0};
    Color pink{128, 76, 51};
    Sphere sp3{d, 3.0, pink, "Sphere 3"};
    REQUIRE(sp3.center() == glm::vec3(5.0, 5.0, 5.0));
    REQUIRE(sp3.radius() == (3.0));
    REQUIRE(sp3.area() == Approx(113.097));
    REQUIRE(sp3.volume() == Approx(113.097));
    REQUIRE(sp3.color() == pink);
    REQUIRE(sp3.name() == "Sphere 3");
}

TEST_CASE("Box","[testing_Box]")
{
    std::cout << "------------------------------------------------------"
    << std::endl;
    std::cout << "  Second test" << std::endl;
    Box bx1;
    Color white{0.0, 0.0, 0.0};
    REQUIRE(bx1.minimum() == glm::vec3(0.0, 0.0, 0.0));
    REQUIRE(bx1.maximum() == glm::vec3(0.0, 0.0, 0.0));
    REQUIRE(bx1.color() == white);
    REQUIRE(bx1.name() == "no name");

    glm::vec3 a{1.0, 1.0, 1.0};
    glm::vec3 o{3.0, 3.0, 3.0};
    Box bx2{a, o};
    REQUIRE(bx2.minimum() == glm::vec3(1.0, 1.0, 1.0));
    REQUIRE(bx2.maximum() == glm::vec3(3.0, 3.0, 3.0));
    REQUIRE(bx2.lenght() == bx2.width());
    REQUIRE(bx2.height() == bx2.width());
    REQUIRE(bx2.width() == (2.0));
    REQUIRE(bx2.area() == Approx(24));
    REQUIRE(bx2.volume() == Approx(8));
    REQUIRE(bx2.color() == white);
    REQUIRE(bx2.name() == "no name");

    glm::vec3 mi{1.0, 0.5, 2.0};
    glm::vec3 ma{4.0, 4.0, 3.5};
    Color green{127, 204, 0.0};
    Box bx3{mi, ma, green, "balala"};
    REQUIRE(bx3.minimum() == mi);
    REQUIRE(bx3.maximum() == ma);
    REQUIRE(bx3.lenght() == (3.0));
    REQUIRE(bx3.height() == (3.5));
    REQUIRE(bx3.width() == (1.5));
    REQUIRE(bx3.area() == Approx(40.5));
    REQUIRE(bx3.volume() == Approx(15.75));
    REQUIRE(bx3.color() == green);
    REQUIRE(bx3.name() == "balala");
}

TEST_CASE("print", "[testing_print]")
{
    std::cout << "------------------------------------------------------"
    << std::endl;
    using namespace std;
    cout << "  Third test" << endl;

    Color red{255, 0, 0};
    Sphere sp1{glm::vec3{2.5, 3.5, 1.5}, 5.5, red, "That Sphere"};
    cout << endl;
    cout << sp1 << endl;

    Color blue{0, 255, 0};
    glm::vec3 min{-1.0, 1.0, 0.0};
    glm::vec3 max{3.0, 6.0, 11.0};
    Box bx1{min, max, blue, "That Box"};
    cout << endl;
    cout << bx1 << endl;
}

TEST_CASE("intersectRaySphere", "[intersect]")
{
    std::cout << "------------------------------------------------------"
    << std::endl;
    std::cout << "  Fourth test" << std::endl;
    //Ray
    glm::vec3 ray_origin(0.0, 0.0, 0.0);
    // ray direction has to be normalized
    // you can use:     v = glm::normalize(some_vector)
    glm::vec3 ray_direction(0.0, 0.0, 1.0);

    //Sphere
    glm::vec3 sphere_center(0.0, 0.0, 5.0);
    float sphere_radius(1.0);

    float distance(0.0);
    auto result = glm::intersectRaySphere(ray_origin, ray_direction,
        sphere_center, sphere_radius, distance);
    REQUIRE(distance == Approx(4.0f));
}

TEST_CASE("intersect", "[intersect]")
{
    std::cout << "------------------------------------------------------"
    << std::endl;
    std::cout << "  Fifth test" << std::endl;
    glm::vec3 orig{0.0, 0.0, 0.0};
    glm::vec3 dir{0.0, 0.0, 1.0};
    Ray line(orig, dir);
    Sphere sp1{glm::vec3{0.0, 0.0, 6.0}, 1.0};
    float distance(0.0);
    sp1.intersect(line, distance);
    REQUIRE(distance == Approx(5.0f));
}

TEST_CASE("virtual_construtor_destructor", "[virtual]")
{
    std::cout << "------------------------------------------------------"
    << std::endl;
    std::cout << "  Sixth test" << std::endl;

    Color red(255, 0, 0);
    glm::vec3 position(0,0,0);
    Sphere* s1 = new Sphere(position, 1.2, red, "sphere0");
    Shape* s2 = new Sphere(position, 1.2, red, "sphere1");
    std::cout << std::endl;
    s1->print(std::cout);
    std::cout << std::endl;
    s2->print(std::cout);
    std::cout << std::endl;
    delete s1;
    delete s2;
}

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
