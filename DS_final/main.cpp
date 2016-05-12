#include <iostream>
#include <string>
#include <queue>
#include <list>
#include <queue>
#include <stack>
#include <fstream>
#include <stdlib.h>
#include "operation.h"
#include "CustomerAccount.h"
#include "BST.h"
#include  "bank.h"
#include "banker.h"
#define ull double 
using namespace std;

void main() {

	int mode, op, banker_op;
	char confirm = ' ', f = ' ';
	string password, feedback;
	cout << "Welcome Banking System!" << endl;
a:	cout << "Choose Mode:" << endl << "1.Banker Mode\t" << "2.Client Mode" << endl;
	cin >> mode;
	if (mode == 1)
	{
					Banker banker;
passwordlabel:		cout << "Enter password:" << endl;
					cin >> password;
					if (password == banker.getpassword())
					{
label:					cout << "Choose Queue to do its operation:" << endl;
						cout << "1.Create New Account\t2.Deposit\t3.Withdraw\t4.Balance Check\t\t5.Transfer\t\t6.Feedback\t7.Deactivate Account" << endl;
						cin >> banker_op;
						if (banker_op == 1)
						{
							banker.Creat_Operation();
							cout << "Do you want to do any other operation? y/n" << endl;
							cin >> confirm;
							if (confirm == 'y')
							{
								goto label;
							}
						}
						else if (banker_op == 2)
						{
							banker.Deposit_Operation();
							cout << "Do you want to do any other operation? y/n" << endl;
							cin >> confirm;
							if (confirm == 'y')
							{
								goto label;
							}
						}
						else if (banker_op == 3)
						{
							banker.Withdraw_Operation();
							cout << "Do you want to do any other operation? y/n" << endl;
							cin >> confirm;
							if (confirm == 'y')
							{
								goto label;
							}
						}
						else if (banker_op == 4)
						{
							banker.BalanceCheck();
							cout << "Do you want to do any other operation? y/n" << endl;
							cin >> confirm;
							if (confirm == 'y')
							{
								goto label;
							}
						}
						else if (banker_op == 5)
						{
							banker.Transfer_Operation();
							cout << "Do you want to do any other operation? y/n" << endl;
							cin >> confirm;
							if (confirm == 'y')
							{
								goto label;
							}
						}
						else if (banker_op == 6)
						{
							banker.Feedback_Operation();
							cout << "Do you want to do any other operation? y/n" << endl;
							cin >> confirm;
							if (confirm == 'y')
							{
								goto label;
							}
						}
						else if (banker_op == 7)
						{
							banker.Deactivation_Operation();
							cout << "Do you want to do any other operation? y/n" << endl;
							cin >> confirm;
							if (confirm == 'y')
							{
								goto label;
							}
						}
					}
					else
					{
						cout << "Wrong Password!" << endl;
						goto passwordlabel;
					}

	}
	else if (mode == 2)
	{
		Bank bank;

opm2:	cout << "Choose one operation:" << endl;
		cout << "1.Create New Account\t2.Deposit\t3.Withdraw\t4.Balance Check\t\t5.Transfer\t\t6.Deactivate Account" << endl;
		cin >> op;
		if (op == 1)
		{
			string name, national_id; double balance;
			cout << "Please enter your name(first-mid-surname):" << endl;
			cin >> name;
			//getline(cin,name);
			//cin >> name;
	natid:		cout << "Please enter your National ID:" << endl;
			cin >> national_id;
			if (national_id.length() != 14)
			{
				cout << "Wrong National ID!" << endl;
				goto natid;
			}
			else
			{
				cout << "Please Enter you first deposit:" << endl;
				cin >> balance;
				//save in file
				cout << "Wait until your operation is done." << endl;
				operation ope(0, name, national_id, balance);
				bank.new_account.push_back(ope);
			}
		}
		else if (op == 2)

		{
			string Acc_ID; double amount;
l0:			cout << "Please enter your account ID:" << endl;
			cin >> Acc_ID;
			if (Acc_ID.length() != 14)
			{
				cout << "Wrong Account ID!" << endl;
				goto l0;
			}
			else
			{
				cout << "Please Enter your deposite amount:" << endl;
				cin >> amount;
				//save in file
				cout << "Wait until your operation is done." << endl;
				//show balance
				operation ope(1, "", "", 0.0, amount, Acc_ID);
				bank.deposite.push_back(ope);

				cout << "Do you want to add you feedback? y/n" << endl;
				cin >> f;
				if (f == 'y')
				{
					cin >> feedback;
					//save in file
					cout << "Thank you for your help!\n GoodBye." << endl;
				}
				else
				{
					cout << "Goodbye." << endl;
				}
			}
		}
		else if (op == 3)

		{
			string Acc_ID; double amount;
 l1:		cout << "Please enter your account ID:" << endl;
			cin >> Acc_ID;
			if (Acc_ID.length() != 14)
			{
				cout << "Wrong Account ID!" << endl;
				goto l1;
			}
			else
			{
				cout << "Please Enter your withdrawal amount:" << endl;
				cin >> amount;
				//save in file
				cout << "Wait until your operation is done." << endl;
				//show balance
				operation ope(2, "", "", 0.0, amount, Acc_ID);
				bank.withdraw_queue.push_back(ope);
				cout << "Do you want to add you feedback? y/n" << endl;
				cin >> f;
				if (f == 'y')
				{
					cin >> feedback;
					//save in file
					cout << "Thank you for your help!\n GoodBye." << endl;
				}
				else
				{
					cout << "Goodbye." << endl;
				}
			}
		}
		else if (op == 4)

		{
			string Acc_ID;
	l2:		cout << "Please enter your account ID:" << endl;
			cin >> Acc_ID;
			if (Acc_ID.length() != 14)
			{
				cout << "Wrong Account ID!" << endl;
				goto l2;
			}
			else
			{
				cout << "Wait until your operation is done." << endl;
				//show balance
				operation ope(4, "", "", 0.0, 0.0, Acc_ID);
				bank.Show_balance_queue.push_back(ope);
				cout << "Do you want to add you feedback? y/n" << endl;
				cin >> f;
				if (f == 'y')
				{
					cin >> feedback;
					//save in file
					cout << "Thank you for your help!\n GoodBye." << endl;
				}
				else
				{
					cout << "Goodbye." << endl;
				}
			}
		}
		else if (op == 5)

		{
			string Acc_ID, AccID_to; double amount;
			cout << "Please enter your account ID:" << endl;
			cin >> Acc_ID;
l3:			cout << "Please enter target account ID:" << endl;
			cin >> AccID_to;
			if (Acc_ID.length() != 14 || AccID_to.length() != 14)
			{
				cout << "Wrong Account ID!" << endl;
				goto l3;
			}
			else
			{
				cout << "Please Enter the transfering amount:" << endl;
				cin >> amount;
				//save in file
				cout << "Wait until your operation is done." << endl;
				//show balance
				operation ope(3, "", "", 0.0, amount, Acc_ID, AccID_to);
				bank.Transfer_queue.push_back(ope);
				cout << "Do you want to add you feedback? y/n" << endl;
				cin >> f;
				if (f == 'y')
				{
					cin >> feedback;
					//save in file
					cout << "Thank you for your help!\n GoodBye." << endl;
				}
				else
				{
					cout << "Goodbye." << endl;
				}
			}
		}
		else if (op == 6)

		{
			string Acc_ID;
			
l4:			cout << "Please enter your account ID:" << endl;
			cin >> Acc_ID;
			if (Acc_ID.length() != 14)
			{
				cout << "Wrong Account ID!" << endl;
				goto l4;
			}
			else
			{
				//save in file
				cout << "Wait until your operation is done." << endl;
				//show his data
				operation ope(5, "", "", 0.0, 00, Acc_ID);
				bank.deactivate_queue.push_back(ope);
				cout << "Do you want to add you feedback? y/n" << endl;
				if (f == 'y')
				{
					cin >> feedback;
					//save in file
					cout << "Thank you for your help!\n GoodBye." << endl;
				}
				else
				{
					cout << "Goodbye." << endl;
				}
			}
		}
		
		char endm2;
		cout << "do you want to do another operation ?y/n" << endl;
		cin >> endm2;
		if (endm2 == 'y') {
			goto opm2;
		}
	}
	else
	{
		cout << "Please Re-enter Mode Number." << endl;
		goto a;
	}
	
	
	int endc;
	cout << " To end this session and terminate the application enter 1\nTo go to mode selection enter 2\n";
	cin >>endc;
	if (endc == 2) {
		goto a;
	}

	system("pause");
}