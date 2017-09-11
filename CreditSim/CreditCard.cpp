#include "stdafx.h"
#include "CreditCard.h"
#include <iostream>
#include <fstream>
#include <ctime>
#include <sstream>
using namespace std;
// Gabby Callahan


CreditCard::CreditCard(void)
{
	string fName;
	ifstream fin;
	ostringstream n;
	
	srand((unsigned)time(0));
	Ano = (rand() % 100000) + 1;
	n << Ano << flush;
	fName = "CC" + n.str() + ".txt";
	fin.open(fName.c_str());
	while (fin.is_open())
	{
		fin.close();
		Ano = (rand() % 100000) + 1;
		n << Ano << flush;
		fName = "CC" + n.str() + ".txt";
		fin.open(fName.c_str());
	}
	fin.close();
	vCLimit = 1000;
	vBalDue = 0;
	vABal = (vCLimit - vBalDue);
	CCName = fName;
	CCLName = "CCL" + n.str() + ".txt";
	writestatus();
	writelog("Account " + n.str() + " opened ");
	
}

CreditCard::CreditCard(int a)
{
	string fName;
	ifstream fin;
	ostringstream n;
	vErr = false;
	

	n << a << flush;
	fName = "CC" + n.str() + ".txt";
	fin.open(fName.c_str());
	if (fin.is_open())
	{
		Ano = a;
		fin >> vCLimit;
		fin >> vBalDue;
		fin >> vABal;
		fin.close();
		CCName = fName;
		CCLName = "CCL" + n.str() + ".txt";
		writelog("Account " + n.str() + " reopened ");

	}
	else
	{
		Ano = 0;
		vCLimit = 0;
		vBalDue = 0;
		vErr = true;
		vEMsg = "Account " + n.str() + " could not be opened.";

	}
}
int CreditCard::getActNo()
{
	return Ano;
} 
double CreditCard::getCreditLimit()
{
	return vCLimit;
}
double CreditCard::getBalanceDue()
{
	return vBalDue;

}
double CreditCard::getAvalibleBal()
{
	vABal = vCLimit - vBalDue;
	return vABal;
}
int CreditCard::getIncrease(int amount) 
{
	double inc;
	ostringstream n;
	double x;
	x = vCLimit + amount;
	ostringstream convert;
	string amounts;
	convert << amount;
	amounts = convert.str();

	if (amount % 100 == 0)  
	{
		srand((unsigned)time(0));
		inc = (rand() % 100) + 1;
		n << inc << flush;
		
		if (inc >= 50)
		{	
			cout << "Your increase was approved " << endl;
			cout << "Limit is now " << x << endl;
			writestatus();
			writelog("Increase for " + amounts + " was approved");
			return vCLimit;
			
		}
		else
		{	
			cout << "Your increase was deneid please try again later. " << endl;
			writestatus();
			writelog("Increase for " + amounts + " was denied");

			return vCLimit;
		}
		

	}
	else 
	{ 
		vErr = true;
		cout << "not a valid amount to request. Please try again." << endl;
	}

}
double CreditCard::getPayBal(double x) 
{
	ostringstream convert;
	string balance;
	balance = x;
	

	if (x > 0 && x <= vBalDue)
	{
		vBalDue = (vBalDue - x);
		vABal = (vCLimit - vBalDue);

		cout << " Your new Balance is: " << vBalDue << " and you new avalible balance is now: " << vABal << endl;
		writestatus();
		convert << vBalDue;
		balance = convert.str();
		writelog("payment of " + balance);
	} 
	else if ( x < 0 || x > vBalDue)
	{
		cout << "Not a valid Payment ammount." << endl;
		writelog("payment of " + balance + " declined");
	}
	return (vBalDue && vABal);
}

 void CreditCard::getCCHistory()
{
	
	std::ifstream fout(CCLName.c_str());
	std::stringstream buffer;

	buffer << fout.rdbuf();
	std::string str = buffer.str();
	std::cout << str;

	cout << "You current Avlible Balance is: " << vABal << endl; 
	cin.clear();
	return;

}
void CreditCard::writestatus()
{
	vErr = false;
	vEMsg = "";
	ofstream fout;
	fout.open(CCName.c_str());
	if (fout.is_open())
	{
		fout << vCLimit << endl;
		fout << vBalDue << endl; // write out 
		fout << vABal << endl;
		fout.close();
	} 
	else
	{
		vErr = true;
		vEMsg = "Unable to write status file";

	}
}
void CreditCard::writelog(string m)
{
	vErr = false;
	vEMsg = "";
	time_t rawtime;
	time(&rawtime);

	ofstream fout;
	fout.open(CCLName.c_str(), ios_base::app);
	if (fout.is_open())
	{
		fout << m << " on " << ctime(&rawtime) << endl;
		fout.close();
	}
	else
	{
		vErr = true;
		vEMsg = "Unable to write log entry: " + m;

	}
}
void CreditCard::getCharge(double a, string m) 
{
	double charge;
	charge = a;
	string discrip;
	discrip = m;
	ostringstream convert;
	string charges;

	convert << charge;
	charges = convert.str();
		

			if (vCLimit <= 0)
			{
				vErr = true;
				vEMsg = "Charge attempted on unopened account.";

				return;
			}
			else if (charge <= 0)
			{
				cout << "Charge of " << charge << " declined: must be > 0 " << endl;

				writelog("charge declined " + charges + " for " + discrip);
				return;


			}
			else if ((vBalDue + charge) > vCLimit)
			{
				cout << "Charge of " << charge << " declined - insufficient credit." << endl;
				writelog("charge declined " + charges + " for " + discrip);
			}
			else
			{
				((vBalDue += charge) < vABal);


				cout << "you new Balance is: " << vBalDue << endl;
				writestatus();
				writelog("charge accepted " + charges + " for " + discrip);
			}
		
	
}




CreditCard::~CreditCard(void)
{
}
