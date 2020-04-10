// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include <iomanip>
#include<fstream>
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
	sleep(0.5);
}


int main()
{
		/*ifstream input("Text.txt");
		ofstream out("Info.txt", ios_base::app);
		int a[] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24 }; int i = 0, x;

		cin >> x;
		a[x - 1] = 0;
		for (i = 0; i <= 22; i = i + 4)
		{
			cout << setw(3) << a[i] << setw(3) << a[i + 1] << setw(10) << a[i + 2] << setw(3) << a[i + 3] << '\n';

		}
		
		input >> x;
		out << 6;
		cout << x;
		cin >> x;*/
	
	hti();
		return 0;
	}

