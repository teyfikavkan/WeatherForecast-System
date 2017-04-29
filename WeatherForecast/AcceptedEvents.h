#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

class Event
{
public:
	Event(string e, string s) : _eventE(e), _situationE(s) {}
	Event() {}

	void setEventE(string e) { this->_eventE = e; }
	void setSituationE(string s) { this->_situationE = s; }

	string getEventE() { return this->_eventE; }
	string getSituationE() { return this->_situationE; }


private:
	string _eventE;
	string  _situationE;
};