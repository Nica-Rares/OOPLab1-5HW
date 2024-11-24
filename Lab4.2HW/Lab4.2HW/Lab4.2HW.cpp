#include <iostream>
#include <string>
#include <vector>

class Address {
private:
    std::string street;
    std::string city;
    int zipCode;

public:
    Address(std::string str, std::string cty, int zip) : street(str), city(cty), zipCode(zip) {}

    void display() {
        std::cout << street << ", " << city << ", " << zipCode << std::endl;
    }
};

class Driver {
private:
    std::string name;
    int licenseNumber;

public:
    Driver(std::string nm, int licNum) : name(nm), licenseNumber(licNum) {}

    void display() {
        std::cout << "Driver: " << name << ", License No: " << licenseNumber << std::endl;
    }
};

class Engine {
protected:
    int horsepower;

public:
    Engine(int hp) : horsepower(hp) {}
};

class Bus : public Engine {
private:
    std::string busNumber;
    Driver driver;

public:
    Bus(std::string bNum, Driver drv, int hp) : Engine(hp), busNumber(bNum), driver(drv) {}

    void display() {
        std::cout << "Bus Number: " << busNumber << std::endl;
        driver.display();
        std::cout << "Horsepower: " << horsepower << std::endl;
    }
};

class BusStation {
private:
    std::string name;
    Address address;

public:
    BusStation(std::string nm, Address addr) : name(nm), address(addr) {}

    void display() {
        std::cout << "Bus Station: " << name << std::endl;
        address.display();
    }
};

class Commuter {
private:
    std::string name;
    int ticketNumber;

public:
    Commuter(std::string nm, int tNum) : name(nm), ticketNumber(tNum) {}

    void display() {
        std::cout << "Commuter: " << name << ", Ticket No: " << ticketNumber << std::endl;
    }
};

class Car : public Engine {
public:
    Car(int hp) : Engine(hp) {}

    void display() {
        std::cout << "Car with Horsepower: " << horsepower << std::endl;
    }
};

int main() {
    Address addr("123 Main St", "Metropolis", 12345);
    Driver driver("John Doe", 987654);
    Bus bus("B123", driver, 300);
    BusStation station("Central Station", addr);
    Commuter commuter("Jane Smith", 555);

    bus.display();
    station.display();
    commuter.display();

    return 0;
}
