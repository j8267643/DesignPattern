//简单工厂模式，工厂类是创建产品的，它决定创建哪一种产品，就像领导决定采用那种技术方案样。
//优点： 1、一个调用者想创建一个对象，只要知道其名称就可以了。 2、扩展性高，如果想增加一个产品，只要扩展一个工厂类就可以。 3、屏蔽产品的具体实现，调用者只关心产品的接口。
//缺点：每次增加一个产品时，都需要增加一个具体类和对象实现工厂，使得系统中类的个数成倍增加，在一定程度上增加了系统的复杂度，同时也增加了系统具体类的依赖。这并不是什么好事。
#include <iostream>
using namespace std;

enum CarType { BENZ, BMW };

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

class CarFactory //车厂
{
public:
	Car* createSpecificCar(CarType type)
	{
		switch (type)
		{
		case BENZ://生产奔驰车
			return (new BenzCar());
			break;
		case BMW://生辰宝马车
			return (new BmwCar());
			break;
		default:
			return NULL;
			break;
		}
	}
};

int main(int argc, char** argv)
{
	CarFactory carfac;
	Car* specificCarA = carfac.createSpecificCar(BENZ);//看到网上众多示例在new后没有delete，感觉不是特别严谨
	Car* specificCarB = carfac.createSpecificCar(BMW);

	delete specificCarA; delete specificCarB;
	
	system("pause");
	return 0;
}
