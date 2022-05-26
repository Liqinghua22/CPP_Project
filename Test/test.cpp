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
	static int a;
public:
	
	string getName() const{
		return name;
	}
	int getAge() const {
		return age;
	}
	void setName(string name){
		(*this).name = name;
	}
	void setAge(int age){
		(*this).age = age;
	}
	Person(string _name = "", int _age = 0) {
		name = _name;
		age = _age;
	}
	~Person() {
		cout << "Îö¹¹Person£º[" << name << "," << age << "]" << endl;
	}
	friend ostream& operator<<(ostream& os, Person& a) {
		os << "Person£º[" << a.name << "," << a.age << "]" << endl;
		return os;
	}
	explicit operator int() {
		return age;
	}
};

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


int Person::a = 444;
int main() {
	
}

