#include<iostream>
#include<string>

class Printable {
public:
    // declaring the function as virtual and making it equal to 0
    // indicates this is a pure virtual function
    // Now all the children of this class should implement this function
    // in order to compile and continue working
    // Pure virtual functions ensure children class have implementation
    // This is similar to interfaces in other languages
    virtual std::string GetClassName() = 0;
};

class Entity : public Printable {
public:
    // over-ridden method must be declared virtual 
    // if not declared then this method is called even when
    // Child class object is used
    // Once function is declared as virtual, entry is created vTable
    // which connects this to the correct function in child class
    virtual std::string getName() {
        return "Entity";
    }

    std::string GetClassName() {
        return "Entity";
    }
};

class Player : public Entity {
private:
    std::string playerName;
public:
    // Constructor
    Player(const std::string& pName) : playerName(pName) {}
    
    // Over-ridden method which is not known to the compiler
    // unless the function in the parent class is declared virtual
    std::string getName() {
        return playerName;
    }

    std::string GetClassName() {
        return "Player";
    }
};

// Can accept both Entity and Player as Entity is a subclass of Player
void printName(Entity* entity) {
    std::cout << "Entity Name = " << entity->getName() << "\n";
}

void printClassName(Printable* printableObject) {
    std::cout << "Printable Class Name = " << printableObject->GetClassName() << "\n";
}

int main() {

    Entity *entity = new Entity();
    printName(entity);

    Player *player = new Player("John");
    printName(player);

    printClassName(entity);
    printClassName(player);

    delete entity;
    delete player;
    return 0;
}