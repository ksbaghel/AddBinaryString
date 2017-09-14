// AddBinaryString.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

string addBinary(string A, string B)
{
	if (A.length() < B.length()) return addBinary(B, A);

	string res;
	int nB = B.length();
	int nA = A.length();
	int c = 0;
	int a = 0;
	int b = 0;
	int sum = 0;
	int pos = 0;

	while (pos<nB)
	{
		a = A[nA-1-pos] - '0';
		b = B[nB-1-pos] - '0';
		sum = a + b + c;
		if (sum == 3)
		{
			c = 1;
			res = "1" + res;
		}
		else if (sum == 2)
		{
			c = 1;
			res = "0" + res;
		}
		else if (sum == 1)
		{
			c = 0;
			res = "1" + res;
		}
		else {
			c = 0;
			res = "0" + res;
		}
		pos++;
	}

	//pos = n - l-1;
	while (pos<nA)
	{
		a = A[nA-1-pos] - '0';
		sum = a + c;
		if (sum == 2)
		{
			c = 1;
			res = "0" + res;
		}
		else if (sum == 1)
		{
			c = 0;
			res = "1" + res;
		}
		else {
			c = 0;
			res = "0" + res;
		}
		pos++;
	}
	if (c == 1)
	{
		res = "1" + res;
	}

	return res;
}


int main()
{
	string A = "100";
	string B = "11";
	cout << addBinary(A, B) << endl;
    return 0;
}

