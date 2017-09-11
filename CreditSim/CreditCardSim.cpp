// CreditCardSim.cpp : main project file.
// Gabby Callahan

#include "stdafx.h"
#include "CreditCard.h"
#include <iostream>

using namespace std;
using namespace System;

int main(array<System::String ^> ^args)
{
	CreditCard *cc;
	char choice;
	int acctno;
	int actionc;
	string cdiscrp;
	double charge;

	//double charge = 0;
	double payment = 0;
	double increase;


	cout << "Welcome to the CreditCard Simulator" << endl;

	cout << "New or Existing Account? (N/E): "; // needs data validation 
	cin >> choice;
	choice = toupper(choice);

	if (choice == 'N')
	{
		cc = new CreditCard();
		
		cout << "Credit account " << cc->getActNo() << " opened." << endl;
		cout << "Current Balance = " << cc->getBalanceDue() << endl;
		cout << "Credit Card limit is: " << cc->getCreditLimit() << endl;
		cout << "Credit Card Avalible balance: " << cc->getAvalibleBal() << endl;
	}
	else if (choice == 'E')
	{
		cout << "Enter account number: ";
		cin.ignore(1000, '\n');
		cin >> acctno;
		cc = new CreditCard(acctno);
		
		cout << "Credit account " << cc->getActNo() << " was re-opened." << endl;
		cout << "Current Balance = " << cc->getBalanceDue() << endl;
		cout << "Credit Card limit is: " << cc->getCreditLimit() << endl;
		cout << "Credit Card Avalible balance: " << cc->getAvalibleBal() << endl;
	}
	else
	{
		cout << "Invalid Entery" << endl;
	}

	do {
		cout << "Transaction Optitons" << ('\n') <<
			"(0) Quit" << ('\n') << "(1) New Charge" << ('\n') <<
			"(2) Payment" << ('\n') << "(3) Credit Increase Request" << ('\n') <<
			"(4) Card History " << endl;
		cin >> actionc;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore();

		}
		switch (actionc)
		{

		case 0:
			cout << "Thanks for using the Credit Card Simulator." << endl;
			break;

		case 1:


			cout << "How much would you like to charge? ";
			cin >> charge;


			cout << "Please enter a charge discritption: ";
			cin >> cdiscrp;

			cc->getCharge(charge, cdiscrp);




			break;


		case 2:
			cout << "How much would you like to the Payment Amount to be? ";
			cin >> payment;

			cc->getPayBal(payment);

			break;
		case 3:
			cout << "Request Increase in Increments of 100: ";
			cin >> increase;
			cc->getIncrease(increase);

			break;
		case 4:

			cout << "Your acount history is as follows: " << endl;
			cc->getCCHistory();
			break;
		}

	} while (actionc != 0);

	system("Pause");

    
    return 0;
}
