#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Events 
{
public:
	void push(string day, string events, bool situation, double LS, double LN, double prior) {
		_daysE.push_back(day); _eventsE.push_back(events); _situationE.push_back(situation);
		
	}
	string topDaysE() { return  _daysE.back(); }
	string topEventsE() { return  _eventsE.back(); }
	bool topSituationE() { return _situationE.back(); }
	void popDaysE() { _daysE.pop_back(); }
	void popEventsE() { _eventsE.pop_back(); }
	void popSituationE() { _situationE.pop_back(); }
private:
	vector<string> _daysE;
	vector<string> _eventsE;
	vector<bool>  _situationE;
};