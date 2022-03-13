#include <Bank.h>
#include <bits\stdc++.h>
using namespace std;

int main()
{   
    Bank b;
    Account acc;
    int choice;
    long phoneNumber,accountNumber;
    string fullName;
    float balance,amount;

    cout<<"---Welcome To The *** Bank---"<<endl;
    do
    {
        cout<<"\tSelect one option below"<<endl;
        cout<<"\t1- Open an account"<<endl;
        cout<<"\t2- Deposit Money"<<endl;
        cout<<"\t3- Withdraw Money"<<endl;
        cout<<"\t4- Close an Account"<<endl;
        cout<<"\t5- Show All Accounts"<<endl;
        cout<<"\t6- Quit"<<endl;
        cout<<"\t Enter your choice"<<endl;
        cin>>choice;
        switch (choice)
        {
        case 1:
            cout<<"Enter Your Full Name: "<<endl;
            getline(cin,fullName);
            cout<<"Enter Your Phone Number: "<<endl;
            cin>>phoneNumber;
            cout<<"Enter Your Balance: "<<endl;
            cin>>balance;
            acc=b.openAccount(fullName,phoneNumber,balance);
            cout<<endl<<"Account is Created"<<endl;
            cout<<acc;
            break;
        case 2:
            cout<<"Enter Account Number: "<<endl;
            cin>>accountNumber;
            cout<<"Enter the Money You Want to Deposit: "<<endl;
            cin>>amount;
            acc=b.Deposit(accountNumber,amount);
            cout<<endl<<"Money is Deposited"<<endl;
            cout<<acc;
            break;
        case 3:
            cout<<"Enter Account Number: "<<endl;
            cin>>accountNumber;
            cout<<"Enter the Money You Want to Withdraw: "<<endl;
            cin>>amount;
            acc=b.Withdraw(accountNumber,amount);
            cout<<endl<<"Money is Withdrawn"<<endl;
            cout<<acc;
            break;
        case 4:
            cout<<"Enter Account Number: "<<endl;
            cin>>accountNumber;
            b.closeAnAccount(accountNumber);
            cout<<endl<<"Account is deleted"<<endl;
            cout<<acc;
            break;
        case 5:
            b.showAccount();
            break;
        case 6: break;
        default:
            cout<<"Wrong choice!"<<endl;
            exit(0);
        }
    } while (choice != 6);
    return 0;
}