// WeatherForecast.cpp : Konsol uygulamas� i�in giri� noktas�n� tan�mlar.
//

#include "stdafx.h"
#include "DayH.h"


int main()
{
	int i;
	string b = "aaa";
	cout << "naber";

	DayH<Monday> * a=new DayH<Monday>(true,b);
	cout << a->getIs() << endl;
	cout << a->getHypotesis() << endl;
	cout << a->getName() << endl;


    
	cin >> i;
	return 0;
}

