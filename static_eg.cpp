#include <iostream>

class StaticDemoClass {
public:
    int x, y;
    static int s_x, s_y;

    void printFunction() {
        std::cout << x << " " << y << "\n";
        
        std::cout << s_x << "\n";
    }

    static void demoStaticFunction() {
        // cannot access non static class variables inside state member functions
        // std::cout << x << " " << y << "\n";

        std::cout << s_x << " " << s_y << "\n";
    }
};

/*
    This is same as static function. Here you cannot access class variables.
*/
void demoStaticFunction(StaticDemoClass s) {
    std::cout << s.s_x << " " << s.s_y << "\n";
}

/*
    Program will not compile without this.
    They need to be defined in the below manner
*/
int StaticDemoClass::s_x;
int StaticDemoClass::s_y;

int main() {
    StaticDemoClass d1;
    d1.x = 10;
    d1.y = 20;

    StaticDemoClass d2;
    d2.s_x = 60; // change the value of static varible to 60 for instance d2
    
    // The correct way to access static variables and member functions are
    // StaticDemoClass::s_x = 20;
    // StaticDemoClass::demoStaticFunction();

    // s_x expected value would be 30, but the actual is 60
    // because static variables are shared across all instances of class
    d1.demoStaticFunction(); 
    d2.demoStaticFunction();
    return 0;
}