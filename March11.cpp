#include <iostream>
#include <string>
using namespace std;

// Structre to store data for online Banking system
typedef struct bank{
    string name;
    string code;
    string acc_type;
    double amount;
    string address;
    string email;
}bank;

// Taking input of the employee
bank input(){
    bank a;
    int temp;
    string temp2,temp3;
    cout<<"\nEnter the name of employee:";
    cin>>temp2;
    getline(cin,a.name);
    cout<<"\nEnter the customer code: ";
    cin>>a.code;
    cout<<"\nChoose the account type:\n(1). Saving\n(2). Current\n(3). Fixed: ";
    cin>>temp;
    switch (temp)
    {
    case 1:
        a.acc_type="Saving";
        break;
    case 2:
        a.acc_type="Current";
        break;
    case 3:
        a.acc_type="Fixed";
        break;
    
    default:
        cout<<"You entered the wrong input.";
        break;
    }
    cout<<"\nEnter the amount: ";
    cin>>a.amount;
    cout<<"\nEnter the adress: ";
    cin>>temp3;
    getline(cin,a.address);
    cout<<"\nEnter the email of the employee: ";
    cin>>a.email;
    return a;
}

// Printing full employee details
void print(bank a){
    cout<<a.code<<" "<<a.name<<" "<<a.acc_type<<" "<<a.amount<<" "<<a.address<<" "<<a.email;
}

//Printing specific details of an employee
void print_name(bank a){
    cout<<a.name;
}
void print_code(bank a){
    cout<<a.code;
}
void print_acc_type(bank a){
    cout<<a.acc_type;
}
void print_amount(bank a){
    cout<<a.amount;
}
void print_adress(bank a){
    cout<<a.address;
}
void print_email(bank a){
    cout<<a.email;
}

// Editing details of a given employee
bank edit(bank a){
    bank b=a;
    cout<<"Enter the number of option you want to edit:";
    cout<<"\n1. Name\n2. Customer code\n3. Acc type\n4. Amount\n5. Adress\n6. Email\n:";
    int temp;
    cin>>temp;
    switch (temp)
    {
    case 1:
        getline(cin,b.name);
        break;
    case 2:
        cin>>b.code;
        break;
    case 3:{
        cout<<"Choose the account type:\n(1). Saving\n(2). Current\n(3). Fixed";
        cin>>temp;
        switch (temp)
        {
        case 1:
            a.acc_type="Saving";
            break;
        case 2:
            a.acc_type="Current";
            break;
        case 3:
            a.acc_type="Fixed";
            break;

        default:
            cout<<"You entered the wrong input.";
            break;
        }
        break;
        }
    case 4:
        cin>>b.amount;
        break;
    case 5:
        getline(cin,b.address);
        break;
    case 6:
        cin>>b.email;
        break;
    default:
        cout<<"No valid input given.";
        break;
    }
    return b;
}

//Deleting an element
bank delete_entry(bank a){
    // Guessed that new element will be having null values
    bank b;
    return b;
}

//Trying to make a class and work on it.
typedef class employee{
    public:
        bank a;
        //Taking input of all the members
        employee(){
            a=input();
        }
        //Printing all the details of a given employee
        void print_all(){
            print(a);
        }
}emp;

//Searching employee
void search(emp *a){
    cout<<"Search by name(1) or search by code(2)";
    int temp;cin>>temp;
    if(temp==1){
        string temp1;
        cout<<"Enter the name: ";
        cin>>temp1;
        for(int i=0;i<sizeof(a)/sizeof(a[0]);i++){
            if(temp1.compare(a[i].a.name)==0){
                a[i].print_all();
            }
        }
    }else if(temp==2){
        string temp1;
        cout<<"Enter the customer code: ";
        cin>>temp1;
        for(int i=0;i<sizeof(a)/sizeof(a[0]);i++){
            if(temp1.compare(a[i].a.code)==0){
                a[i].print_all();
            }
        }
    }  
}


