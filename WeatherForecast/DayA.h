#pragma once
#include "DayH.h"


class DayA
{
public:
	DayA(DayH * dH) { _dH = dH; _result = 0; }
	void setInfo(double LS, double LN, double prior) { _LS = LS; _LN = LN; _prior = prior; }
	void setEventA(string e) {  _eventA.push_back(e); }
	void setSituationA(string s) { _situationA.push_back(s); }
	void setDayNum(int dayNum) { _dayNum = dayNum; }
	void setResult(double result) { _result = result; }

	string topEventA() { return  _eventA.back(); }
	string topSituationA() { return _situationA.back(); }
	int getDayNum() { return this->_dayNum; }
	double getResult() { return _result; }

	void popEventsA() { _eventA.pop_back(); }
	void popSituationA() { _situationA.pop_back(); }
	void initialIterator() { itEvBeg = _eventA.begin(); itEvBeg = _eventA.end(); itStBeg = _situationA.begin(); itStEnd = _situationA.end(); }

	double getLS() { return _LS; }
	double getLN() { return _LN; }
	double getPrior() { return _prior; }
	DayH * getDayH() { return _dH; }
	
	vector<string>::iterator itEvBeg;
	vector<string>::iterator itEvEnd;
	vector<string>::iterator itStBeg;
	vector<string>::iterator itStEnd;

	vector<string> _eventA;
	vector<string>  _situationA;
private:
	double _result;
	double _LS;
	double _LN;
	double _prior;
	int _dayNum;
	DayH * _dH;

};