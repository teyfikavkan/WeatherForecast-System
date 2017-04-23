#pragma once
#include "AcceptedEvents.h"

class DayA 
{
public:
	DayA (string day, string events, bool situation,double LS,double LN, double prior) {
		_days=day; _events=events; _situation=situation; 
		_LS=LN; _LN=LN; _prior=prior;
	}
	
	bool getSituation() { return _situation; }
	string getDays() { return  _days; }
	string getEvents() { return  _events; }
	double getLS() { return _LS; }
	double getLN() { return _LN; }
	double getPrior() { return _prior; }

private:
	double _LS;
	double _LN;
	double _prior;
	string _days;
	string _events;
	bool  _situation;
};