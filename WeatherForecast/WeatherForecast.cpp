// WeatherForecast.cpp :konsol
//

#include "stdafx.h"
#include "functions.h"

using namespace MyFunctions;

//template<typename T1,typename T2>
int findVolume(vector<string>::iterator itStart, vector<string>::iterator itEnd)
{
	int temp = 0;
     
	for (itStart; itStart != itEnd; itStart++)
	{
		temp++;
	}
	//cout << "temp is" << " " << temp<<endl;
	return temp;
}
void addEvents(Event * e,vector<Event *> & ve)
{   
	string STRING;
	ifstream infile;
	infile.open("event.txt");
	int a = 0;
	int temp = 0;
	string previousLine = "";
	while (a<1) // To get you all the lines.
	{
		
		//cout << "geldi" << endl;
		getline(infile, STRING); // Saves the line in STRING.
		if (STRING != previousLine)
		{
			if (temp % 2 == 0)
			{
				
				previousLine = STRING;
				//cout << STRING << endl;
				e->setEventE(STRING);

			}
			else
			{  // cout << STRING << endl;
				previousLine = STRING;
			//	cout << previousLine << endl;
				
				e->setSituationE(previousLine);
				ve.push_back(e);
				e = new Event();
			}
			//previousLine = STRING;
			//cout << STRING << endl; // Prints our STRING.
			temp++;
		}
		else
		{
			break;
		}

	}

	infile.close();
	
}

void calculateAllHypotesis(vector<DayA *> & vdA, vector<Event *>  ve)
{
	vector<DayA *>::iterator beg = vdA.begin();
	vector<DayA *>::iterator end = vdA.end();
	vector<string>::iterator itEvBeg;
	vector<string>::iterator itEvEnd;
	vector<string>::iterator itStBeg;
	vector<string>::iterator itStEnd;

	vector<Event *>::iterator veBeg = ve.begin();
	vector<Event *>::iterator veEnd = ve.end();

	int i;
	int cntEvent ;
	int cntAcceptedEvent ;
	double prior=1;
	for (beg; beg != end; beg++)
	{
		cntEvent = 0;
		cntAcceptedEvent = 0;
		
		i = 0;
		
		itEvBeg = (*beg)->_eventA.begin();
		itEvEnd = (*beg)->_eventA.end();

		cntEvent = findVolume(itEvBeg,itEvEnd);
		for (vector<Event *>::iterator veBeg = ve.begin(); veBeg != veEnd; veBeg++)
		{
			
		itEvBeg = (*beg)->_eventA.begin();
		itEvEnd = (*beg)->_eventA.end();
		itStBeg = (*beg)->_situationA.begin();
		itStEnd = (*beg)->_situationA.end();

		
			for (itEvBeg; itEvBeg != itEvEnd; itEvBeg++)
			{
				//cout << "bir"<<" " << (*veBeg)->getEventE() << " " << (*veBeg)->getSituationE() << endl;
				//cout << "iki"<<" " << *itEvBeg << " " << *itStBeg << endl;
				if (!(*itEvBeg).compare((*veBeg)->getEventE()))
				{    
					if (!(*itStBeg).compare((*veBeg)->getSituationE()))
					{

                    //cout<<"BULDU " << *itEvBeg << " "<<*itStBeg << endl;
					cntAcceptedEvent++;
					}
					
				}
			
				
               itStBeg++;
			}

			
			
			//cout << "loopa girmedi" << endl;
		}

		if (cntEvent  == cntAcceptedEvent)
		{
			if (prior == 1)
			{
				//cout << "dogru ilk girdi" << endl;
				prior= (((*beg)->getPrior() / (1 - (*beg)->getPrior())) * ((*beg)->getLS())) / (1+ (((*beg)->getPrior() / (1 - (*beg)->getPrior())) * ((*beg)->getLS())));
				(*beg)->setResult(prior);
			}
			else
			{
				//cout << "Dogru ilk deðil girdi" << endl;
				prior = ((prior / (1 - prior)) * ((*beg)->getLS())) / (1 + ((prior / (1 - prior)) * ((*beg)->getLS())));
				(*beg)->setResult(prior);
			}

		}

		else
		{
			if (prior == 1)
			{
				//cout << "yanlýs ilk girdi" << endl;
				prior = (((*beg)->getPrior() / (1 - (*beg)->getPrior())) * ((*beg)->getLN())) / (1 + (((*beg)->getPrior() / (1 - (*beg)->getPrior())) * ((*beg)->getLN())));
				(*beg)->setResult(prior);
			}
			else
			{
				//cout << "yanlýs ilk deðil girdi" << endl;
				prior = ((prior / (1 - prior)) * ((*beg)->getLN())) / (1 + ((prior / (1 - prior)) * ((*beg)->getLN())));
				(*beg)->setResult(prior);
			}
		}


		

		//cout << "beg loopu" << endl;
	}


}


