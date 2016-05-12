#pragma once
#include <iostream>
#include <queue>
#include <stdlib.h>
#include "CustomerAccount.h"
#include "BST.h"
#include  "bank.h"
#include <ctime>;

#define ull double
using namespace std;

int Time()
{
	time_t currentTime;
	struct tm localTime;

	time(&currentTime);                   // Get the current time
	localtime_s(&localTime, &currentTime);  // Convert the current time to the local time

	int Day = localTime.tm_mday;
	int Month = localTime.tm_mon + 1;
	int Year = localTime.tm_year + 1900;
	int Hour = localTime.tm_hour;
	int Min = localTime.tm_min;
	int Sec = localTime.tm_sec;

	cout << "The Time of Operation : " << Hour << ":" << Min << ":" << Sec << endl;
	cout << "The Date of Operation : " << Day << "/" << Month << "/" << Year << endl;
	return 0;
}

class Banker {

private:
	Bank b;
	string password;
public:
	int pos, pos1, pos2;
	string s,Acc_ID,AccID_target,feedback;
	ull Balance, Balance_target, Amount;
	operation op;

	Banker() {password = "0000";}
	string getpassword() { return password; }
	Bank wbank() {
		return b;
	}
	void Creat_Operation()
	{
		while (b.new_account.size() != 0)
		{
			customerAccount c(b.new_account.front().get_name(), b.new_account.front().get_national_id(),"",b.new_account.front().get_balance());
			c.generate();
			b.accounts.push_back(c);
			//pos = b.accounts.size() - 1;
			//b.AccountIDs.insert(c.getid(),pos); 
			cout << "Welcome to Our Bank!" << endl << "Your Account ID: " << c.getid() << endl << "Your Balance:" << to_string(c.getbalance()) << endl;
			b.new_account.erase(b.new_account.begin());
			//b.accounts.push_back(c);
		}
	}
	void Withdraw_Operation()
	{
		while (b.withdraw_queue.size() != 0)
		{
			//customerAccount c ("","",b.withdraw_queue.front().get_customer_id(), b.withdraw_queue.front().getamount());
			Acc_ID = b.withdraw_queue.front().get_customer_id();
			pos = find(b.AccountsID.begin(), b.AccountsID.end(), Acc_ID) - b.AccountsID.begin();
			if (pos >= 0 && pos < b.AccountsID.size())
			{
				Balance = b.accounts[pos].getbalance();
				Amount = b.withdraw_queue.front().getamount();
				if (Amount > Balance) { 
					cout << "Cannot do this Operation due to in suffent balance" << endl; 
					b.withdraw_queue.erase(b.withdraw_queue.begin());
					continue;
				}
				Balance = Balance - Amount;
				b.accounts[pos].setbalance(Balance);
				cout << "After Withdraw Operation your balance is: " << Balance << endl;
				s = " Customer , " + b.accounts[pos].getname() + "with ID: " + b.accounts[pos].getid() + "did withdraw operation with amount: " + to_string(Amount) + " updating balance to: " + to_string(b.accounts[pos].getbalance()) + "at" + to_string(Time());
				b.accounts[pos].history.push(s);
			}
			else {cout << "No Customer with Account ID: " + Acc_ID << "!" << endl << "There operation won't complete." << endl;}
			b.withdraw_queue.erase(b.withdraw_queue.begin());
		}



	}
	void Deposit_Operation()
	{
		while (b.deposite.size() != 0)
		{
			//customerAccount c ("","",b.withdraw_queue.front().get_customer_id(), b.withdraw_queue.front().getamount());
			Acc_ID = b.deposite.front().get_customer_id();
			pos = find(b.AccountsID.begin(), b.AccountsID.end(), Acc_ID) - b.AccountsID.begin();
			if (pos >= 0 && pos < b.AccountsID.size())
			{
				Balance = b.accounts[pos].getbalance();
				Amount = b.deposite.front().getamount();
				Balance = Balance + Amount;
				b.accounts[pos].setbalance(Balance);
				cout << "After Deposit Operation your balance is: " << Balance << endl;
				s = " Customer , " + b.accounts[pos].getname() + "with ID: " + b.accounts[pos].getid() + "did withdraw operation with amount: " + to_string(Amount) + " updating balance to: " + to_string(b.accounts[pos].getbalance()) + "at" + to_string(Time());
				b.accounts[pos].history.push(s);
			}
			else { cout << "No Customer with Account ID: " + Acc_ID << "!" << endl << "There operation won't complete." << endl; }
			b.deposite.erase(b.deposite.begin());
		}
	}
	void Transfer_Operation()
	{
		while (b.Transfer_queue.size() != 0)
		{
			Amount = (b.Transfer_queue.front()).getamount();
			Acc_ID = b.Transfer_queue.front().get_customer_id();
			AccID_target = b.Transfer_queue.front().get_Target_id();
			pos1 = find(b.AccountsID.begin(), b.AccountsID.end(), Acc_ID) - b.AccountsID.begin();
			pos2 = find(b.AccountsID.begin(), b.AccountsID.end(), AccID_target) - b.AccountsID.begin();
			if (pos1 >= 0 && pos2 >= 0 && pos1 < b.AccountsID.size() && pos2 < b.AccountsID.size())
			{   
				Balance = b.accounts[pos1].getbalance();
				if (Amount > Balance) {
					cout << "Cannot do this Operation due to in suffent balance" << endl;
					b.Transfer_queue.erase(b.Transfer_queue.begin());
					continue;
				}
				////
				Balance = b.accounts[pos1].getbalance() - Amount;
				Balance_target = b.accounts[pos2].getbalance() + Amount;
				b.accounts[pos1].setbalance(Balance);
				b.accounts[pos2].setbalance(Balance_target);
				cout << "After Transfer Operation your balance is: " << Balance << endl;
				s = " Customer , " + b.accounts[pos1].getname() + "with ID: " + Acc_ID+ "did Transfer operation with amount: " + to_string(Amount) + "  to: " + "Target with id :" + AccID_target + " and your balance is updated to  " + to_string(Balance) + "At Duration " + to_string(Time());
				b.accounts[pos1].history.push(s);
				b.accounts[pos2].history.push(s);

			}
			else { cout << "One of the customer or target doesn't have an account!" << endl << "The operation won't be complete." << endl; }
			b.Transfer_queue.erase(b.Transfer_queue.begin());
		}
	}
	void BalanceCheck()
	{
		while (b.Show_balance_queue.size() != 0)
		{
			Acc_ID = b.Show_balance_queue.front().get_customer_id();
			pos = find(b.AccountsID.begin(), b.AccountsID.end(), Acc_ID) - b.AccountsID.begin();
			if (pos >= 0 && pos < b.AccountsID.size())
			{
				Balance = b.accounts[pos].getbalance();

				cout << "Your Balance is : " << Balance<<endl;
				s = " Customer , " + b.accounts[pos].getname() + "with ID: " + Acc_ID + "did Show Balance operation and The Balance was " + to_string(Balance) + "At Duration " + to_string(Time());
				b.accounts[pos].history.push(s);
			}
			else { cout << "No Customer with Account ID: " + Acc_ID << "!" << endl << "There operation won't complete." << endl; }
			b.Show_balance_queue.erase(b.Show_balance_queue.begin());
		}
	}
	void Feedback_Operation() 
	{
		while (b.feedback_queue.size() != 0)
		{
			Acc_ID = b.feedback_queue.front().get_customer_id();
			pos = find(b.AccountsID.begin(), b.AccountsID.end(), Acc_ID) - b.AccountsID.begin();
			if (pos >= 0 && pos < b.AccountsID.size())
			{
				feedback = b.feedback_queue.front().get_feedback();
				//save in feedback file
				s = " Customer: " + b.accounts[pos].getname() + "with ID: " + Acc_ID + "gave us a feedback: "+feedback+ "At Duration " + to_string(Time());
				b.accounts[pos].history.push(s);
			}
			else { cout << "No Customer with Account ID: " + Acc_ID << "!" << endl << "There operation won't complete." << endl; }
			b.feedback_queue.erase(b.feedback_queue.begin());
		}
	}
	void Deactivation_Operation()
	{
		while (b.deactivate_queue.size() != 0)
		{
			Acc_ID = b.deactivate_queue.front().get_customer_id();
			pos = find(b.AccountsID.begin(), b.AccountsID.end(), Acc_ID) - b.AccountsID.begin();
			if (pos >= 0 && pos < b.AccountsID.size())
			{
				char confirm = ' ';
				cout << "Please Confirm The following Information." << endl;
				cout << "Your Name: "<< b.accounts[pos].getname()<< endl <<"Your National ID: "<< b.accounts[pos].getNatid()<< endl << "Your Account ID: " << Acc_ID << endl << "Your Balance:" << to_string(b.accounts[pos].getbalance()) << endl << "y/n?";
				cin >> confirm;
				if (confirm == 'y')
				{
				//	auto it= find(b.accounts.begin(),b.accounts.end(), Acc_ID);
					//auto posx = it - b.accounts.begin();
					vector<string>::iterator x = b.AccountsID.begin() + (int)pos;
					b.AccountsID.erase(b.AccountsID.begin() + (int)pos );
					b.accounts.erase(b.accounts.begin() + pos );
				}
				else { cout << "May you visit our nearest branch to you?"; }
			}
			else { cout << "No Customer with Account ID: " + Acc_ID << "!" << endl << "There operation won't complete." << endl; }
			b.deactivate_queue.erase(b.deactivate_queue.begin());
		}
	}

};
