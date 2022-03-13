#include <bits\stdc++.h>
using namespace std;

class Account
{
    private:
        string fullName;
        long phoneNumber;
        float balance;
        long accNumber;
        static long nextAccNumber;
    public:
        Account(){};
        Account(string name,long number,float bal);
        long getAccNo(){return accNumber;}
        string getFullName(){return fullName;}
        float getBalance(){return balance;}
        long getPhoneNumber(){return phoneNumber;}
        void Deposit(float amount);
        void withdraw(float amount);
        static void setLastAccountNumber(long AccNumber);
        static long getLastAccountNumber();
        friend ofstream & operator<<(ofstream &ofs, Account &a);
        friend ifstream & operator>>(ifstream &ifs, Account &a);
        friend ostream & operator<<(ostream &os, Account &a);

};
long Account::nextAccNumber=0;
Account::Account(string name,long number,float bal)
{
    fullName=name;
    phoneNumber = number; balance=bal;
}

void Account::Deposit(float amount)
{
    balance += amount;
}

void Account::withdraw(float amount)
{
    balance -= amount;
}

void Account::setLastAccountNumber(long AccNumber)
{
    nextAccNumber = AccNumber;
}

long Account::getLastAccountNumber()
{
    return nextAccNumber;
}

ofstream & operator<<(ofstream &ofs, Account &a)
{
    ofs<<a.fullName<<endl<<endl<<a.phoneNumber<<endl<<a.balance<<endl;
    return ofs;
}

ifstream & operator>>(ifstream &ifs, Account &a)
{
    ifs>>a.fullName>>a.phoneNumber>>a.balance;
    return ifs;
}

ostream & operator<<(ostream &os,Account &a)
{
    os<<"AccountID: "<<a.getAccNo()<<endl;
    os<<"Full Name: "<<a.getFullName()<<endl;
    os<<"Phone Number: "<<a.getPhoneNumber()<<endl;
    os<<"Balance:   "<<a.getBalance()<<endl;

    return os;
}
