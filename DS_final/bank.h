#pragma once
#include <iostream>
#include <string>
#include <queue>
#include <list>
#include <vector>
#include <stack>
#include <fstream>
#include <stdlib.h>
#include "operation.h"
#include "CustomerAccount.h"
#include "BST.h"

#define ull  double
using namespace std;

class Bank {

protected:
	vector<customerAccount> accounts;
	
	vector<string> AccountsID;
	

public:
	deque<operation>  withdraw_queue;
	deque<operation>  new_account;
	deque<operation>  deposite;
	deque<operation>  deactivate_queue;
	deque<operation>  Transfer_queue;
	deque<operation>  Show_balance_queue;
	deque<operation>  feedback_queue;
	void pasrse_new_acccunt(string line) {
		string name,natid,balance_s;
		double balance;
		line = line.substr(2,line.length());
		
		name = line.substr(0, line.find(','));
		line = line.substr(line.find(',')+1, line.length() - name.length());
		
		natid = line.substr(0, line.find(','));
		line = line.substr(line.find(',')+1, line.length() - natid.length());
		
		balance_s = line.substr(0, line.find(','));
		balance =stod(balance_s);
		operation op(0, name, natid, balance);
		new_account.push_back(op);
	}
	void pasrse_deposit(string line) {
		string accId, natid, amount_s;
		double amount;
		line = line.substr(2, line.length());

		accId = line.substr(0, line.find(','));
		line = line.substr(line.find(',') + 1, line.length() - accId.length());

		amount_s = line.substr(0, line.find(','));
		amount = stod(amount_s);
		operation op(1,"","",0.0,amount,accId);
		deposite.push_back(op);
	}
	void pasrse_withdraw(string line) {
		string accId, natid, amount_s;
		double amount;
		line = line.substr(2, line.length());

		accId = line.substr(0, line.find(','));
		line = line.substr(line.find(',') + 1, line.length() - accId.length());

		amount_s = line.substr(0, line.find(','));
		amount = stod(amount_s);
		operation op(2, "", "", 0.0, amount, accId);
		withdraw_queue.push_back(op);
	}
	void pasrse_transfer(string line) {
		string accId, natid, targetId, amount_s;
		double amount;
		line = line.substr(2, line.length());

		accId = line.substr(0, line.find(','));
		line = line.substr(line.find(',') + 1, line.length() - accId.length());
		
		targetId = line.substr(0, line.find(','));
		line = line.substr(line.find(',') + 1, line.length() - targetId.length());

		amount_s = line.substr(0, line.find(','));
		amount = stod(amount_s);
		operation op(3, "", "", 0.0, amount, accId,targetId);
		Transfer_queue.push_back(op);
	}
	void pasrse_review(string line) {
		string accId, natid, targetId, amount_s;
		double amount;
		line = line.substr(2, line.length());
		accId = line.substr(0, line.find(','));

		operation op(4, "", "", 0.0, 0.0, accId);
		Show_balance_queue.push_back(op);
	}
	void pasrse_deactivate(string line) {
		string accId, natid, targetId, amount_s;
		double amount;
		line = line.substr(2, line.length());
		accId = line.substr(0, line.find(','));

		operation op(4, "", "", 0.0, 0.0, accId);
		deactivate_queue.push_back(op);
	}
	
	void load_op_data() {
		string line;
		ifstream in("file.txt");
	
		while (getline(in, line))
		{
			if (line[0] == '#')//to do comments only valid lw fe awl el satr
				continue;
			if (line[0] == '0')
				pasrse_new_acccunt(line);
			else if (line[0] == '1')
				pasrse_deposit(line);
			else if (line[0] == '2')
				pasrse_withdraw(line);
			else if (line[0] == '3')
				pasrse_transfer(line);
			else if (line[0] == '4')
				pasrse_review(line);
			else if (line[0] == '5')
				pasrse_deactivate(line);
		}


	}
	void load_users_data() {
		string line;
		ifstream in("users.txt");

		while (getline(in, line))
		{
			if (line[0] == '#')//to do comments only valid lw fe awl el satr
				continue;
			string name, natid, accID, balance_s;
			double balance;
			name = line.substr(0, line.find(','));
			line = line.substr(line.find(',') + 1, line.length() - name.length());

			natid = line.substr(0, line.find(','));
			line = line.substr(line.find(',') + 1, line.length() - natid.length());
			
			accID = line.substr(0, line.find(','));
			line = line.substr(line.find(',') + 1, line.length() - accID.length());

			balance_s = line.substr(0, line.find(','));
			balance = stod(balance_s);

			customerAccount user (name, natid, accID, balance);
			accounts.push_back(user);
		}

		for each (customerAccount user in accounts)
		{
			AccountsID.push_back(user.getid());
		}


	}

	Bank() {
		load_op_data();
		load_users_data();

	}

	~Bank() {

		//save account vector to users.xml file 
		//remember you should clear the file first
		//name,national_id,account_id,balance
		string line;
		ofstream out("users.txt");
		out << "#comments start with #\n#Legend:\n# name,national_it,account, id,balance\n######################################\n";
		for each (customerAccount user in accounts)
		{
			string name = user.getname();
			string account_id = user.getid();
			string national_id = user.getNatid();
			double balance = user.getbalance();
			out << name+","+national_id+","+account_id+","<<balance<<endl;
			
		}
			out.close();

		////////////////////////////////////
		//nsave el operation queues to the file.xml hn3mlo esm tany later 
		//el mafrod zy el fo2 bs hykon feha bnsba kbera :3
		ofstream fout("file.txt");
		fout << "#operationtype,name,nationalid,balance,ammount,Accountid,targetaccountid,feedback\n#\n#operationtype :\n# 0 = > newaccount = > operationtype, name, nationalid, balance\n# 1 = > deposit = > operationtype, Accountid, amount\n# 2 = > withdraw = > operationtype, Accountid, amount\n# 3 = > transfer = > operationtype, Accountid, targetaccountid, amount\n# 4 = > review data / balance = >operationtype, accountid\n# 5 = > deactivate = >operationtype, accountid\n#################################################\n";
		for each (operation op in new_account)
		{
			string name = op.get_name();
			string national_id = op.get_national_id();
			double balance = op.get_balance();
			fout << "0," + name + "," + national_id +"," << balance << endl;

		}
		for each (operation op in withdraw_queue)
		{
			
			string customer_id = op.get_customer_id();
			double amount = op.getamount();
			fout << "2," + customer_id + "," << amount << endl;

		}
		for each (operation op in deposite)
		{
		
			string customer_id = op.get_customer_id();
			double amount = op.getamount();
			fout << "1,"+ customer_id + "," << amount << endl;

		}
		for each (operation op in Transfer_queue)
		{
			string customer_id = op.get_customer_id();
			string target_id = op.get_Target_id();
			double amount = op.getamount();
			fout << "3," + customer_id + "," + target_id + "," << amount << endl;

		}
		for each (operation op in Show_balance_queue)
		{
			string customer_id = op.get_customer_id();
			fout << "4," + customer_id << endl;

		}
		for each (operation op in deactivate_queue)
		{
			string customer_id = op.get_customer_id();
			fout << "5," + customer_id << endl;

		}
		fout.close();
	}
	friend class Banker;
};