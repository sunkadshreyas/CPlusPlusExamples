#include<iostream>

class Entity {
public:
    float X;
    float Y;

    void Move(float xa, float ya) {
        // Move the entity by (xa, ya) units
        X = X + xa;
        Y = Y + ya;
    }
};

class Player : public Entity {
public:
    const char* Name;

    void printName() {
        std::cout << "Name = " << Name << "\n";
    }
};

int main() {

    Player p1;
    p1.Name = "John";

    return 0;
}