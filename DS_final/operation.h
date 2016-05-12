#include <string>
using namespace std;
#ifndef OPERATION_H
#define OPERATION_H
#define ull  double
class operation {
private:
	ull amount;
	int operationType;
	string customer_id;
	string Target_id;
	string name;
	string national_id;
	string feedback;
	ull balance;
public:
	operation(){}
	operation(int operation_id, string customer_name = "", string national_ID = "",ull balance_ = 0.0, ull amount_ = 0.0, string AccID = "", string AccID_to = "" ,string feedback=""){
		operationType = operation_id;
		customer_id = AccID;
		national_id = national_ID;
		name = customer_name;
		Target_id = AccID_to;
		balance = balance_;
		amount = amount_;

	}
	//void setamount(ull k){amount = k;}
	ull getamount(){ return amount ;}
	//void set_customer_id( string x ){customer_id=x;}
	string get_customer_id(){return  customer_id;}
	//void set_Target_id( string x ){Target_id=x;}
	string get_Target_id(){return  Target_id;}
	string get_name() { return  name; }
	string get_national_id() { return national_id; }
	string get_feedback() { return feedback; }
	ull get_balance() { return balance; }
	//void setname(string name) { name = name; }
	//void set_national_id(string national) { national_id = national; }

	
};







#endif