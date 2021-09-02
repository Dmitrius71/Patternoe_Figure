#include<iostream>
#include <string>

using namespace std;


// �������� ������ ������� ���������� ��� �������� 
// �������� ��������� �������������� �����
// ��������� ����� 

class Figure     // ��������� �������� ��������� ��������,
	             // ������� ������ ��������� ���
	             // ���������� ��������
{
public:

	virtual ~Figure() {}
	virtual std::string Operation() const = 0;

};

class Triangle : public Figure   
	//���������� �������� ������������� ��������� ���������� ���������� 
	// �����������
{
public:
	std::string Operation() const override 
	{
		return "{A triangle has been created}";
	}

};  

class Square : public Figure   
	//���������� �������� ������������� ��������� ���������� ���������� 
	// �������
{
public:
	std::string Operation() const override
	{
		return "{A Square has been created}";
	}

};

class �ircle: public Figure   
	//���������� �������� ������������� ��������� ���������� ���������� 
	// ����
{
public:
	
	std::string Operation() const override
	{
		return "{A �ircle has been created}";
	}
};

class Creator 
{

	// ����� ��������� ��������� ��������� �����,
	// ������� ������ ���������� ������� ������ �������!!
	
public:
	virtual ~Creator() {};
	virtual Figure* FactoryMethod() const = 0;


	//������ �� �������� ��������� �������
	//������ - ������, ������� �������� �� �������� ���������,
	//������������ ��������� �������.

	std::string SomeOperation() const
	{
		// �������� ��������� �����.
		Figure* figure = this->FactoryMethod();
		// �����, �������� � ���� ���������.
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

class ConcreteCreator�ircle : public Creator
{
public:
	Figure* FactoryMethod() const override
	{
		return new �ircle();
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