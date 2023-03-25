#pragma once
#include <iostream>
#include <string>
#include <random>
#include "Sequence.h"
using namespace std;
class Person {
public:
	int Age{};
	string Name;
	Person() {}
	Person(int age, string name) {
		Age = age;
		Name = name;
	}

	friend bool operator ==(const Person& person1, const Person& person2) {
		return (person1.Age == person2.Age) && (person1.Name == person2.Name);
	}

	friend bool operator >=(const Person& person1, const Person& person2) {
		return person1.Age >= person2.Age;
	}

	friend bool operator !=(const Person& person1, const Person& person2) {
		return (person1.Age != person2.Age) && (person1.Name != person2.Name);
	}

	friend bool operator <=(const Person& person1, const Person& person2) {
		return person1.Age <= person2.Age;
	}

	friend bool operator >(const Person& person1, const Person& person2) {
		return person1.Age > person2.Age;
	}

	friend bool operator <(const Person& person1, const Person& person2) {
		return person1.Age < person2.Age;
	}
};
Sequence<Person> create_people(int s, int distr_number) {
	srand(time(0));
	int p = rand();
	std::random_device rd;
	std::mt19937 gen(rd());
	std::poisson_distribution<> poisson(p);
	std::uniform_int_distribution<> uniform(0, p);
	int age = 0;
	string name = "";
	Person person;
	Sequence<Person> vector = Sequence<Person>();
	for (int i = 0; i < s; ++i) {
		switch (distr_number)
		{
		case 1:
			age = poisson(gen);
			break;
		case 2:
			age = uniform(gen);
			break;
		default:
			break;
		}
		person = Person(age, "Person" + to_string(i));
		vector = vector.add(person);
	}
	return vector;
}