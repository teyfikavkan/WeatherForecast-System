#pragma once
#include "AcceptedEvents.h"

class DayA 
{
public:
	DayA (string day, string events, bool situation) {
		_daysA.push_back(day); _eventsA.push_back(events); _situationA.push_back(situation);
		itDayA = _daysA.begin(); itEventA = _eventsA.begin(); itSituationA = _situationA.begin();
		beginA = _daysA.begin(); endA = _daysA.end();

	}
	void setInfo(double LS, double LN, double prior){ _LS=LN; _LN=LN; _prior=prior; }
	string topDaysA() { return  _daysA.back(); }
	string topEventsA() { return  _eventsA.back(); }
	bool topSituationA() { return _situationA.back(); }
	void popDaysA() { _daysA.pop_back(); }
	void popEventsA() { _eventsA.pop_back(); }
	void popSituationA() { _situationA.pop_back(); }
	vector<string>::iterator beginA;
	vector<string>::iterator endA;
	vector<string>::iterator itDayA;
	vector<string>::iterator itEventA;
	vector<bool>::iterator itSituationA;
	
	double getLS() { return _LS; }
	double getLN() { return _LN; }
	double getPrior() { return _prior; }

private:
	double _LS;
	double _LN;
    double _prior;
	vector<string> _daysA;
	vector<string> _eventsA;
	vector<bool>  _situationA;
};