//Конструктор переноса

#include <iostream>
using namespace std;

class Car
{
private:
	string num;
	static string* nums;
	static int count;

	void addNum()
	{
		string* buf = new string[count + 1];
		for (int i = 0; i < count; i++)
		{
			buf[i] = nums[i];
		}
		buf[count] = this->num;
		delete[]nums;
		nums = buf;
		count++;
	}

	template <typename T>
	friend void info(T&);
public:
	Car(string num)
	{
		bool flag = true;
		for (int i = 0; i < count; i++)
		{
			if (num == nums[i])
			{
				cout << num << " num is busy" << endl;
				flag = false;
				break;
			}
		}
		if (flag)
		{
			this->num = num;
			addNum();
		}
		else this->num = "null";
	}
	string getNum()
	{
		return num;
	}
};

int Car::count = 0;
string* Car::nums = nullptr;


class Moto
{
private:
	string num;
	static string* nums;
	static int count;

	void addNum()
	{
		string* buf = new string[count + 1];
		for (int i = 0; i < count; i++)
		{
			buf[i] = nums[i];
		}
		buf[count] = this->num;
		delete[]nums;
		nums = buf;
		count++;
	}

	template <typename T>
	friend void info(T&);
public:
	Moto(string num)
	{
		bool flag = true;
		for (int i = 0; i < count; i++)
		{
			if (num == nums[i])
			{
				cout << num << " num is busy" << endl;
				flag = false;
				break;
			}
		}
		if (flag)
		{
			this->num = num;
			addNum();
		}
		else this->num = "null";
	}
	string getNum()
	{
		return num;
	}
};


int Moto::count = 0;
string* Moto::nums = nullptr;


template <typename T>
void info(T& object)
{
	cout << object.num << endl;
}


class Garage
{
private:
	string* nums = nullptr;  //т.к. у машин и мото всего одно поле и оно одинаковое
	int size = 0;
	int max_volume;
public:
	Garage(int max_volume)
	{
		this->max_volume = max_volume;
		delete[]nums;
		nums = new string[max_volume]{};
	}
	Garage(Garage&& garage)
	{
		nums = garage.nums;
		size = garage.size;
		max_volume = garage.max_volume;

		garage.nums = nullptr;
		garage.size = 0;
	}
	template <typename T>
	void add(T& cl, int i)
	{
		if (size == max_volume)
		{
			cout << cl.getNum() << " - Garage is busy" << endl;
		}
		else if (nums[i] == "")
		{
			nums[i] = cl.getNum();
			size++;
		}
		else
		{
			for (int j = i, n=1;; n++)
			{
				if (nums[j + n] == "" && n+j < max_volume)
				{
					cout << "go to place number " << j + n << endl;
					nums[j+n] = cl.getNum();
					break;
				}
				else if (nums[j - n] == "" && j-n >= 0)
				{
					cout << "go to place number " << j - n << endl;
					nums[j-n] = cl.getNum();
					break;
				}
			}
			size++;
		}
	}
	void show()
	{
		for (int i = 0; i < max_volume; i++)
		{
			cout << i << ". " << nums[i] << endl;
		}
	}
};


class Human
{
private:
	int age = 1;
	int* marks = nullptr;
	int size = 0;
public:
	Human()
	{

	}
	Human(const Human& other)
	{
		cout << "object copy" << endl;
		age = other.age;
		size = other.size;
		marks = new int[size];
		for (int i = 0; i < size; i++)
		{
			marks[i] = other.marks[i];
		}
	}
	Human(Human&& other) // <- конструктор переноса
	{
		cout << "object move" << endl;
		age = other.age;
		marks = other.marks;
		size = other.size;

		other.age = 1;
		other.size = 0;
		other.marks = nullptr;
	}
};

Human create()
{
	Human buf;
	return buf;
}

int main()
{
	//Car car1("A898TT");
	//Car car2("O567TA");
	//Car car3("O678AH");

	//Moto moto1("O546TO");
	//Moto moto2("K898KK");

	//Garage g1(10);
	//g1.add(car2, 7);
	//g1.show();
	//cout << endl;
	//g1.add(car3, 7);
	//g1.show();
	//cout << endl;
	//g1.add(moto2, 1);
	//g1.show();
	//cout << endl;
	//g1.add(moto1, 7);
	//g1.show();
	//cout << endl;
	//g1.add(moto2, 7);
	//g1.show();
	//cout << endl;
	//g1.add(moto1, 1);
	//g1.show();
	//cout << endl;
	//g1.add(moto1, 1);
	//g1.show();
	//cout << endl;
	//g1.add(moto1, 1);
	//g1.show();
	//cout << endl;
	//g1.add(moto1, 1);
	//g1.show();
	//cout << endl;
	//g1.add(moto1, 1);
	//g1.show();
	//cout << endl;
	//g1.add(moto2, 1);
	//g1.show();

	Human h1;
	Human h2 = h1;
	Human h3 = create();
}