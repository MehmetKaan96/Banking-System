#include <bits\stdc++.h>
#include <Account.h>
using namespace std;

class Bank : public Account
{
    private:
        map<long,Account> accs;
    public:
        Bank();
        Account openAccount(string fName,long number,float balance);
        Account Deposit(long accNumber,float amount);
        Account Withdraw(long accNumber,float amount);
        void closeAnAccount(long accNumber);
        void showAccount();
        ~Bank();
};

Bank::Bank()
{
    Account account;
    ifstream infile;
    infile.open("Bank.txt");
    while (!infile.eof())
    {
        infile>>account;
        accs.insert(pair<long,Account>(account.getAccNo(),account));
    }
    Account::setLastAccountNumber(account.getAccNo());
    infile.close();
}

Account Bank::openAccount(string fName,long number,float balance)
{
    ofstream outputFile;
    Account account(fName,number,balance);
    accs.insert(pair<long,Account>(account.getAccNo(),account));
    outputFile.open("Bank.txt",ios::trunc);
    map<long,Account>::iterator it;
    for (it = accs.begin(); it != accs.end(); it++)
    {
        outputFile<<it->second;
    }
    outputFile.close();
    return account;
}

Account Bank::Deposit(long accNumber,float amount)
{
    map<long,Account>::iterator it=accs.find(accNumber);
    it->second.Deposit(amount);
}

Account Bank::Withdraw(long accNumber,float amount)
{
    map<long,Account>::iterator it=accs.find(accNumber);
    it->second.withdraw(amount);
}

void Bank::closeAnAccount(long accNumber)
{
    map<long,Account>::iterator it=accs.find(accNumber);
    cout<<"Account Deleted!"<<it->second;
    accs.erase(accNumber);
}

void Bank::showAccount()
{
    map<long,Account>::iterator it;
    for (it = accs.begin(); it !=accs.end(); it++)
    {
        cout<<"Account "<<it->first<<endl<<it->second<<endl;
    }
    
}

Bank::~Bank()
{
    ofstream outfile;
    outfile.open("Data.txt",ios::trunc);

    map<long,Account>::iterator iter;
    for(iter=accs.begin();iter != accs.end();iter++)
    {
        outfile<<iter->second;
    }
    outfile.close();
}