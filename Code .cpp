// ConsoleApplication2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <string>
#include <cstdio>
#include <ctime>

using namespace std;
void sleep(float seconds) {
	clock_t startClock = clock();
	float secondsAhead = seconds * CLOCKS_PER_SEC;
	while (clock() < startClock + secondsAhead);
	return;
}
void hti()
{
	cout << "***   ***     *********    *********\n";

	sleep(0.5);
	cout << "***   ***     *********        *\n";
	sleep(0.5);
	cout << "*********         *            *\n";
	sleep(0.5);
	cout << "*********         *            *\n";
	sleep(0.5);
	cout << "***   ***         *            *\n";
	sleep(0.5);
	cout << "***   ***         *            *\n";
	sleep(1.0);
}
void Creat()
{
	string from, to, time, Bus_num, Driver, cost, file;
	ofstream output; ifstream input;
	int paseen;
	cout << "please enter from where the line start\n";
	cin >> from;
	cout << "to" << '\n';
	cin >> to;
	cout << "enter time" << '\n';
	cin >> time;
	cout << "please enter number of passsengers" << '\n';
	cin >> paseen;
	cout << "enter bus_num" << '\n';
	cin >> Bus_num;
	cout << "enter Driver name" << '\n';
	cin >> Driver;
	cout << "enter cost for ticket" << '\n';
	cin >> cost;

	file = from + '_' + to + ".txt";
	output.open(file, std::ios_base::app);
	output << "from: " << from << '\n' << "to: " << to << '\n' << "time: " << time << '\n' << "Tieckets: " << paseen << '\n' << "Bus_num: " << Bus_num << '\n'
		<< "Driver: " << Driver << '\n' << "cost: " << cost << '\n';
	output << "****************************************************************";
	output.close();
	output.open("data.txt", std::ios_base::app);
	output << from << "_" << to << '\n';
	output.close();
	system("CLS");

}
void Enquiry()
{
	ofstream output; ifstream input;
	input.open("data.txt"); int i = 1; string serch; string arr[200] = { "null" }; string x;

	while (input>>x)
	{
		input >> x;
		cout << i << "- " << x << '\n';
		x = x + ".txt";

		arr[i] = x;

		i++;
		if (!input)
			break;
	}
	input.close();
	cin >> i;
	serch = arr[i];
	input.open(serch);
	cout << input.rdbuf();
}
void Reservation()
{
	system("CLS");
	cout << "please choose your line\n ";
	ofstream output; ifstream input;
	input.open("data.txt"); int i = 1; string serch; string arr[200] = { "null" }; string x;

	string _, from, to, time, passen, Bus_num, Driver, cost, Client, phone;
	int counter = 1, pass;

	while (input>>x)
	{
		cout << i << "- " << x << '\n';
		x = x + ".txt";

		arr[i] = x;

		i++;
	}
	input.close();
	cin >> i;
	serch = arr[i];
	input.open(serch);
	const char *c = serch.c_str();
	while (!input.eof())
	{
		cout << "enter " << counter << " for \n";

		getline(input, from);
		getline(input, to);
		getline(input, time);
		input >> passen >> pass;
		input.ignore();
		getline(input, Bus_num);

		getline(input, Driver);
		getline(input, cost);
		getline(input, _);
		cout << from << '\n' << to << '\n' << time << '\n' << passen << ": " << pass << '\n' << Bus_num << '\n' << Driver <<
			'\n' << cost << '\n' << _ << '\n';
		counter++;
		break;
	}
	cout << "please enter the Line Number\n";

	input.clear();
	input.seekg(0, std::ios::beg);
	int k;
	cin >> k;
	for (counter = 1; counter <= k; counter++)
	{
		getline(input, from);
		getline(input, to);
		getline(input, time);

		input >> passen >> pass;
		input.ignore();
		getline(input, Bus_num);

		getline(input, Driver);
		getline(input, cost);
		getline(input, _);



	}
	string s_time = time;
	input.seekg(0, std::ios::beg);
	system("CLS");
	cout << from << '\n' << to << '\n' << time << '\n' << passen << ": " << pass << '\n' << cost << '\n' << _;
	cout << "\n enter client Name \n";
	cin.ignore();
	getline(cin, Client);
	cout << " enter phone number \n";
	getline(cin, phone);
	cout << "\n Please enter number of Ticket u need boke \n";
	cin >> k;
	output.open("temp.txt");
	if (k > pass)
	{
		cout << "sorry there is no enouph Tickets \n";
	}
	else if (k <= pass)
	{


		while (!input.eof())
		{
			getline(input, from);
			getline(input, to);
			getline(input, time);
			output << from << '\n' << to << '\n' << time << '\n';
			if (time == s_time)
			{
				input >> passen >> pass;
				input.ignore();
				output << passen << " " << pass - k << '\n';
			}
			else
			{

				input >> passen >> pass;
				input.ignore();
				output << passen << " " << passen << '\n';
			}
			getline(input, Bus_num);

			getline(input, Driver);
			getline(input, cost);
			getline(input, _);

			output << Bus_num << '\n' << Driver << '\n' << cost << '\n' << _ << '\n';





		}


		input.close();
		output.close();
		remove(c);
		rename("temp.txt", c);
		output.open("Client.txt", std::ios_base::app);
		output << '\n' << Client << "                 " << phone << "                 " << k << "\n";

		output.close();


	}
}
	void Clitens()
	{
		fstream input;
		input.open("Client.txt");
		cout << input.rdbuf();
	}






int main()
{
	hti();
	int c;
main_menu:
	system("CLS");
	cout << "please enter \n 1-For Create new Line Or new Trip \n 2For boke Tickets \n 3-For Enquiry All lines\n 4-for Client INFO \n";
	cin >> c;
	switch (c)
	{
	case 1: Creat(); cout << "Created successfully \n Presst 0 for main menu \n";
		cin >> c;
		if (c == 0)
			system("CLS");
		goto main_menu;

		break;
	case 2: Reservation(); cout << "\n booked successfully \n Presst 0 for main menu \n";
		cin >> c;
		if (c == 0)
			goto main_menu;
		break;
	case 3: Enquiry(); cout << "\n Presst 0 for main menu \n";
		cin >> c;
		if (c == 0)
			goto main_menu;
		break;
	case 4: 
		system("CLS");
		Clitens();
		if (c == 0)
			goto main_menu;
		break;
	}

	return 0;
}
