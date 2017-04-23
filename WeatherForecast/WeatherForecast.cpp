// WeatherForecast.cpp : Konsol uygulamasý için giriþ noktasýný tanýmlar.
//

#include "stdafx.h"
#include "functions.h"


int main()
{ /*
	
	string b = "aaa";
	cout << "naber";

	DayH<Monday> * a=new DayH<Monday>(true,b);
	cout << a->getIs() << endl;
	cout << a->getHypotesis() << endl;
	cout << a->getName() << endl;
*/
	int t;
	string dayName, dayEvent;
	char dayIS;
	int selection1,selection2;
	bool daySituation;
	int  end;
	Events  * e = new Events();
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

