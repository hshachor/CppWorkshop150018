#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Example 6 - UnSequatial read
#include "ClientData.h"  
int getAccount(const char * const prompt);
int enterChoice();
void printRecord(fstream &creditFl);
void updateRecord(fstream &updateFl);
void deleteRecord(fstream &deleteFromFl);
void newRecord(fstream &addToFl);
void create();

int main()
{
	system("color 9e");
	fstream inOutCredit("credit.dat", ios::in | ios::out | ios::binary);
	if (!inOutCredit)
	{
		cout << "File could not be opened." << endl;
		//return 1;
	} 
	int choice;
	while ((choice = enterChoice()) != END)
	{
		switch (choice)
		{
			case CREATE:
				create();
				break;
			case PRINT:
				printRecord(inOutCredit);
				break;
			case UPDATE:
				updateRecord(inOutCredit);
				break;
			case NEW:
				newRecord(inOutCredit);
				break;
			case DELETE:
				deleteRecord(inOutCredit);
				break;
			default:
				cout << "Incorrect choice" << endl;
		} 
		inOutCredit.clear(); // reset end-of-file flag
	} 
	return 0;
}

void create()
{	// Create credit file
	try
	{
		ofstream createFile( "credit.dat", ios::binary);
		if (!createFile)
			throw "File could not be created.\n"; 
		ClientData client;  // Empty record
		for(int i = 0; i < 100; i++)
			createFile.write((char*) &client,sizeof(ClientData));
	}
	catch(char* msg)
	{
		cout<<msg;
	}
}

int getAccount(const char * const prompt)
{
	int accountNumber;
	do
	{
		cout << prompt << " (1 - 100): ";
		cin >> accountNumber;
	} 
	while ( accountNumber < 1 || accountNumber > 100 );
	return accountNumber;
} 

int enterChoice()
{
	cout << "\nEnter your choice" << endl
	<< "0 - create new credit.dat file\n" 
	<< "1 - store a formatted text file of accounts\n" 
	<< "    called \"print.txt\" for printing" << endl
	<< "2 - update an account" << endl
	<< "3 - add a new account" << endl
	<< "4 - delete an account" << endl
	<< "5 - end program\n? ";
	int menuChoice;
	cin >> menuChoice; 
	return menuChoice;
}  

void printRecord(fstream &creditFl)
{
	try 
	{
		ofstream outPrintFile("print.txt");
		if (!outPrintFile ) 
			throw "File could not be created.\n" ;
		outPrintFile<<"Account"<<'\t'<<"Name"<<'\t'<<"Balance"<<endl;                      
		creditFl.seekg(0);                                
		ClientData client;
		creditFl.read((char*)&client,sizeof(ClientData));                               
		while (creditFl.good()) 
		{
			if (client.getAccountNumber() != 0)
				outPrintFile << client;
			creditFl.read((char*) &client,sizeof(ClientData));                               
		}
		outPrintFile.close();
		// Print on screen
		ifstream inPrintFile("print.txt");
		while(inPrintFile.good())
		{
			char c = inPrintFile.get();
			cout << c;
		}
		inPrintFile.close();
	}
	catch(char *msg)
	{
		cout << msg;
	}
} 

void updateRecord(fstream &updateFl)
{
	int num = getAccount("Enter account to update:");
	updateFl.seekg((num -1) * sizeof(ClientData));     
	ClientData client;
	updateFl.read((char*)&client,sizeof(ClientData));                             
	if (client.getAccountNumber() != 0)
	{
		cout<<client.getName()<<'\t'<<client.getBalance()<<endl;                      
		cout << "\nEnter charge (+) or payment (-): ";
		double transaction; 
		cin >> transaction;
		double oldBalance = client.getBalance();
		client.setBalance(oldBalance + transaction);
		updateFl.seekp((num -1) *  sizeof(ClientData));     
		updateFl.write((char*)&client,sizeof(ClientData));                     
	} 
	else 
		cout << "Account #" << num << " not exist.\n";
} 

void deleteRecord(fstream &deleteFromFl)
{												 
	int num = getAccount("Enter account to delete: " );
	deleteFromFl.seekg((num-1)*sizeof(ClientData));     
	ClientData client;
	deleteFromFl.read((char*)&client,sizeof(ClientData));                                 
	if (client.getAccountNumber() != 0)
	{
		ClientData blankClient;	// Empty record
		deleteFromFl.seekp((num-1)*sizeof(ClientData));                             
		deleteFromFl.write((char*)&blankClient,sizeof( ClientData));                          
		cout << "Account #" << num << " deleted.\n";
	} 
	else 
		cout << "Account #" << num << " is empty.\n";
} 

void newRecord(fstream &addToFl)
{
	int num = getAccount("Enter new account number: ");
	addToFl.seekg((num-1) * sizeof(ClientData));
	ClientData client;
	addToFl.read((char *) &client, sizeof(ClientData));                               
	if (client.getAccountNumber() == 0 )
	{
		char name[20];
		double balance;
		cout << "Enter name and balance: ";
		cin >> name >> balance;
		ClientData client1(num,name,balance);
		addToFl.seekp((num-1) * sizeof(ClientData));                             
		addToFl.write((char*) &client1, sizeof(ClientData));                     
	} 
		else cout << "Account #" << num << " already contains information.\n";
}

