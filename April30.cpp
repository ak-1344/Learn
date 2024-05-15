#include <iostream>
#include <string>
using namespace std;

class Person{
    protected:
        string name;
        int age;
    public:
        Person(){}
        Person(string n, int a): name(n),age(a){}
        void display(){
            cout<<"Name: "<<name;
            cout<<"\nAge"<<age<<endl<<endl;
        }
};

class Child: public Person{
    public:
        Child(){}
        Child(string n,int a){
            name=n;
            age=a;            
        }
};

class Parent: public Person{
    public:
        static int numChildren;
        Parent(){}
        Parent(string a,int b){
            name=a;
            age=b;
        }
        Child addChild(string a,int b){
            numChildren++;
            Child bchcha(a,b);
            return bchcha;
        }
};

int Parent::numChildren =0;

class Grandfather: public Parent{
    public:
        Grandfather(){}
        Grandfather(string a,int b){
            name=a;
            age=b;
        }
};

class Grandmother: public Parent{
    public:
        Grandmother(){}
        Grandmother(string a,int b){
            name=a;
            age=b;
        }
};


int main(){
    Grandfather dada("Harish",65);
    Grandmother dadi("Sarita",60);
    Parent mummy("Kavita",30);
    Parent mama("Ramesh",40);
    Child mom;
    Child uncle;
    Child c1,c2,c3,c4,c5;

    c1=mama.addChild("Hitesh",25);
    c2=mama.addChild("Kamlesh",22);
    c3=mama.addChild("Sunita",21);

    c4=mummy.addChild("Prabha",20);
    c5=mummy.addChild("Satya",18);

    mom=dada.addChild("Ramesh",40);
    uncle=dada.addChild("Kavita",30);

    cout<<"Grandfather: \n";
    dada.display();
    cout<<"Grandmother: \n";
    dadi.display();

    cout<<"Parents: \n";
    mummy.display();
    mama.display();

    cout<<"Children of grandfathers: \n";
    mom.display();
    uncle.display();

    cout<<"Children of first child of grandfather: \n";
    c1.display();
    c2.display();
    c3.display();

    cout<<"Children of second child of grandfather: \n";
    c4.display();
    c5.display();

    cout<<"Total number of Children:  "<<Parent::numChildren;
}