void printAllHypotesis(vector<DayA *> & vdA)
{
	vector<DayA *>::iterator beg = vdA.begin();
	vector<DayA *>::iterator end = vdA.end();
	vector<string>::iterator itEvBeg;
	vector<string>::iterator itEvEnd;
	vector<string>::iterator itStBeg;
	vector<string>::iterator itStEnd;
	int i;
	for (beg; beg != end; beg++)
	{
		i = 0;
		itEvBeg = (*beg)->_eventA.begin();
		itEvEnd = (*beg)->_eventA.end();
		itStBeg= (*beg)->_situationA.begin();
		itStEnd= (*beg)->_situationA.end();
		
		cout << (*beg)->getDayNum() << ".Day" << endl;
		for (itEvBeg; itEvBeg != itEvEnd; itEvBeg++)
		{ 
			
			++i;
			cout <<i<<"."<< *itEvBeg <<" "<< *itStBeg << endl;
			itStBeg++;
		}	
		cout << "LS :"<<(*beg)->getLS()<<" " <<"LN :"<<(*beg)->getLN()<<" " <<"Prior :"<< (*beg)->getPrior() << endl;
		cout << "The hypotesis is " << " " << (*beg)->getDayH()->getEventH() << " " << (*beg)->getDayH()->getSituationH() << endl;
		cout << "New probability of the hypothesis" << " " << (*beg)->getResult()<<endl;
		


	}


}

void printSelectedHypotesis(vector<DayA *> & vdA,string e,string s)
{
	vector<DayA *>::iterator beg = vdA.begin();
	vector<DayA *>::iterator end = vdA.end();
	vector<string>::iterator itEvBeg;
	vector<string>::iterator itEvEnd;
	vector<string>::iterator itStBeg;
	vector<string>::iterator itStEnd;
	int i;
	for (beg; beg != end; beg++)
	{
		i = 0;
		itEvBeg = (*beg)->_eventA.begin();
		itEvEnd = (*beg)->_eventA.end();
		itStBeg = (*beg)->_situationA.begin();
		itStEnd = (*beg)->_situationA.end();
		if (e==(*beg)->getDayH()->getEventH() && s == (*beg)->getDayH()->getSituationH())
		{

			cout << (*beg)->getDayNum() << ".Day" << endl;
			for (itEvBeg; itEvBeg != itEvEnd; itEvBeg++)
			{

				++i;
				cout << i << "." << *itEvBeg << " " << *itStBeg << endl;
				itStBeg++;
			}
			cout << "LS :" << (*beg)->getLS() << " " << "LN :" << (*beg)->getLN() << " " << "Prior :" << (*beg)->getPrior() << endl;
			cout << "The hypotesis is " << " " << (*beg)->getDayH()->getEventH() << " " << (*beg)->getDayH()->getSituationH() << endl;
			cout << "New probability of the hypothesis" << " " << (*beg)->getResult() << endl;
			
			

		}
			


	}


}

