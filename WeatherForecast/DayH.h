#pragma once
#include "AcceptedEvents.h"



class DayH {
public:
	DayH(string s, string e) : _situationH(s), _eventH(e) {}
	DayH() {}
	void setAll(string e, string s) { setEventH(e); setSituationH(s); }
	void setEventH(string e) { this->_eventH = e; }
	void setSituationH(string s) { this->_situationH = s; }

	string getSituationH() { return this->_situationH; }
	string getEventH() { return this->_eventH; }
private:
	string _eventH;
	string _situationH;

};



