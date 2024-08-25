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

     // Demo of Enum
    enum Level : unsigned int {
        // You can do something like Beginner = 5, to start the values from 5
        // You can also explicity set the values
        Beginner, Intermediate, Expert
    };

    Level currLevel;

    Player() {
        currLevel = Beginner;
    }

    void setLevel(Level level) {
        currLevel = level;
    }

    Level getLevel() {
        return currLevel;
    }

    void printName() {
        std::cout << "Name = " << Name << "\n";
    }
};

int main() {

    Player p1;
    p1.Name = "John";

    std::cout << p1.getLevel() << "\n";
    p1.setLevel(Player::Expert);
    std::cout << p1.getLevel() << "\n";

    return 0;
}