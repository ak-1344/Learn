#include <iostream>
#include <string>
using namespace std;
class BankAccount
{
private:
    string accountholder_name;
    int account_number;
    double initial_balance;
    double balance; 
    int number;

public:
    BankAccount()
    {
        accountholder_name = "unknown";
        account_number = 0;
        initial_balance = 0.0;
    }
    BankAccount(string name, double b)
    {
        accountholder_name = name;
        initial_balance = b;
        balance=b;
    }
    BankAccount(string name, int acc_number, double balance)
    {
        accountholder_name = name;
        account_number = acc_number;
        initial_balance = balance;
    }
    void deposit(double amount)
    {
        initial_balance += amount;
    }
    void withdrawal(double amount)
    {
        if (initial_balance < amount)
        {
            cout << "insufficient amount";
            return;
        }
        initial_balance -= amount;
    }
    void display()
    {
        cout << "accountholder_name:" << accountholder_name << endl;
        cout << "account_number:" << account_number << endl;
        cout << "initial balance:" << initial_balance << endl;
    }
};
int main()
{
    BankAccount acc1("kumud", 1000.0);
    BankAccount acc2("khushi", 200, 2000.0); //first name, then acc number, then initial amount
    BankAccount acc3("bhavya", 300, 3000.0); //Same here
    
    acc1.display();
    cout << endl;
    acc2.display();
    cout << endl;
    acc3.display();
    cout << endl;

    acc1.withdrawal(500);
    acc1.deposit(4000);
    acc1.deposit(100);
    acc1.withdrawal(500);
    acc2.deposit(890);
    acc2.withdrawal(300);
    acc3.deposit(6780);
    acc3.withdrawal(400);

    cout << "updated details" << endl;
    acc1.display();
    cout << endl;
    acc2.display();
    cout << endl;
    acc3.display();
    cout << endl;

    return 0;
}