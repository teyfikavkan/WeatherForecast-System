// WeatherForecast.cpp : Konsol uygulamasý için giriþ noktasýný tanýmlar.
//

#include "stdafx.h"
#include "functions.h"


int main()
{
	int t;
	string dayName, dayEvent;
	char dayIS;
	bool daySituation;

	int selection1,selection2;
	double LS, LN, prior;
	
	string nameH, eventH;
	char hypothesisIS;
	bool situationH;
	//int  end;
	Events  * e = new Events();
	DayA * dA;

	vector<DayH<Monday> * > v1;
	vector<DayH<Tuesday> * > v2;
	vector<DayH<Wednesday> * > v3;
	vector<DayH<Thursday> * > v4;
	vector<DayH<Friday> * > v5;
	vector<DayH<Saturday> * > v6;
	vector<DayH<Sunday> * > v7;

	
	cout << "Welcome to Weather Forecast System" << endl;
	
	do {
		cout << "1-)Enter Accepted Events" << endl;
		cout << "2-)Enter Actions of days and Anticipation of the Hypothesis" << endl;
		cout << "3-)Calculate All Ratio of Hypotheses" << endl;
		cout << "4-)Exit from System" << endl;
		cin >> selection1;
		switch (selection1)
		{
				case 1: 
				{	
					cout << "Entry amount of accepted events"<<endl;
					cin >> selection2;;
					for(int i=0;i<selection2;i++)
					{
						cout << "Days:[monday,tuesday,wednesday,thursday,friday,saturday,sunday]" << endl;
						cout << "Entry a day" << endl;
						cin >> dayName;
						cout << "Days:[rainy,windy,warm,sunny,clear]" << endl;
						cout <<"Entry an Event of Weather"<<endl;
						cin >> dayEvent;
						cout << dayName << " " << "is/is not" << " " << dayEvent<<" " <<"[Y/y] or [N/n]" << endl;
						cin >> dayIS;
						if (dayIS == 'Y' || dayIS == 'y')
						{
							daySituation = true;
						}
							
						else if (dayIS == 'N' || dayIS == 'n')
						{
							daySituation = false;
						}
							

						e->push(dayName, dayEvent, daySituation);
						

					}

					break;
				}
				case 2: 
				{
					
					cout << "Entry amount of  events with hypothesis" << endl;
					cin >> selection2;
					
					for (int i = 0; i<selection2; i++)
					{   
						cout << "The" << " " << i + 1 << "action" << endl;
						cout << "Days:[monday,tuesday,wednesday,thursday,friday,saturday,sunday]" << endl;
						cout << "Entry a day" << endl;
						cin >> dayName;
						cout << "Days:[rainy,windy,warm,sunny,clear]" << endl;
						cout << "Entry an Event of Weather" << endl;
						cin >> dayEvent;
						cout << dayName << " " << "is/is not" << " " << dayEvent << " " << "[Y/y] or [N/n]" << endl;
						cin >> dayIS;
						if (dayIS == 'Y' || dayIS == 'y')
						{
							daySituation = true;
						}

						else if (dayIS == 'N' || dayIS == 'n')
						{
							daySituation = false;
						}


						dA = new DayA(dayName, dayEvent, daySituation);


					}

					cout << "The Hypotesis" << endl;
					cout << "Days:[monday,tuesday,wednesday,thursday,friday,saturday,sunday]" << endl;
					cout << "Entry a Day of Hypotesis" << endl;
					cin >> nameH;
					cout << "Days:[rainy,windy,warm,sunny,clear]" << endl;
					cout << "Entry an Event of Weather of Hypotesis" << endl;
					cin >> eventH;
					cout << nameH << " " << "is/is not" << " " << eventH << " " << "[Y/y] or [N/n]" << endl;
					cin >> hypothesisIS;
					if (hypothesisIS == 'Y' || hypothesisIS == 'y')
					{
						situationH = true;
					}

					else if (hypothesisIS == 'N' || hypothesisIS == 'n')
					{
						situationH = false;
					}

					cout << "Enter a ratio of LS" << endl;
					cin >> LS;
					cout << "Enter a ratio of LN" << endl;
					cin >> LN;
					cout << "Enter a prior" << endl;
					cin >> prior;
					dA->setInfo(LS,LN,prior);
						if (dayName == "monday")
						{
							DayH<Monday> * d = new DayH<Monday>(situationH, eventH, dA);
							v1.push_back(d);
						}
						else if (dayName == "tuesday")
						{
							DayH<Tuesday> * d = new DayH<Tuesday>(situationH, eventH, dA);
							v2.push_back(d);
						}
						else if (dayName == "wednesday")
						{
							DayH<Wednesday> * d = new DayH<Wednesday>(situationH, eventH,  dA);
							v3.push_back(d);
						}
						else if (dayName == "thursday")
						{
							DayH<Thursday> * d = new DayH<Thursday>(situationH, eventH, dA);
							v4.push_back(d);
						}
						else if (dayName == "friday")
						{
							DayH<Friday> * d = new DayH<Friday>(situationH, eventH,  dA);
							v5.push_back(d);
						}
						else if (dayName == "saturday")
						{
							DayH<Saturday> * d = new DayH<Saturday>(situationH, eventH, dA);
							v6.push_back(d);
						}
						else if (dayName == "sunday")
						{
							DayH<Sunday> * d = new DayH<Sunday>(situationH, eventH, dA);
							v7.push_back(d);
						}

					
					break;
				}
				case 3:
				{
					break;
				}

				default: 
				{
					if (selection1 == 4)
						cout << "See You Again" << endl;
					else
						cout << "You have entered wrong choice, please try again"<<endl;
					break;
				}
					
		}

	} while (selection1!=4);

	for (e->begin; e->begin!=e->end; e->begin++)
	{ 
		cout << *(e->itDay)<<endl;
		cout << *(e->itEvent)<<endl;
		cout << *(e->itSituation)<<endl;
		e->itDay++;
		e->itEvent++;
		e->itSituation++;

		/*
		cout << e->topDaysE()<<endl;
		cout << e->topEventsE()<<endl;
		cout << e->topSituationE()<<endl;
		e->popDaysE();
		e->popEventsE();
		e->popSituationE();
*/
	}
	cin >> t;
	return 0;
}

