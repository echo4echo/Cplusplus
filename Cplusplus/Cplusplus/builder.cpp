#include <string>
#include <iostream>
#include <memory>
#include "stdafx.h"

#include "builder.h"
using namespace std;

//Prodcut

//class Pizza
//{
//public:
//	Pizza();
//
//	virtual int getPrice() const = 0;
//	virtual ~Pizza() {};
//
//	//const string& dough to ensure that the input variable couldn't be changed
//	void setDough(const string& dough)
//	{
//		m_dough = dough;
//	}
//	void setSauce(const string& sauce)
//	{
//		m_sauce = sauce;
//	}
//	void setTopping(const string& topping)
//	{
//		m_topping = topping;
//	}
//	void open() const
//	{
//		cout << "Pizza with" << m_dough << " dough, " << m_sauce << " saunce and "
//			<< m_topping << " topping. Mmm." << endl;
//	}
//
//private:
//	string m_dough;
//	string m_sauce;
//	string m_topping;
//};


void Pizza::setDough(const string& dough)
{
	m_dough = dough;
}
void Pizza::setSauce(const string& sauce)
{
	m_sauce = sauce;
}
void Pizza::setTopping(const string& topping)
{
	m_topping = topping;
}
void Pizza::open() const
{
	cout << "Pizza with" << m_dough << " dough, " << m_sauce << " saunce and "
		<< m_topping << " topping. Mmm." << endl;
}
Pizza::Pizza()
{
	m_dough = "No dough";
	m_sauce = "No sauce";
	m_topping = "No topping";
}

//Abstact Builder
class PizzaBuilder
{
public:
	PizzaBuilder();
	virtual ~PizzaBuilder() {};

	Pizza* getPizza()
	{
		return m_pizza.release();
	}
	void creatNewPizzaProcut()
	{
		m_pizza =  make_unique<Pizza>();
	}
	virtual void buildDough() = 0;
	virtual void buildSauce() = 0;
	virtual void buildTopping() = 0;

protected:
	unique_ptr<Pizza> m_pizza;
};

PizzaBuilder::PizzaBuilder()
{
}

//PizzaBuilder::~PizzaBuilder()
//{
//}

class HawaiianPizzaBuilder : public PizzaBuilder
{
public:
	virtual ~HawaiianPizzaBuilder(){};

	virtual void buildDough()
	{
		m_pizza->setDough("cross");
	}
	virtual void buildSauce()
	{
		m_pizza->setSauce("mild");
	}
	virtual void buildTopping()
	{
		m_pizza->setTopping("ham+pineapple");
	}
};

class SpicyPizzaBuilder : public PizzaBuilder
{
public:
	virtual ~SpicyPizzaBuilder(){};

	virtual void buildDough()
	{
		m_pizza->setDough("pan baked");
	}
	virtual void buildSauce()
	{
		m_pizza->setSauce("hot");
	}
	virtual void buildTopping()
	{
		m_pizza->setTopping("pepperoni+salami");
	}
};

class Cook
{
public:
	void openPizza()
	{
		m_pizzaBuilder->getPizza()->open();
	}
	void makePizza(PizzaBuilder* pb)
	{
		m_pizzaBuilder = pb;
		m_pizzaBuilder->creatNewPizzaProcut();
		m_pizzaBuilder->buildDough();
		m_pizzaBuilder->buildSauce();
		m_pizzaBuilder->buildTopping();
	}

private:
	PizzaBuilder* m_pizzaBuilder;
};





int _tmain(int argc, _TCHAR* argv[])
{
	Cook cook;
	HawaiianPizzaBuilder hawaiianPizzaBuilder;
	SpicyPizzaBuilder spicyPizzaBuilder;

	cook.makePizza(&hawaiianPizzaBuilder);
	cook.openPizza();

	cook.makePizza(&spicyPizzaBuilder);
	cook.openPizza();

	std::cin.get();
	return 0;
}