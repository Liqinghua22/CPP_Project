#include <iostream>
#include <string>
#include <exception>
#include <memory>
#include <vector>
#include <iterator>
#include <algorithm>
#include <list>
#include <queue>
#include <map>
#include <array>
#include <fstream>
#include <stdio.h>
#include <thread>
#include <valarray>
#include <functional>
#include <tuple>
#include <utility>
#include <complex>
#include <stack>
#include <forward_list>
#include <numeric>
#include <regex>
#include <thread>
#include <future>
#include <random>
#include <chrono>
#include "tools.h"
#include <limits>
#include <ctime>
using namespace std;

class Person {
private:
	string name;
	int age;
	char* city;
	static int num;
public:
	static void setNum(int c) {
		num = c;
	}
	string getName() const {
		return name;
	}
	int getAge() const {
		return age;
	}
	void setName(string name) {
		(*this).name = name;
	}
	void setAge(int age) {
		(*this).age = age;
	}
	Person(string _name , int _age,const char* _city) {
		name = _name;
		age = _age;
		int len = strlen(_city);
		city = new char[len + 1];
		strcpy_s(city, len + 1, _city);
		num++;
	}
	~Person() {
		cout << "析构Person：[" << "name:" << name << "," << "age:" << age << "]" << endl;
		num--;
	}
	friend ostream& operator<<(ostream& os, Person& a) {
		os << "Person：[" << "name:" << a.name << "," << "age:" << a.age << "]" << endl;
		return os;
	}
	explicit operator int() {
		return age;
	}
	static int getNum() {
		return num;
	}
	bool operator==(const Person& a) {
		if(this->name == a.name&&this->age == a.age&&this->city==a.city){
			return true;
		}
		else {
			return false;
		}
	}
	Person& operator=(const Person& a) {
		
		if (*this == a) {
			return *this;
		}
		delete[] city;
		int len = strlen(a.city);
		city = new char[len + 1];
		strcpy_s(city, len+1,a.city);
		age = a.age;
		name = a.name;

	}
	Person(const Person& a) {
		age = a.age;
		name = a.name;
		
		int len = strlen(a.city);
		city = new char[len + 1];
		strcpy_s(city, len+1, a.city);
		num++;
	}
	char* getCity() {
		return city;
	}
};

//int Person::num = 0;

struct People {
private:

	string name;
	int age;
public:
	string getName() {
		return name;
	}
	int getAge() {
		return age;
	}
	friend  ostream& operator<<(ostream& os, People& a) {
		os << "People: [" << a.name << "," << a.age << "]" << endl;
		return os;
	}
	People operator+(People& a) {
		People c{};
		c.name = this->name;
		c.age = this->age + a.age;
		return c;
	}
	People(string name = "lihua", int age = 22) {
		this->name = name;
		this->age = age;
	}
	
};

class Student :public Person {
private:
	string school;
	
public:
	Student(string _name,int age,const char* _city,string _school) :Person(_name,age,_city) {
		school = _school;
	}
	~Student() {
		cout << "析构Student：[name:" << getName() << "," << "age:" << getAge() << "," << "school:" << school << "]" << endl;
	}
	Student() :Person("李华", 22, "赣州"), school("于都二中") {

	}
};


int main() {
	int* a = new int;
	*a = 44;
	unique_ptr<int> p(a);
	/*shared_ptr<int> p2(a);
	cout << *p2 << endl;*/
	cout << *p << endl;
}

