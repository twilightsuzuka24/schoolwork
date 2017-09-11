#include "stdafx.h"
#include "LetterCodeLogic.h"
#include <string>
#include <vector>
#include <sstream>
//Gabby Callahan

using namespace std;
using namespace System;

string LetterCodeLogic::Encode(string m)
{

	int c;
	unsigned int i;
	stringstream result;

	for (i = 0; i < m.length(); i++)
	{
		if (m.at(i) == ' ')
		{
			c = 0;
		}

		else
		{
			if (m.length() > 0)
			{
				m.at(i) = toupper(m.at(i));
				c = (((int)(m.at(i))) - 64);
				
				if (c == 32)
				{
						c == 0;
				}
				else  
				{
			
					if (c < 1 || c > 26)
					{
							c = 99;
					}
				}
			}
		
		}

		result << c << " ";
	}

	return result.str();

}
string LetterCodeLogic::Decode(vector<int> letters)
{
	char c;
	unsigned int i;
	stringstream result;

	for (i = 0; i < letters.size(); i++)
	{
		if (letters[i] == 0)
		{
			c = ' ';
		}
		else
		{
			if (letters[i] < 0 || letters[i] > 26)
			{
				c = '?';
			}
			else
			{
				c = (char)(letters[i] + 64);
			}
		}
		result << c;
	} // end of for
	return result.str();
}