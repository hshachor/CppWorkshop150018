#include <iostream>
#include "ClientData.h"
#include <cstring>

using namespace std;

ClientData::ClientData(int accountNum, string Name, double Balance)
{
    setAccountNumber(accountNum);
    setName(Name);
    setBalance(Balance);
}

void ClientData::setAccountNumber(int accountNum)
{
    accountNumber = accountNum;
}

int ClientData::getAccountNumber() const
{
    return accountNumber;
}

void ClientData::setName(string Name)
{
    strcpy(name, Name.c_str());
}

string ClientData::getName() const
{
    return name;
}

void ClientData::setBalance(double balanceValue)
{
    balance = balanceValue;
}

double ClientData::getBalance() const
{
    return balance;
}

ofstream& operator<<(ofstream& os, ClientData& client)
{
    os << client.accountNumber << '\t' << client.name << '\t' << client.balance << '\n';
    return os;
}



