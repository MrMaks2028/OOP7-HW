#include <iostream>
#include <conio.h>
using namespace std;

class Vehicle {
public:
	Vehicle() {}
	void move() {
		cout << "Press key on keyboard that vehicle will move\n";
		char n = _getch();
		cout << "\nVehicle was moving\n";
	}
	void setSpeed(int speed) {
		_speed = speed;
	}
	int getSpeed() {
		return _speed;
	}
	void setWheels(int wheels) {
		_wheels = wheels;
	}
	int getWheels() {
		return _wheels;
	}
	void setHumanCapacity(int humanCapacity) {
		_humanCapacity = humanCapacity;
	}
	int getHumanCapacity() {
		return _humanCapacity;
	}
private:
	int _speed = 0;
	int _wheels = 0;
	int _humanCapacity = 0;
};
class FuelTs : public Vehicle {
public:
	void move() {
		if (_fuel == 0)
			cout << "Fuel tank empty\n";
		else {
			cout << "Press key on keyboard that vehicle will move\n";
			char n = _getch();
			cout << "\nVehicle was moving\n";
		}
	}
	void setFuel(int fuel) {
		fuel = _fuel;
	}
	int getFuel() {
		return _fuel;
	}
	void setFuelCapacity(int fuelCapacity) {
		fuelCapacity = _fuelCapacity;
	}
	int getFuelCapacity() {
		return _fuelCapacity;
	}
	void reFuel(int n) {
		if (_fuel + n > _fuelCapacity)
			cout << "Error. You overflow fuel tank\n";
		if (_fuel == _fuelCapacity)
			cout << "Fuel tank full\n";
	}
private:
	int _fuel = 0;
	int _fuelCapacity = 0;
};
class DVS : public FuelTs {
public:
	void move() {
		if (getFuel() == 0)
			cout << "Fuel tank empty\n";
		else
			if (_oil == false)
				cout << "You need change oil\n";
			else {
				cout << "Press key on keyboard that vehicle will move\n";
				char n = _getch();
				cout << "\nVehicle was moving";
				oilWear();
			}
	}
	void oilWear() {
		static int oilCount = 5;
		oilCount--;
		if (oilCount == 0)
			_oil = false;
	}
	void changeOil() {
		if (_oil == true)
			cout << "Oil change early\n";
		_oil = true;
	}
private:
	bool _oil = true;
};
class Electric : public FuelTs {
public:

};
class MuscleTs : virtual public Vehicle {
public:

};
class Bysicle : public MuscleTs {
public:

};
class Skate : public MuscleTs {
public:

};
class ElectroBike : public FuelTs, public MuscleTs {
public:

};


int main() {
	setlocale(LC_ALL, "Russian");

	Vehicle a;
	FuelTs b;
	DVS c;
	c.setFuelCapacity(10);
	c.setFuel(5);
	cout << c.getFuel();
	/*for (int i = 0; i < 5; i++) {
		c.move();
	}
	cout << c.getFuel() << endl;
	c.move();
	*/



	return 0;
}