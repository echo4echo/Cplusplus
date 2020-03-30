#include <iostream>
#include <string>

class Pizza
{
public:
	Pizza();

	virtual int getPrice() const = 0;
	virtual ~Pizza() {};

	//const string& dough to ensure that the input variable couldn't be changed

	void setDough(const string& dough);
	void setSauce(const string& sauce);
	void setTopping(const string& topping);
	void open() const;

private:
	string m_dough;
	string m_sauce;
	string m_topping;
};