int main()
{

	string dayName, dayEvent;
	char dayIS;
	string daySituation;
	string selectedE,selectedS;
	int selection1, selection2,selection3,selection4, selectevent;
	int day = 1;
	double LS, LN, prior;
	int selected=0;
	string nameH, eventH;
	char hypothesisIS, selectedH;
	string situationH;
	//int  end;
	Event  * e;
	DayA * dA;


	vector<Event *> ve;
	vector<DayA *>  vdA;
	

	cout << "Welcome to Weather Forecast System" << endl;

	do {
		cout << "1-)Enter Accepted Events" << endl;
		cout << "2-)Enter Actions of Days and Anticipation of the Hypothesis" << endl;
		cout << "3-)Calculate All Ratio of Hypotheses" << endl;
		cout << "4-)Show the hypotheses" << endl;
		cout << "5-)Exit from System" << endl;
		cin >> selection1;
		switch (selection1)
		{
		case 1:
		{




			cout << "1-)Open the event that has already written" << endl;
			cout << "2-)Create a new event" << endl;
			cout << "3-)Add  new events into old events " << endl;
			cin >> selectevent;
			if (selectevent == 1)
			{
				ifstream file("event.txt");




				if (!file)
				{
					cout << "File is not open!!" << endl;
					cout << "The new text will be creating...." << endl;
					ofstream myfile("event.txt");

				}

				else if (MyFunctions::is_empty(file))
				{
					cout << "File is empty!!" << endl;
				}
				else
				{

					string STRING;
					ifstream infile;
					infile.open("event.txt");
					int a = 0;
					string previousLine = "";
					while (a<1) // To get you all the lines.
					{
						getline(infile, STRING); // Saves the line in STRING.
						if (STRING != previousLine)
						{
							previousLine = STRING;
							cout << STRING << endl; // Prints our STRING.
						}
						else
						{
							break;
						}

					}
					
					infile.close();
					//system("pause");


				}


			}

			else if (selectevent == 2)
			{
				  
				
				cout << "Entry amount of accepted events" << endl;
				cin >> selection2;
				ofstream myfile("event.txt");

				for (int i = 0; i<selection2; i++)
				{

					cout << "[rainy,windy,warm,sunny,clear]" << endl;
					cout << "Entry an Event of Weather" << endl;
					cin >> dayEvent;
					cout << dayEvent << " " << "is/is not" << " " << "[Y/y] or [N/n]" << endl;
					cin >> dayIS;
					if (dayIS == 'Y' || dayIS == 'y')
					{
						daySituation = "yes";
					}

					else if (dayIS == 'N' || dayIS == 'n')
					{
						daySituation = "no";
					}

				


					if (myfile.is_open())
					{
						myfile << dayEvent << "\n";
						myfile << daySituation << "\n";
						myfile.seekp(0, std::ios::end);


					}

				}
				myfile.close();



			}

			else
			{
				
				cout << "Entry amount of accepted events" << endl;
				cin >> selection2;
				ofstream myfile("event.txt", std::ios_base::app);
				
				for (int i = 0; i<selection2; i++)
				{

					cout << "[rainy,windy,warm,sunny,clear]" << endl;
					cout << "Entry an Event of Weather" << endl;
					cin >> dayEvent;
					cout << dayEvent << " " << "is/is not" << " " << "[Y/y] or [N/n]" << endl;
					cin >> dayIS;
					if (dayIS == 'Y' || dayIS == 'y')
					{
						daySituation = "yes";
					}

					else if (dayIS == 'N' || dayIS == 'n')
					{
						daySituation = "no";
					}

				//	e = new Event(dayEvent, daySituation);
				//	ve.push_back(e);

					
					if (myfile.is_open())
					{
						myfile << dayEvent <<"\n";
						myfile << daySituation <<"\n";
						myfile.seekp(0, std::ios::end);
						
						
					}
                    
				}
                myfile.close();
			}





			

			break;
		}
		case 2:
		{
			
			cout << "Enter number of days that will be entered hypothesis" << endl;
			cin >> selection2;
			do {
				cout << "Entry amount of  events for your hypothesis for"<<" "<<day<<".day"<< endl;
				cin >> selection3;



				dA = new DayA(new DayH());
				for (int i = 0; i<selection3; i++)
				{
					cout << "The" << " " << i + 1 << ".action" << endl;
					cout << "[rainy,windy,warm,sunny,clear]" << endl;
					cout << "Entry an Event of Weather" << endl;
					cin >> dayEvent;
					cout << dayEvent << " " << "is/is not" << " " << "[Y/y] or [N/n]" << endl;
					cin >> dayIS;
					if (dayIS == 'Y' || dayIS == 'y')
					{
						daySituation = "yes";
					}

					else if (dayIS == 'N' || dayIS == 'n')
					{
						daySituation = "no";
					}



					dA->setEventA(dayEvent);
					dA->setSituationA(daySituation);


				}

				cout << "Entry a  Hypotesis" << endl;

				cout << "[rainy,windy,warm,sunny,clear]" << endl;
				cout << "Entry an Action of Weather of Hypotesis" << endl;
				cin >> eventH;
				cout << eventH << " " << "is/is not" << " " << "[Y/y] or [N/n]" << endl;
				cin >> hypothesisIS;
				if (hypothesisIS == 'Y' || hypothesisIS == 'y')
				{
					situationH = "yes";
				}

				else if (hypothesisIS == 'N' || hypothesisIS == 'n')
				{
					situationH = "no";
				}

				cout << "Enter a ratio of LS" << endl;
				cin >> LS;
				cout << "Enter a ratio of LN" << endl;
				cin >> LN;
				cout << "Enter a prior" << endl;
				cin >> prior;
				dA->setInfo(LS, LN, prior);
				dA->getDayH()->setAll(eventH, situationH);
				dA->setDayNum(day);
				dA->initialIterator();
				vdA.push_back(dA);

				day++;
				selection2--;
			} while (selection2 != 0);

			
			break;
		}
		case 3:
		{   
			e = new Event();
			addEvents(e, ve);
			calculateAllHypotesis(vdA, ve);
			cout << "Processing....." << endl;
			selected++;
			/*
			e = new Event();
			addEvents(e, ve);
			vector<Event *>::iterator beg = ve.begin();
			vector<Event *>::iterator end = ve.end();


			for (beg;beg!=end;beg++)
			{


				cout << (*beg)->getEventE() << endl;
				cout << (*beg)->getSituationE() << endl;
				


			}
		*/	

		/*	
		    for(int i=0;i<4;i++)
			{  
				
				
				cout<<ve.back()->getEventE()<<endl;
				cout<<ve.back()->getSituationE()<<endl;
				ve.pop_back();


			}
		*/	

			break;
		}
		case 4:
		{
			cout << "1-)Show all hypotheses which are concerned with their day" << endl;
			cout << "2-)Show selected hypotheses with days" << endl;
			cin >> selection4;
			if(selection4==1)
			{      
				if (selected == 0)
				{
					cout << "No added hypotheses that will be displayed!!!" << endl;
				}
				else
				{
                     printAllHypotesis(vdA);
				}
				   
			
			}
			else if (selection4 == 2)
			{
				if (selected == 0)
				{
					cout << "No added hypotheses that will be displayed !!!" << endl;
				}
				else
				{
					cout << "Entry a  Hypotesis" << endl;

					cout << "[rainy,windy,warm,sunny,clear]" << endl;
					cout << "Entry an Action of Weather of Hypotesis" << endl;
					cin >> selectedE;
					cout << selectedE << " " << "is/is not" << " " << "[Y/y] or [N/n]" << endl;
					cin >> selectedH;
					if (selectedH == 'Y' || selectedH == 'y')
					{
						selectedS = "yes";
					}

					else if (hypothesisIS == 'N' || hypothesisIS == 'n')
					{
						selectedS = "no";
					}
					printSelectedHypotesis(vdA, selectedE, selectedS);
				}
				  
			}

			else 
			{
				cout << "You have entered wrong number!!!" << endl;
			}

			break;
		}

		default:
		{
			if (selection1 == 5)
				cout << "See You Again" << endl;
			else
				cout << "You have entered wrong choice, please try again" << endl;
			break;
		}

		}

	} while (selection1 != 5);





	return 0;
}

