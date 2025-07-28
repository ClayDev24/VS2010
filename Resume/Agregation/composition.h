#include <iostream>
#include <array>

/*
composição=> Os objetos internos são criados e destruídos pela própria classe Car.
Isso demonstra que a vida útil dos componentes está atrelada ao objeto Car.
*/
class Engine2 {
public:
    void start() const { std::cout << "Engine started\n"; }
};

class Wheel2 {
public:
    void inflate(int psi) const { std::cout << "Wheel inflated to " << psi << " PSI\n"; }
};

class Window2 {
public:
    void rollup()   const { std::cout << "Window rolled up\n";   }
    void rolldown() const { std::cout << "Window rolled down\n"; }
};

class Door2 {
private:
    Window2 window; // Composição: Window pertence ao Door

public:
    void open() const  { std::cout << "Door opened\n"; }
    void close() const { std::cout << "Door closed\n"; }
    void rollUpWindow()   const { window.rollup();   }
    void rollDownWindow() const { window.rolldown(); }
};

class Car2 {
private:
    Engine2   engine;               // Composição: engine é parte do Car
    std::array<Wheel2, 4> wheels;   // Composição: 4 rodas internas
    Door2     leftDoor, rightDoor;  // Duas portas internas

public:
    void useCar() {
        engine.start();
        wheels[0].inflate(32);
        leftDoor.rollUpWindow();
    }
};

// **************<<_USAGE_>>****************
static void _compositionUsage() {
    Car2 car;
    car.useCar();
}

/*
Características de Composiçã:
	-Os componentes (Engine, Wheel, Door, Window) são membros DIRETOS (inside) da classe Car.
	-A vida útil deles é gerenciada AUTOMATICAMENTE pelo objeto Car.
	-Se o Car for destruído, tudo que ele contém TAMBÉM SERÁ.
*/
