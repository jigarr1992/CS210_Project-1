/*
Name:  Jigar Patel
Class: CS_210 
Project_1: Chada Tech Clock
Prof: Bill, Chan
Date: 11/10/2022
*/


#include<iostream>
#include<ctime>
#include<iomanip>
using namespace std;

//Create class time

class TimeSim {
public:

	//variables
	int hour;
	int minute;
	int seconds;
};

//Create class for 12 hour format
class hour_12_format :public TimeSim {
public:
	string meridian;
	hour_12_format()
	{
		time_t now = time(0);
		tm* ltm = localtime(&now);
		hour = ltm->tm_hour;
		minute = ltm->tm_min;
		seconds = ltm->tm_sec;
		if (hour >= 12)
		{
			meridian = "P M";
			hour -= 12;
		}
		else
			meridian = "A M";

	}
	//Increment hour 1 for 12 hour format
	void add_hour(int h)
	{
		hour += h;
		if (hour > 12)
		{
			hour -= 12;
		}
		else if (hour >= 12)
		{
			if (meridian == "A M")
			{
				meridian = "P M";
			}
			else if (meridian == "P M")
			{
				meridian = "A M";
			}
		}

	}

	//Increment minute 1 for 12 hour format
	void add_minute(int min)
	{
		minute += min;
		if (minute >= 60)
		{
			int h = minute / 60;
			minute -= 60 * h;
			add_hour(h);
		}
	}

	//Increment 1 second for 12 hour format 
	void add_seconds(int sec)
	{
		seconds += sec;
		if (seconds >= 60)
		{
			int m = seconds / 60;
			seconds -= 60 * m;
			add_minute(m);
		}
	}
};

//Create class for 24 hours
class hour_24_format :public TimeSim {
public:
	int hour;
	int minute;
	int seconds;
	hour_24_format()
	{
		time_t now = time(0);
		tm* ltm = localtime(&now);
		hour = ltm->tm_hour;
		minute = ltm->tm_min;
		seconds = ltm->tm_sec;
	}

	//Increment hour 1 for 24 hour format
	void add_hour(int h)
	{
		hour += h;
		if (hour >= 24)
		{
			hour -= 24;
		}
	}

	//Increment minute 1 for 24 hour format
	void add_minute(int min)
	{
		minute += min;
		if (minute >= 60)
		{
			int h = minute / 60;
			minute -= 60 * h;
			add_hour(h);
		}
	}

	//Increment second 1 for 24 hour format
	void add_seconds(int sec)
	{
		seconds += sec;
		if (seconds >= 60)
		{
			int m = seconds / 60;
			seconds -= 60 * m;
			add_minute(m);
		}
	}
};

//function to display for 12 hour and 24 hour format
void display(hour_12_format c1, hour_24_format c2)
{
	cout << "\t\t*************************\t\t";
	cout << "*************************\n";
	cout << "\t\t*\t12-Hour Clock\t*\t\t";
	cout << "*\t24-Hour Clock\t*\n";
	cout << "\t\t*\t" << setw(2) << setfill('0') << c1.hour << ":" << setw(2) << setfill('0') << c1.minute << ":" << setw(2) << setfill('0') << c1.seconds << " " << c1.meridian << "\t*\t\t";
	cout << "*\t" << setw(2) << setfill('0') << c2.hour << ":" << setw(2) << setfill('0') << c2.minute << ":" << setw(2) << setfill('0') << c2.seconds << "\t*\n";
	cout << "\t\t*************************\t\t";
	cout << "*************************\n";
}


//Display option and return manu
int main()
{
	hour_12_format c1;
	hour_24_format c2;
	display(c1, c2);
	int choice = 0;
	while (choice != 4)
	{
		cout << "\n\n*************************\n";
		cout << "* 1 - Add One Hour\t*\n";
		cout << "* 2 - Add One Minute\t*\n";
		cout << "* 3 - Add One Second\t*\n";
		cout << "* 4 - Exit Program\t*\n";
		cout << "*************************\n";


		//Select choice by using switch function
		cin >> choice;
		switch (choice)
		{
		case 1: c1.add_hour(1);
			c2.add_hour(1);
			break;
		case 2: c1.add_minute(1);
			c2.add_minute(1);
			break;
		case 3: c1.add_seconds(1);
			c2.add_seconds(1);
			break;
		case 4:
			exit(0);
			break;
		default:
			cout << "Enter Correct Choice!!\n";
		}

		//Clear screen 
		system("cls");

		//Display result 
		display(c1, c2);
	}
}