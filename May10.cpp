/*
18.  Lets create a bank account. Create a class named 'BankAccount' with the following data members
1 - Name of depositor
2 - Address of depositor
3 - Type of account
4 - Balance in account
5 - Number of transactions

Class 'BankAccount' has a function for each of the following
1 - Generate a unique account number for each depositor
    For the first depositor, account number will be BA1000, for the second depositor it will be BA1001 and so on
2 - Display information and balance of depositor
3 - Deposit more amount in the balance of any depositor
4 - Withdraw some amount from the balance deposited
5 - Change the address of depositor

After creating the class, do the following operations
1 - Enter the information (name, address, type of account, balance) of the depositors. Number of depositors are to be entered by the user.
2 - Print the information of any depositor.
3 - Add some amount to the account of any depositor and then display the final information of that depositor
4 - Remove some amount from the account of any depositor and then display the final information of that depositor
5 - Change the address of any depositor and then display the final information of that depositor
6 - Randomly repeat these processes for some other bank accounts and after that print the total number of transactions.
*/

#include <iostream>
#include <string>
using namespace std;

static int a=1000;
typedef class BankAccount{
    public:
        string acc_no;
        string name;
        string address;
        string acc_type;
        long double balance;
        int n=0; 
    public:
        BankAccount(){
            acc_no = "BA" + to_string(a);
            a++;
            cout<<"Enter the following detalis respectively: ";
            cout<<"Name, Address, Type of account, Balance."<<endl;
            getchar();
            getline(cin,name);
            getline(cin,address);
            getline(cin,acc_type);
            cin >>  balance;

            cout<< "Input Taken !!"<<endl<<endl;
        }

        void print_data(){
            cout<<"Name: "<< name <<endl<<"Address: "<< address<<endl<<"Account type: "<< acc_type<<endl;
            cout<<"Balance: "<<balance<<endl<<endl; 
        }

        void amount_deposit(){
            cout<<"Enter the amount you want to deposit: ";
            int temp_amt;
            cin>>temp_amt;
            balance+= temp_amt;
            n++;
            cout<<"Balance Updated!! \nThe new balance is: "<<balance<<endl<<endl;
        }

        void amount_withdraw(){
            cout<<"Enter the amount you want to withdraw: ";
            int temp_amt;
            cin>>temp_amt;
            balance-= temp_amt;
            n++;
            cout<<"Balance Updated!!\nThe new Balance is: "<<balance<<endl<<endl;
        }

        void change_address(){
            cout<<"Enter the new address: ";
            getchar();
            getline(cin,address); 
            cout<<"Address updated!!\nThe new address is: "<<address<<endl<<endl;
        }

        void show_transactions(){
            cout<<"No of transactions done in this account till now: "<<n<<endl<<endl;
        }

}emp;


int action(emp &a){
    cout<<"Enter the serial number of action you want to perform: ";
    cout<<"\n1. Print info of a depositor\n2. Add amount\n3. Withdraw amount\n4. Change address\n5. Show number of transctions\n9. Search another account\n0. Exit\n";
    int temp;
    cin>>temp;
    switch (temp)
    {
    case 1:
        a.print_data();
        return 1;
        break;
    case 2:
        a.amount_deposit();
        return 1;
        break;
    case 3:
        a.amount_withdraw();
        return 1;
        break;
    case 4:
        a.change_address();
        return 1;
        break;
    case 5:
        a.show_transactions();
        return 1;
        break;
    case 9:
        return 0;
        break;
    case 0:
        return 99;
        break;
    default:
        return 99;
        break;
    }

}

int main(){
    int n;
    cout<<"Enter number of employees: ";
    cin>>n;
    emp bank1[n];
    
    int flag=0;

    while(flag==0){
        cout<<"\n\nSearch an account to perform action on!!\n";
        cout<<"Choose option, how to search?\n1. Acc_number\n2. Name";
        int temp;
        cin>>temp;
        switch (temp)
            {
            case 1:{
                string acc_no;
                cout<<"Enter the account number(BA1000): ";
                cin>>acc_no;
                for(int i=0;i<n;i++){
                    if(acc_no.compare(bank1[i].acc_no)==0){
                        flag=1;
                        while(flag==1){
                            flag= action(bank1[i]);
                        }
                        break;
                    }else{
                        cout<<"User not found !!\nTry Again!!\n\n";
                        flag=0;
                    }
                } // End of case 1
            }    
                break;

            case 2:{
                string name;
                cout<<"Enter the name: ";
                cin>>name;
                for(int i=0;i<n;i++){
                    if(name.compare(bank1[i].name)==0){
                        flag=1;
                        while(flag==1){
                            flag= action(bank1[i]);
                        }
                        break;
                    }else{
                        cout<<"User not found !!\nTry Again!!\n\n";
                        flag=0;
                    }
                }
            }  
                break;

            default:
                cout<<"Wrong input";
                break;
        }
    }
    return 0;
}