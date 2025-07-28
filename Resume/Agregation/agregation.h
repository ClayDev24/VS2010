#include <iostream>
#include <vector>

class Engine {
public:
    void start() const { std::cout << "Engine started\n"; }
};

class Wheel {
public:
    void inflate(int psi) const { std::cout << "Wheel inflated to " << psi << " PSI\n"; }
};

class Window {
public:
    void rollup() const { std::cout << "Window rolled up\n"; }
    void rolldown() const { std::cout << "Window rolled down\n"; }
};

class Door {
public:
    Window* window;

    Door(Window* w) : window(w) {}

    void open() const  { std::cout << "Door opened\n"; }
    void close() const { std::cout << "Door closed\n"; }
};

class Car {
public:
    Engine* engine;
    std::vector<Wheel*> wheels;
    Door*   leftDoor;
    Door*   rightDoor;

    Car(Engine* e, std::vector<Wheel*> w, Door* l, Door* r)
        : engine(e), wheels(w), leftDoor(l), rightDoor(r) {}

    void useCar() {
        engine->start();
        wheels[0]->inflate(32);
        leftDoor->window->rollup();
    }
};

// **************<<_USAGE_>>****************
static void _agregationUsage() {
    // Criando as partes (componentes) FORA da classe Car: AGREGAÇÃO
    Engine engine;
    Wheel  w1, w2, w3, w4;
    Window winLeft, winRight;
    Door   doorLeft(&winLeft), doorRight(&winRight);

    std::vector<Wheel*> wheels;// = { &w1, &w2, &w3, &w4 };
	wheels.push_back(&w1);
	wheels.push_back(&w2);
	wheels.push_back(&w3);
	wheels.push_back(&w4);
    // Agregando as partes à classe Car
    Car car(&engine, wheels, &doorLeft, &doorRight);

    car.useCar();
}

/*
O que mudou?
	-Engine, Wheel, Window e Door são instanciados FORA da classe Car.
	-Car recebe ponteiros para esses objetos.
	-Car não é responsável por destruir esses objetos — isso é típico da agregação.
*/
