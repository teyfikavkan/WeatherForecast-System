#pragma once

#include "DayA.h"

struct Monday {};
struct Tuesday {};
struct Wednesday {};
struct Thursday {};
struct Friday {};
struct Saturday {};
struct Sunday {};




template<typename T>
class DayH {
	
};
template <>
class DayH<Monday> {
public:
	DayH(bool is,string hypothesis) : nameA("Monday"), _is(is), _hypothesis(hypothesis){}
	bool getIs() { return this->_is; }
	string  getName() { return this->nameA; }
	string getHypotesis() { return this->_hypothesis; }
private:
	bool _is;
	string nameA;
	string _hypothesis;
};

template <>
class DayH<Tuesday> {
public:
	DayH(bool is,string hypothesis) : nameA("Tuesday"), _is(is), _hypothesis(hypothesis) {}
	bool getIs() { return this->_is; }
	string getName() { return this->nameA; }
	string getHypotesis() { return this->_hypothesis; }
private:
	bool _is;
	string nameA;
	string _hypothesis;
};

template <>
class DayH<Wednesday> {
public:
	DayH(bool is, string hypothesis) : nameA("Wednesday"), _is(is), _hypothesis(hypothesis) {}
	bool getIs() { return this->_is; }
	string getName() { return this->nameA; }
	string getHypotesis() { return this->_hypothesis; }
private:
	bool _is;
	string nameA;
	string _hypothesis;
};
template <>
class DayH<Thursday> {
public:
	DayH(bool is, string hypothesis) : nameA("Thursday"), _is(is), _hypothesis(hypothesis) {}
	bool getIs() { return this->_is; }
	string getName() { return this->nameA; }
	string getHypotesis() { return this->_hypothesis; }
private:
	bool _is;
	string nameA;
	string _hypothesis;
};
template <>
class DayH<Friday> {
public:
	DayH(bool is, string hypothesis) : nameA("Friday"), _is(is), _hypothesis(hypothesis) {}
	bool getIs() { return this->_is; }
	string getName() { return this->nameA; }
	string getHypotesis() { return this->_hypothesis; }
private:
	bool _is;
	string nameA;
	string _hypothesis;
};
template <>
class DayH<Sunday> {
public:
	DayH(bool is, string hypothesis) : nameA("Sunday"), _is(is), _hypothesis(hypothesis) { }
	bool getIs() { return this->_is; }
	string getName() { return this->nameA; }
	string getHypotesis() { return this->_hypothesis; }
private:
	bool _is;
	string nameA;
	string _hypothesis;
};
template <>
class DayH<Saturday> {
public:
	DayH(bool is, string hypothesis) : nameA("Saturday"),_is(is), _hypothesis(hypothesis) {}
	bool getIs() { return this->_is; }
	string getName() { return this->nameA; }
	string getHypotesis() { return this->_hypothesis; }
private:
	bool _is;
	string nameA;
	string _hypothesis;
};

