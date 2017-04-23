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
	DayH(bool is, string hypothesis, string nameA, string eventA, bool situationA, double LS, double LN, bool priority) :
		nameH("Monday"), _is(is), _hypothesis(hypothesis), d(new DayA(nameA, eventA , situationA, LS, LN, priority)) {}
	bool getIs() { return this->_is; }
	string  getName() { return this->nameH; }
	string getHypotesis() { return this->_hypothesis; }
	DayA * getDayA() { return d; }
private:
	bool _is;
	string nameH;
	string _hypothesis;
	DayA * d;
};


template <>
class DayH<Tuesday> {
public:
	DayH(bool is, string hypothesis, string nameA, string eventA, bool situationA, double LS, double LN, bool priority) :
		nameH("Tuesday"), _is(is), _hypothesis(hypothesis), d(new DayA(nameA, eventA, situationA, LS, LN, priority)) {}
	bool getIs() { return this->_is; }
	string getName() { return this->nameH; }
	string getHypotesis() { return this->_hypothesis; }
	DayA * getDayA() { return d; }
private:
	bool _is;
	string nameH;
	string _hypothesis;
	DayA * d;
};

template <>
class DayH<Wednesday> {
public:
	DayH(bool is, string hypothesis, string nameA, string eventA, bool situationA, double LS, double LN, bool priority) :
		nameH("Wednesday"), _is(is), _hypothesis(hypothesis), d(new DayA(nameA, eventA, situationA, LS, LN, priority)) {}
	bool getIs() { return this->_is; }
	string getName() { return this->nameH; }
	string getHypotesis() { return this->_hypothesis; }
	DayA * getDayA() { return d; }
private:
	bool _is;
	string nameH;
	string _hypothesis;
	DayA * d;
};
template <>
class DayH<Thursday> {
public:
	DayH(bool is, string hypothesis, string nameA, string eventA, bool situationA, double LS, double LN, bool priority) :
		nameH("Thursday"), _is(is), _hypothesis(hypothesis), d(new DayA(nameA, eventA, situationA, LS, LN, priority)) {}
	bool getIs() { return this->_is; }
	string getName() { return this->nameH; }
	string getHypotesis() { return this->_hypothesis; }
	DayA * getDayA() { return d; }
private:
	bool _is;
	string nameH;
	string _hypothesis;
	DayA * d;
};
template <>
class DayH<Friday> {
public:
	DayH(bool is, string hypothesis, string nameA, string eventA, bool situationA, double LS, double LN, bool priority) :
		nameH("Friday"), _is(is), _hypothesis(hypothesis), d(new DayA(nameA, eventA, situationA, LS, LN, priority)) {}
	bool getIs() { return this->_is; }
	string getName() { return this->nameH; }
	string getHypotesis() { return this->_hypothesis; }
	DayA * getDayA() { return d; }
private:
	bool _is;
	string nameH;
	string _hypothesis;
	DayA * d;
};
template <>
class DayH<Sunday> {
public:
	DayH(bool is, string hypothesis, string nameA, string eventA, bool situationA, double LS, double LN, bool priority) :
		nameH("Sunday"), _is(is), _hypothesis(hypothesis), d(new DayA(nameA, eventA, situationA, LS, LN, priority)) {}
	bool getIs() { return this->_is; }
	string getName() { return this->nameH; }
	string getHypotesis() { return this->_hypothesis; }
	DayA * getDayA() { return d; }
private:
	bool _is;
	string nameH;
	string _hypothesis;
	DayA * d;
};
template <>
class DayH<Saturday> {
public:
	DayH(bool is, string hypothesis, string nameA, string eventA, bool situationA, double LS, double LN, bool priority) :
		nameH("Saturday"), _is(is), _hypothesis(hypothesis), d(new DayA(nameA, eventA, situationA, LS, LN, priority)) {}
	bool getIs() { return this->_is; }
	string getName() { return this->nameH; }
	string getHypotesis() { return this->_hypothesis; }
	DayA * getDayA() { return d; }
private:
	bool _is;
	string nameH;
	string _hypothesis;
	DayA * d;
};

