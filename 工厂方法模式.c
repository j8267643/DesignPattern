//简单工厂模式在每次增加新的车型时，需要修改工厂类，这就违反了开放封闭原则：软件实体（类、模块、函数）可以扩展，但是不可修改。于是，工厂方法模式出现了。
//工厂方法模式：不再只由一个工厂类决定那一个产品类应当被实例化,这个决定权被交给子类去做。当有新的产品（新型汽车）产生时， \
只要按照抽象产品角色、抽象工厂角色提供的方法来生成即可（新车型可以用一个新类继承创建产品即可），那么就可以被客户使用，而不必去修改任何已有的代 码。可以看出工厂角色的结构也是符合开闭原则。
#include <iostream>
using namespace std;

class Car//车类
{
public:
	virtual void createdCar(void) = 0;
};

class BenzCar : public Car //奔驰车
{
public:
	BenzCar()
	{
		cout << "Benz::Benz()" << endl;
	}
	virtual void createdCar(void)
	{
		cout << "BenzCar::createdCar()" << endl;
	}
	~BenzCar()
	{

	}
};

class BmwCar : public Car //宝马车
{
public:
	BmwCar()
	{
		cout << "Bmw::Bmw()" << endl;
	}
	virtual void createdCar(void)
	{
		cout << "BmwCar::createdCar()" << endl;
	}
};


class Factory//车厂
{
public:
	virtual Car* createSpecificCar(void) = 0;
};

class BenzFactory : public Factory//奔驰车厂
{
public:
	virtual Car* createSpecificCar(void)
	{
		return (new BenzCar());
	}
};

class BmwFactory : public Factory//宝马车厂
{
public:
	virtual Car* createSpecificCar(void)
	{
		return (new BmwCar());
	}
};


int main(int argc, char** argv)
{
	Factory* factory = new BenzFactory();
	Car* specificCarA = factory->createSpecificCar();
	factory = new BmwFactory();
	Car* specificCarB = factory->createSpecificCar();

	delete factory; delete specificCarA; delete specificCarB;

	system("pause");
	return 0;
}
