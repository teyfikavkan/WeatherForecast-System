// WeatherForecast.cpp : Konsol uygulamasý için giriþ noktasýný tanýmlar.
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

