#include <iostream>
using namespace std;
#include <fstream>
#include "ClientData.h"  

enum Choices { PRINT = 1, UPDATE, NEW, DELETE, END };

int getAccount(const char* const prompt)
{
    int accountNumber;
    do
    {
        cout << prompt << " (1 - 100): ";
        cin >> accountNumber;
    } while ((accountNumber < 1 || accountNumber > 100) && cin);
    return accountNumber;
}

int enterChoice()
{
    cout << "\nEnter your choice" << endl
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
void myPrintRecord(fstream& dataFile) {
    ostream output("print.txt");
    output << "Account\tName\tBalance\n";
    ClientData record;
    dataFile.seekg(0);
    for (int i = 0; i < 100; i++) {
        dataFile.read((char*)&record, sizeof(ClientData));
        if (record.getAccountNumber() > 0) {
            output << record;
        }
    }
}
void printRecord(fstream& creditFl)
{
    ofstream outPrintFile("print.txt");
    if (!outPrintFile)
        throw "File could not be created.\n";
    outPrintFile << "Account" << '\t' << "Name" << '\t' << "Balance" << endl;
    creditFl.seekg(0);
    ClientData client;
    creditFl.read((char*)&client, sizeof(ClientData));
    while (!creditFl.eof())
    {
        if (client.getAccountNumber() != 0)
            outPrintFile << client;
        creditFl.read((char*)&client, sizeof(ClientData));
    }
}

void updateRecord(fstream& updateFl)
{
    int num = getAccount("Enter account to update:");
    updateFl.seekg((num - 1) * sizeof(ClientData));
    ClientData client;
    updateFl.read((char*)&client, sizeof(ClientData));
    if (client.getAccountNumber() != 0)
    {
        cout << client.getName() << '\t';
        cout << client.getBalance() << endl;
        cout << "\nEnter charge (+) or payment (-): ";
        double transaction;
        cin >> transaction;
        double oldBalance = client.getBalance();
        client.setBalance(oldBalance + transaction);
        updateFl.seekp((num - 1) * sizeof(ClientData));
        updateFl.write((char*)&client, sizeof(ClientData));
    }
    else
        cout << "Account #" << num << " not exist.\n";
}

void deleteRecord(fstream& deleteFromFl)
{
    int num = getAccount("Enter account to delete: ");
    deleteFromFl.seekg((num - 1) * sizeof(ClientData));
    ClientData client;
    deleteFromFl.read((char*)&client, sizeof(ClientData));
    if (client.getAccountNumber() != 0)
    {
        ClientData blankClient;
        deleteFromFl.seekp((num - 1) * sizeof(ClientData));
        deleteFromFl.write((char*)&blankClient, sizeof(ClientData));
        cout << "Account #" << num << " deleted.\n";
    }
    else
        cout << "Account #" << num << " is empty.\n";
}

void newRecord(fstream& addToFl)
{
    int num = getAccount("Enter new account number: ");
    addToFl.seekg((num - 1) * sizeof(ClientData));
    ClientData client;
    addToFl.read((char*)&client, sizeof(ClientData));
    if (client.getAccountNumber() == 0)
    {
        char name[20];
        double balance;
        cout << "Enter name and balance: ";
        cin >> name >> balance;
        ClientData client1(num, name, balance);
        addToFl.seekp((num - 1) * sizeof(ClientData));
        addToFl.write((char*)&client1, sizeof(ClientData));
    }
    else cout << "Account #" << num << " already exists.\n";
}

int main()
{
    try {
        fstream inOutCredit("credit.dat", ios::in | ios::out | ios::binary);
        if (!inOutCredit)
        {
            throw " could not open file.\n";
        }
        int choice;
        while ((choice = enterChoice()) != END)
        {
            switch (choice)
            {
            case PRINT:
                try {
                    printRecord(inOutCredit);
                }
                catch (char* msg) {
                    cout << msg;
                }
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
            inOutCredit.clear(); // reset end-of-file indicator
        }
    }
    catch (char* msg) {
        cout << msg;
    }
    return 0;
}
