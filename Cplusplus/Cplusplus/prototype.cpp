/** Implementation of Prototype Method **/
#include <iostream>
#include <unordered_map>
#include <string>
#include <memory>

#include "prototype.h"

using namespace std;

Record::Record()
{
}

class CarRecord: public Record
{
public:
	CarRecord(string carName, int ID) : m_carName(carName), m_ID(ID)
	{}

	void print() override
	{
		cout << "Car Name: " << m_carName << endl;
		cout << "Number: " << m_ID << endl;
	}

	unique_ptr<Record> clone() override {
		return make_unique<CarRecord>(*this);
	}

private:
	string m_carName;
	int m_ID;
};

/** BikeRecord is the Concrete Prototype */
class BikeRecord : public Record
{
private:
	string m_bikeName;
	int m_ID;

public:
	BikeRecord(string bikeName, int ID) : m_bikeName(bikeName), m_ID(ID)
	{
	}

	void print() override
	{
		cout << "Bike Record" << endl
		     << "Name  : " << m_bikeName << endl
		     << "Number: " << m_ID << endl << endl;
	}

	unique_ptr<Record> clone() override
	{
		return make_unique<BikeRecord>(*this);
	}
};

/** PersonRecord is the Concrete Prototype */
class PersonRecord : public Record
{
private:
	string m_personName;
	int m_age;

public:
	PersonRecord(string personName, int age) : m_personName(personName), m_age(age)
	{
	}

	void print() override
	{
		cout << "Person Record" << endl
			<< "Name : " << m_personName << endl
			<< "Age  : " << m_age << endl << endl;
	}

	unique_ptr<Record> clone() override
	{
		return make_unique<PersonRecord>(*this);
	}
};

RecordFactory::RecordFactory()
{
	m_records[CAR]    = make_unique<CarRecord>("Ferrari", 5050);
	m_records[BIKE]   = make_unique<BikeRecord>("Yamaha", 2525);
	m_records[PERSON] = make_unique<PersonRecord>("Tom", 25);
}