#include<iostream>
#include <string>

using namespace std;


// Создайте дизайн классов приложения для создания 
// объектов различных геометрических фигур
// Фабричный метод 

class Figure     // Интерфейс Продукта объявляет операции,
	             // которые должны выполнять все
	             // конкретные продукты
{
public:

	virtual ~Figure() {}
	virtual std::string Operation() const = 0;

};

class Triangle : public Figure   
	//Конкретные Продукты предоставляют различные реализации интерфейса 
	// треугольник
{
public:
	std::string Operation() const override 
	{
		return "{A triangle has been created}";
	}

};  

class Square : public Figure   
	//Конкретные Продукты предоставляют различные реализации интерфейса 
	// квадрат
{
public:
	std::string Operation() const override
	{
		return "{A Square has been created}";
	}

};

class Сircle: public Figure   
	//Конкретные Продукты предоставляют различные реализации интерфейса 
	// круг
{
public:
	
	std::string Operation() const override
	{
		return "{A Сircle has been created}";
	}
};

class Creator 
{

	// Класс Создатель объявляет фабричный метод,
	// который должен возвращать объекта класса Продукт!!
	
public:
	virtual ~Creator() {};
	virtual Figure* FactoryMethod() const = 0;


	//Обычно он содержит некоторую базовую
	//бизнес - логику, которая основана на объектах Продуктов,
	//возвращаемых фабричным методом.

	std::string SomeOperation() const
	{
		// Вызываем фабричный метод.
		Figure* figure = this->FactoryMethod();
		// Далее, работаем с этим продуктом.
		std::string result = "Creator Figure" + figure->Operation();
		delete figure;
		return result;
	}
	
};

class ConcreteCreatorTriangle : public Creator
{
	
public:
	Figure* FactoryMethod() const override
	{
		return new Triangle();
	}
};

class ConcreteCreatorSquare : public Creator
{
public:
	Figure* FactoryMethod() const override 
	{
		return new Square();
	}
};

class ConcreteCreatorСircle : public Creator
{
public:
	Figure* FactoryMethod() const override
	{
		return new Сircle();
	}
};

void ClientCode(Creator& creator)
{
	std::cout << creator.SomeOperation() << std::endl;
}

int main() 
{
	
	Creator* creator = new ConcreteCreatorTriangle();
	ClientCode(*creator);
	Creator* creator2 = new ConcreteCreatorSquare();
	ClientCode(*creator2);
	Creator* creator3 = new ConcreteCreatorTriangle();
	ClientCode(*creator3);

	delete creator;
	delete creator2;
	delete creator3;
	return 0;
}