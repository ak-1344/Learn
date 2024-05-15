#include <iostream>
using namespace std;

class employee{
    public:
        string emp_id,name;
        employee(){
            cout<<"Enter the emp id: ";
            cin>>emp_id;
            getchar();
            cout<<"Enter name: ";
            cin>>name;
        }
        void display(){
            cout<<"Name: "<<name<<endl;
            cout<<"Employee id: "<<emp_id<<endl;
        }
};

class Academic: public employee{
    public:
        int experience;
        Academic(){
            cout<<"Enter the academic experience: ";
            cin>>experience;
        }

};

class Research: public employee{
    public:
        int hindex;

        Research(){
            cout<<"Enter the value of hindex: ";
            cin>>hindex;
        }
};

class collaboration: public employee{
    public:
        int nou;
        collaboration(){
            cout<<"Enter the no of foriegn universities student worked: ";
            cin>>nou;
        }
};

class GradePoints: public Academic, public Research, public collaboration{
    public:
        int GP1,GP2,GP3;

        GradePoints(){
            if(experience<5){
                GP1=0;
            }else if(experience<=10){
                GP1=5;
            }else if(experience>10){
                GP1=10;
            }

            if(hindex>10){
                GP2=50;
            }else if(hindex>=5){
                GP2=25;
            }else if(hindex>=1){
                GP2=10;
            }else{
                GP2=0;
            }

            if(nou>10){
                GP3=25;
            }else if(nou>=5){
                GP3=10;
            }else if(nou>=1){
                GP3=5;
            }else{
                GP3=0;
            }
        }

        void display(){
            employee::display();
            cout<<"Experience: "<<experience<<endl;
            cout<<"Hindex :"<<hindex<<endl;
            cout<<"No. of foreign universities worked with: "<<nou<<endl;
        }
};

int main(){
    GradePoints obj;
    obj.display();
}