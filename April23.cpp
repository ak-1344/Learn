#include <iostream>
#include <string>
using namespace std;

class Voter{
    private:
        string name;
        int age;
        bool voting__status;
    public:
        Voter(){}//Default constructor
        Voter(string a,int b): name(a), age(b) {}
        Voter(string a,int b, bool c): name(a), age(b), voting__status(c) {}

        friend void displayEligibleVoters(); 
};

void displayEligibleVoters(){
    cout<<"Enter the number of voters you need: ";
    int n; cin>>n;
    Voter obj[n];
    int count=0;
    string a[n];
    for(int i=0;i<n;i++){
        cout<<"Enter the name: ";
        cin>>obj[i].name;
        cout<<"Enter the age: ";
        cin>>obj[i].age;
        cout<<"Enter voting status (1/0 = yes/no)  : ";
        cin>>obj[i].voting__status;
        cout<<endl;

        if(obj[i].age>18 && !obj[i].voting__status){
            a[count]=obj[i].name;
            count++;
        }
    }

    for(int i=0;i<count;i++){
        cout<<"Name: "<<a[i]<<endl;
    }
    if(count==0){
        cout<<"No Voter is eligible.";
    }
}

int main(){
    displayEligibleVoters();
}