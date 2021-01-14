//#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class ClientData
{
	private:
		int accountNumber;
		char name[20];
		double balance;
	public:
		ClientData(int accountNum=0,string name="",double balance=0.0 );
		void setAccountNumber( int accountNum) ;
		int getAccountNumber() const ;
		void setName(string tName);
		string getName() const ;
		void setBalance( double balanceValue);
		double getBalance() const ;
		friend ofstream& operator<< (ofstream&, ClientData&);
}; // end class CientData

enum Choices {CREATE = 0, PRINT, UPDATE, NEW, DELETE, END};
