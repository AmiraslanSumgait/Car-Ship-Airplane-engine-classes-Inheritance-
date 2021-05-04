#include<iostream>
using namespace std;
#define MAX 10
template<typename T>
class Stack {
private:
	T items[MAX];
	int top;
public:
	Stack() { top = -1; }
	bool push(T item) {
		if (top >= (MAX - 1)) {
			cout << "Stack overflow!";
			return false;
		}
		else {
			++top;
			items[top] = item;
			return true;
		}
	}
	T peek() {
		if (top < 0) {
			cout << "Stack is Empty!" << endl;
			
		}
		else {
			return items[top];
		}
	}

	T pop() {
		if (top < 0) {
			cout << "Stack is underflow!" << endl;
			
		}
		else {
			return items[top--];
		}
	}

	bool isEmpty() const { return top < 0; }
	bool isFull() const { return top == (MAX - 1); }
};
class Engine {
private:
	int _engine_no;
	string _company;
	double _volume;
public:
	Engine() :_engine_no(), _company(), _volume()
	{

	}
	int GetEngineNo() {
		return _engine_no;
	}
	string GetCompany() {
		return _company;
	}
	double GetVolume() {
		return _volume;
	}
	void SetEngineNo(int engineno) {
		_engine_no = engineno;
	}
	void SetCompany(string company) {
		_company = company;
	}
	void SetVolume(double volume) {
		_volume = volume;
	}
	Engine(int enginno, string company, double volume)
	{
		this->_engine_no = enginno;
		this->_company = company;
		this->_volume = volume;
	}
	void show() {
		cout << "Engine No: " << _engine_no << endl;
		cout << "Company: " << _company << endl;
		cout << "Volume: " << _volume << endl;
	}

};
class Vehicle {
protected:
	int id;
	string model;
	string vendor;
	Engine engine;
	
public:
	Vehicle() :id(), model(),vendor()
	{

	}
	Vehicle(const int& id,const string& model,const string&vendor):id(id),model(model),vendor(vendor)
	{
		                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             
	}
	void show() {
		cout << "Id: " << id << endl;
		cout << "Model: " << model << endl;
		cout << "Vendor: " << vendor << endl;
	
	}
};

class Car:public Vehicle {
private:
	bool _hasSpoiler;
public:
	
	Car():_hasSpoiler()
	{

	}
	Car(const int& id, const string& model, const string& vendor,int engineno,string company,double volume, bool hasSpoiler):Vehicle(id,model,vendor)
	{
		Vehicle:: engine.SetEngineNo(engineno);
		Vehicle::engine.SetCompany(company);
		Vehicle::engine.SetVolume(volume);
		this->_hasSpoiler = hasSpoiler;
		
	}
	void show() {
		Vehicle::show();
		Vehicle::engine.show();
		if (_hasSpoiler == 0) cout << "Spoiler:No" << endl;
		else cout << "Spoiler:Yes" << endl;
		
	}

};
class Airplane :public Vehicle {
private:
	int _engineCount;
	int _passengerCapacity;
public:
	Airplane():_engineCount(),_passengerCapacity()
	{

	}
	Airplane(const int& id, const string& model, const string& vendor, int engineno, string company, double volume,int enginecount,int passangercapacity ):Vehicle(id,model,vendor)
	{
		
		Vehicle::engine.SetEngineNo(engineno);
		Vehicle::engine.SetCompany(company);
		Vehicle::engine.SetVolume(volume);
		_engineCount = enginecount;
		_passengerCapacity = passangercapacity;

	}
	void show() {
		Vehicle::show();
		Vehicle::engine.show();
		cout << "Engine count: " << _engineCount << endl;
		cout << "Passenger Capacity: " << _passengerCapacity << endl;
	}

};
class Ship:public Vehicle{
private:
	bool _hasSail;
public:
	Ship():_hasSail()
	{

	}
	Ship(const int& id, const string& model, const string& vendor, int engineno, string company, double volume, bool hasSail):Vehicle(id,model,vendor)
	{
		Vehicle::engine.SetEngineNo(engineno);
		Vehicle::engine.SetCompany(company);
		Vehicle::engine.SetVolume(volume);
		this->_hasSail = hasSail;
	}
	void show() {
		Vehicle::show();
		Vehicle::engine.show();
		if (_hasSail == 0) cout << "Sail:No" << endl;
		else cout << "Sail:Yes" << endl;

	}
};

class VehicleDepo {
public:
	Stack<Car> cars;
	Stack<Ship> ships;
	Stack<Airplane> airplanes;
	void showAllVehicles() {
		while (!cars.isEmpty()) {
			cars.pop().show();
		}
		while (!ships.isEmpty()) {
			ships.pop().show();
		}
		while (!airplanes.isEmpty()) {
			airplanes.pop().show();
		}
	}
};

void main() {
	
	Car c1(1, "Bmw X5 ", "Classfileds",32,"Bayerische Motoren Werke",3.5 , false);
	//c1.show();
	Car c2(2, "Mercedes ", "Classfileds", 103, "Bayerische Motoren Werke", 3.9, true);
	//c2.show();
	Ship s1(3,"Bismarck","Marine Traffic",45,"Cummins",5.6,true);
	Ship s2(4,"Aframax","Gib yachts",64,"Caterpillar",6.6,false);
	//s1.show();
	Airplane a1(5, "Consolidated B-24 Liberator", "Airplane Suppliers", 72, "United Airlines", 8.9, 4, 200);
	Airplane a2(6, "Boeing C-17A Globemaster", "Airplane Suppliers", 223, "Safran", 8.3, 2, 300);

	//a1.show();
	VehicleDepo v1;
	v1.cars.push(c1);
	v1.cars.push(c2);
	v1.airplanes.push(a1);
	v1.airplanes.push(a2);
	v1.ships.push(s1);
	v1.ships.push(s2);
	v1.showAllVehicles();
	//finish
	
	
}