//Searching employee to delete
bank search_delete(emp *a){
    cout<<"Search by name(1) or search by code(2)";
    int temp;cin>>temp;
    if(temp==1){
        string temp1;
        cout<<"Enter the name: ";
        cin>>temp1;
        for(int i=0;i<sizeof(a)/sizeof(a[0]);i++){
            if(temp1.compare(a[i].a.name)==0){
                a[i].print_all();
                return a[i].a;
            }
        }
    }else if(temp==2){
        string temp1;
        cout<<"Enter the customer code: ";
        cin>>temp1;
        for(int i=0;i<sizeof(a)/sizeof(a[0]);i++){
            if(temp1.compare(a[i].a.code)==0){
                a[i].print_all();
                return a[i].a;
            }
        }
    }  
}
//Sorting algo
//pseudo functions
emp* sort_by_name(emp* a){
    emp temp;
    for(int i=0; i<(sizeof(a)/sizeof(a[0]))-1; i++){
        if(a[i].a.name.compare(a[i+1].a.name)>0){
            temp=a[i+1];
            a[i+1]=a[i];
            a[i]=temp;
        }
    }
    return a;
}
emp* sort_by_id(emp* a){
    emp temp;
    for(int i=0; i<(sizeof(a)/sizeof(a[0]))-1; i++){
        if(a[i].a.code.compare(a[i+1].a.code)>0){
            temp=a[i+1];
            a[i+1]=a[i];
            a[i]=temp;
        }
    }
    return a;
}
emp* sort_by_acctype(emp* a){
    emp temp;
    for(int i=0; i<(sizeof(a)/sizeof(a[0]))-1; i++){
        if(a[i].a.acc_type.compare(a[i+1].a.acc_type)>0){
            temp=a[i+1];
            a[i+1]=a[i];
            a[i]=temp;
        }
    }
    return a;
}
emp* sort_by_amount(emp* a){
    emp temp;
    for(int i=0; i<(sizeof(a)/sizeof(a[0]))-1; i++){
        if(a[i].a.amount > a[i+1].a.amount){
            temp=a[i+1];
            a[i+1]=a[i];
            a[i]=temp;
        }
    }
    return a;
}
//Main sorting funtion
emp* sort(emp *a){
    cout<<"Sort by what?";
    cout<<"\n1. Name\n2. Customer id\n3. Amount \n4. Account type";
    int sort_type;
    cin>> sort_type;
    switch (sort_type)
    {
    case 1:
        return sort_by_name(a);
        break;
    case 2:
        return sort_by_id(a);
        break;
    case 3:
        return sort_by_amount(a);
        break;
    case 4:
        return sort_by_acctype(a);
        break;
    default:
        cout<<"Wrong input.\n";
        break;
    }
}


//All the functions called in here.
int action(emp *a){
    cout<<"\n1. Master Table\n2. Print specific content\n3. Delete an entry\n4. Edit entry\n5. Search and print\n6. Sort entries\n0. Exit.";
    int temp;
    cin>>temp;
    switch (temp)
    {
    case 1:
        for(int i=0;i<sizeof(a)/sizeof(a[0]);i++){
            a[i].print_all();
        }
        break;
    case 2:{
            cout<<"Please choose which option you want to print: \n";
            cout<<"1. Customer Code\n2. Name\n3. Account type of each customer\n4. Amount\n5. Adress\n6. Email-ID\n";
            cout<<"Please enter all entry you want without space.";
            int temp2;
            cin>>temp2;
            int temp1=0;
            for(int i=temp2;i>0;i=i/10){
                temp1=temp1*10 +i;
            }
            for(int i=0;i<sizeof(a)/sizeof(a[0]);i++){
                for(int i=temp;i>0;i=i/10){
                    switch (i%10)
                    {
                    case 1:
                        print_code(a[i].a);
                        break;
                    case 2:
                        print_name(a[i].a);
                        break;
                    case 3:
                        print_acc_type(a[i].a);
                        break;
                    case 4:
                        print_amount(a[i].a);
                        break;
                    case 5:
                        print_adress(a[i].a);
                        break;
                    case 6:
                        print_email(a[i].a);
                        break;   
                    default:
                        cout<<"No valid input given";
                        break;
                    }
                }
            }
        }  
        break;
    case 3:
        cout<<"Search an entry to delete it? ";
        delete_entry(search_delete(a));
        break;
    case 4:
        cout<<"Search entry to edit?\n";
        edit(search_delete(a));
        break;
    case 5:
        cout<<"Search?\n";
        search(a);
        break;
    case 6:
        sort(a);
        break;
    case 0:
        cout<<"Exited!";
        break;
    default:
        break;
    }
    return temp;
}



// Some things i couldn't place in functions and classes.
int main(){
    int n;
    cout<<"Enter the number of employees: ";
    cin>>n;
    emp SBI[n];
    while(true){
        cout<<"Enter the number of action you want to do: ";
        int a=action(SBI);
        if(a==0){
            break;
        }
    }
}