// This is the main DLL file.
// Gabby Callahan
#include "stdafx.h"
#include "LetterCodeLogic.h"
#include <string>
#include <iostream>
#include <vector>

using namespace std;
using namespace System;

void getEncodeString();
void getDecodeString();

int main()
{
	char choice;
	cout << "Welcome to the letter code program." << endl;

	do
	{
		cout << "Enclode, Decode, or Quit (E/D/Q): ";
		cin >> choice;
		if (!cin.good())
		{
			cin.clear();
			cin.ignore(1000, '\n');
			choice = '?';
		}
		switch (choice)
		{
		case 'e':
		case 'E':
			getEncodeString();
			break;
		case 'd':
		case 'D':
			getDecodeString();
		case 'q':
		case 'Q':
			break;
		default:
			cout << "Please enter E, D, or Q" << endl;
			break;
		} // end of switch
	} while (toupper(choice) != 'Q');
	cout << "Thanks for using the letter code program." << endl;
	system("Pause");
	return 0;
}

void getEncodeString() // NEEDS TO BE FIXED
{ 
	string m;
	cout << "Please enter your message to be encoded, use spaces between words: " << endl;
	cin.ignore();
	getline(cin, m);


	cout << LetterCodeLogic::Encode(m) << endl;


	return;

	/* obtain input as a string. 
	 call lettercode logic for Encoding
	cout << "Function not yet available" << endl;*/
}

void getDecodeString()
{
	vector<int> letters;
	unsigned int x;

	cout << "Please enter your numbers to be decoded; use space between numbers and 99 to terminate input:" << endl;

	do
	{
		
		cin >> x;

		if (!cin.good())
		{
			cin.clear();
			cin.ignore(1000, '\n');
			x = 99;
		}
		if (x != 99)
		{
			letters.push_back(x);
		}
	} while (x != 99);
	if (letters.size() > 1)
	{
		cout << "\nYour decoded message is: " << endl;
		cout << LetterCodeLogic::Decode(letters) << endl << endl;
	}
	return;
}

