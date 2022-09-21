#include"Bank_1.h"

//Variable Declaration
Bank b;
Account acc;
int choice;
string fname,lname;
long accountNumber;
float balance, amount;

//Function signature Declaration
void printchoices();
void choice1();
void choice2();
void choice3();
void choice4();
void choice5();

int main()
{
    cout<<"***Banking System***"<<endl;
    do
    {
        printchoices();
        cin>>choice;
        switch(choice)
        {
            case 1:
                choice1();
                break;
            case 2:
                choice2();
                break;
            case 3:
                choice3();
                break;
            case 4:
                choice4();
                break;
            case 5:
                choice5();
                break;
            case 6:
                b.ShowAllAccounts();
                break;
            case 7: break;
            default:
                cout<<"\nEnter corret choice";
                exit(0);
        }
    }while(choice!=7);
    return 0;
}
void printchoices(){
    cout<<"\n\tSelect one option below ";
    cout<<"\n\t1 Open an Account";
    cout<<"\n\t2 Balance Enquiry";
    cout<<"\n\t3 Deposit";
    cout<<"\n\t4 Withdrawal";
    cout<<"\n\t5 Close an Account";
    cout<<"\n\t6 Show All Accounts";
    cout<<"\n\t7 Quit";
    cout<<"\nEnter your choice: ";
}
void choice1(){
    cout<<"Enter First Name: ";
    cin>>fname;
    cout<<"Enter Last Name: ";
    cin>>lname;
    balance = 0;
    cout<<"Enter initil Balance: ";
    cin>>balance;
    while(balance < MIN_BALANCE){
        cout<<"Initial balance must be grater than "<<MIN_BALANCE<<endl;
        int choice;
        cout<<"\t\t 1)Continue\n";
        cout<<"\t\t 2)Terminate account creation\n";
        cout<<"\t\t Enter your choice :- ";
        cin>>choice;
        if(choice != 1) 
            return;
        cout<<"Enter initil Balance: ";
        cin>>balance;
    }
    acc=b.OpenAccount(fname,lname,balance);
    cout<<endl<<"Congratulation Account is Created"<<endl;
    // cout<<acc;
}
void choice2(){
    cout<<"Enter Account Number:";
    cin>>accountNumber;
    try{
        acc=b.BalanceEnquiry(accountNumber);
        cout<<endl<<"Your Account Details"<<endl;
        cout<<acc;
    }
    catch(int e){
        cout<<"Account not found"<<endl;
    }
}
void choice3(){
    cout<<"Enter Account Number:";
    cin>>accountNumber;
    cout<<"Enter Balance:";
    cin>>amount;
    acc=b.Deposit(accountNumber, amount);
    cout<<endl<<"Amount is Deposited"<<endl;
    // cout<<acc;
}
void choice4(){
    cout<<"Enter Account Number:";
    cin>>accountNumber;
    cout<<"Enter Balance:";
    cin>>amount;
    acc=b.Withdraw(accountNumber, amount);
    cout<<endl<<"Amount Withdrawn"<<endl;
    cout<<acc;
}
void choice5(){
    cout<<"Enter Account Number:";
    cin>>accountNumber;
    b.CloseAccount(accountNumber);
    cout<<endl<<"Account is Closed"<<endl;
    cout<<acc;
}
