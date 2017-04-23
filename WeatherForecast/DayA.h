#pragma once
#include "AcceptedEvents.h"

class DayA 
{
public:
	void push(string day, string events, bool situation,double LS,double LN, double prior) {
		_days.push_back(day); _events.push_back(events); _situation.push_back(situation); 
		_LS = LN; _LN = LN; _prior = prior;
	}
	string topDays() {return  _days.back(); }
	string topEvents() {return  _events.back(); }
	bool topSituation() {return _situation.back(); }
	void popDays() { _days.pop_back(); }
	void popEvents() { _events.pop_back(); }
	void popSituation() { _situation.pop_back(); }
private:
	double _LS;
	double _LN;
	double _prior;
	vector<string> _days;
	vector<string> _events;
	vector<bool>  _situation;
};