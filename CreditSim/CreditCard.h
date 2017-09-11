#pragma once
#include <string>
using namespace std;
// Gabby Callahan

class CreditCard
{
public:
	CreditCard(void);
	CreditCard(int a);
	double getCreditLimit();
	double getBalanceDue();
	int getActNo();
	void getCharge(double a, string m);
	int getIncrease(int amount);
	void getCCHistory();
	double getPayBal(double x);
	double getAvalibleBal();
	
	~CreditCard(void);
	

private:
	int Ano;
	bool vErr;
	string vEMsg;
	double vCLimit, vBalDue, vABal; // avalible credit varibale
	void writestatus();
	void writelog(string m);
	string CCName, CCLName;


};

