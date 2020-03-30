#include <stdexcept>
#include <iostream>
#include <memory>
#include "builder.h"

using namespace std;

class HamAndMushroomPizza : public Pizza
{
public:
	virtual int getPrice() const {return 850;};
	virtual ~HamAndMushroomPizza(){};
};

class DeluxePizza : public Pizza
{
public:
	virtual int getPrice() const {return 1050;};
	virtual ~DeluxePizza(){};
};

class HawaiianPizza : public Pizza {
public:
	virtual int getPrice() const { return 1150; };
	virtual ~HawaiianPizza() {};
};

class PizzaFactory{
public:
	enum PizzaType {
		HamMushroom,
		Deluxe,
		Hawaiian,
	};

	static unique_ptr<Pizza>createPizza(PizzaType pizzaTyp)
	{
		switch (pizzaTyp)
		{
		case PizzaFactory::HamMushroom: return make_unique<HamAndMushroomPizza>();
			break;
		case PizzaFactory::Deluxe: return make_unique<DeluxePizza>();
			break;
		case PizzaFactory::Hawaiian: return make_unique<HawaiianPizza>();
			break;
		}
		throw "invalid pizza type.";
	}
};

void pizza_information(PizzaFactory::PizzaType pizzaTyp)
{
	unique_ptr<Pizza> pizza = PizzaFactory::createPizza(pizzaTyp);
	cout << "Price of " << pizzaTyp << " is " << pizza->getPrice() << std::endl;
}