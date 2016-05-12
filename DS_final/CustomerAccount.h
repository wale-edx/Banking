#pragma once
#ifndef CUSTOMERACCOUNT_H
#define CUSTOMERACCOUNT_H

#include <iostream>
#include <string>
#include "operation.h"
#include <queue>
#include <list>
#include <queue>
#include <stack>
#include <fstream>
#include <stdlib.h>
#include <stack>
#include <ctime>
//#include "BST.h"
#define ull double 
//#define for(x) for(int i ; i<x;i++)
using namespace std;

class customerAccount {
public:
	ull getbalance(){return balance ;}
	void setbalance(ull k) {balance = k ;}
	string getname(){return name ;}
	string getNatid() { return national_id; }

	string getid(){return id;}
	string generate() {
	//string id="";
		time_t timer;
		struct tm y2k = { 0 };
		int seconds;

		y2k.tm_hour = 0;   y2k.tm_min = 0; y2k.tm_sec = 0;
		y2k.tm_year = 100; y2k.tm_mon = 0; y2k.tm_mday = 1;

		time(&timer);  /* get current time; same as: timer = time(NULL)  */

		seconds = difftime(timer, mktime(&y2k));
		string xx = to_string(seconds);
	for(int i = 0; i <5; i++)
	{
		
		int digit = rand() % 10;
		string x = to_string(digit);
		
		id += x;
	}
	id += xx;
	return id;
}
	
	stack<string> history;

	
	customerAccount(string n ,string natid,string id_,double balance_)
	{
		id = id_;
		name = n;
		balance = balance_;
		national_id = natid;
	}
	
	customerAccount()
	{
		id = "";
		name = "";
		balance = 0.0;
		national_id = "";
	}

private:
	ull balance;
	string id;
	string name;
	string national_id;
	string ATMserial;
	
};

#endif