// TempConverter.cpp : main project file.
// Gabby Callahan
#include "stdafx.h"
#include <iostream>
using namespace std;

using namespace System;




double FtoC(double t);
double CtoF(double t);
double KelvinF(double t);	
double KelvinC(double t);


int main()
{
	double temp, result; 
	int choice;
	char response;
	
	

	cout << "Welcome to the Temp Conversion program." << endl;
	

	do
	{
		cout << "Conversion type (1=F to C, 2=C to F, 0=Quit) : ";
		cin >> choice;
		
			
		
		if (choice == 0)
	{
			continue;
	}
	
	
	cout << "Would you like to see degress Kelvin (K) in the results?(Y/N) : ";
		cin >> response;
		response = toupper(response);
		
		if (choice == 1 )
		{
			cout << "Enter Fahrenheit temp: ";
			cin >> temp;
			result = FtoC(temp);
			cout << "A temp " << temp << "F is equal to " << result << "C." << endl;
			
		}
		

		if (choice == 2)
		{
			cout << "Enter Celsius temp: ";
			cin >> temp;
			result = CtoF(temp);
			cout << "A temp " << temp << "C is equal to " << result << "F." << endl;
			
		}
		
	
		if (result < -459.7 || temp < -273.1)
		{
			cout << "Tempature colder then Absolute Zero" << endl;
		}

		
		else if (response == 'Y' && choice == 1)
		{
		cout << "This is also a temperature of: " << KelvinF(temp) << "K" << endl;
		}
			
		else if (response == 'Y' && choice == 2)
		{
		cout << "This is also a temperature of: " << KelvinC(temp) << "K" << endl;
		}

	}
	while (choice != 0);
	cout << "Thanks for using the temp Converter." << endl;
	system("pause");
		return 0;
	}
double FtoC(double t)

{ 
	double r;
	r = (5.0 / 9.0 * (t - 32.0));
	return r;
}
double CtoF(double t)
{
	double s;
	s = ( (t * 9.0) /5.0 +32 );
	return s;
}
double KelvinF(double t)
{
	double kf;
	kf = ((t + 459.67) * 5.0 / 9.0);
	return kf;
}
double KelvinC(double t)
{
	double kc;
	kc = (t + 273.15);
	return kc;
}




