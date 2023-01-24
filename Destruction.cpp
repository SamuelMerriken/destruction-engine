#include <iostream>
#include <vector>

class Object {
private:
    double x, y; // position
    double mass; // mass
    double strength; // strength

public:
    Object(double x, double y, double mass, double strength) {
        this->x = x;
        this->y = y;
        this->mass = mass;
        this->strength = strength;
    }

    bool applyForce(double forceX, double forceY) {
        double force = std::sqrt(forceX*forceX + forceY*forceY);
        if (force > strength) {
            std::cout << "Object broke!" << std::endl;
            return false;
        }
        return true;
    }

    double getX() { return x; }
    double getY() { return y; }
};

int main() {
    std::vector<Object> objects;
    objects.push_back(Object(0, 0, 1, 10)); // create object at (0, 0) with mass 1 and strength 10
    objects.push_back(Object(1, 1, 2, 5)); // create object at (1, 1) with mass 2 and strength 5

    for (auto& obj : objects) {
        if (obj.applyForce(2, 2)) {
            std::cout << "Object at (" << obj.getX() << ", " << obj.getY() << ") withstood the force." << std::endl;
        }
    }

    return 0;
}
