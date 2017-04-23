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
	DayH(bool is, string hypothesis, DayA * dA) :
		nameH("monday"), _is(is), _hypothesis(hypothesis), _dA(dA) {}
	
	bool getIs() { return this->_is; }
	string  getName() { return this->nameH; }
	string getHypotesis() { return this->_hypothesis; }
	DayA * getDayA() { return _dA; }
private:
	bool _is;
	string nameH;
	string _hypothesis;
	DayA * _dA;
};


template <>
class DayH<Tuesday> {
public:
	DayH(bool is, string hypothesis, DayA * dA) :
		nameH("tuesday"), _is(is), _hypothesis(hypothesis), _dA(dA) {}
	bool getIs() { return this->_is; }
	string getName() { return this->nameH; }
	string getHypotesis() { return this->_hypothesis; }
	DayA * getDayA() { return _dA; }
private:
	bool _is;
	string nameH;
	string _hypothesis;
	DayA * _dA;
};

template <>
class DayH<Wednesday> {
public:
	DayH(bool is, string hypothesis, DayA * dA) :
		nameH("wednesday"), _is(is), _hypothesis(hypothesis), _dA(dA) {}
	bool getIs() { return this->_is; }
	string getName() { return this->nameH; }
	string getHypotesis() { return this->_hypothesis; }
	DayA * getDayA() { return _dA; }
private:
	bool _is;
	string nameH;
	string _hypothesis;
	DayA * _dA;
};
template <>
class DayH<Thursday> {
public:
	DayH(bool is, string hypothesis, DayA * dA) :
		nameH("thursday"), _is(is), _hypothesis(hypothesis), _dA(dA) {}
	bool getIs() { return this->_is; }
	string getName() { return this->nameH; }
	string getHypotesis() { return this->_hypothesis; }
	DayA * getDayA() { return _dA; }
private:
	bool _is;
	string nameH;
	string _hypothesis;
	DayA * _dA;
};
template <>
class DayH<Friday> {
public:
	DayH(bool is, string hypothesis, DayA * dA) :
		nameH("friday"), _is(is), _hypothesis(hypothesis), _dA(dA) {}
	bool getIs() { return this->_is; }
	string getName() { return this->nameH; }
	string getHypotesis() { return this->_hypothesis; }
	DayA * getDayA() { return _dA; }
private:
	bool _is;
	string nameH;
	string _hypothesis;
	DayA * _dA;
};

template <>
class DayH<Saturday> {
public:
	DayH(bool is, string hypothesis, DayA * dA) :
		nameH("saturday"), _is(is), _hypothesis(hypothesis), _dA(dA) {}
	bool getIs() { return this->_is; }
	string getName() { return this->nameH; }
	string getHypotesis() { return this->_hypothesis; }
	DayA * getDayA() { return _dA; }
private:
	bool _is;
	string nameH;
	string _hypothesis;
	DayA * _dA;
};

template <>
class DayH<Sunday> {
public:
	DayH(bool is, string hypothesis, DayA * dA) :
		nameH("sunday"), _is(is), _hypothesis(hypothesis), _dA(dA) {}
	bool getIs() { return this->_is; }
	string getName() { return this->nameH; }
	string getHypotesis() { return this->_hypothesis; }
	DayA * getDayA() { return _dA; }
private:
	bool _is;
	string nameH;
	string _hypothesis;
	DayA * _dA;
};


