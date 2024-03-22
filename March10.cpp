#include <iostream>
#include <string>
#include <conio.h>
using namespace std;
class solution{
    private:
        string a,s1,s2;
    public:
        solution(){
            getline(cin,a);
            cin>>s1>>s2;
        }
        void replace(){
            string A=a;
            A.replace(A.find(s1),s1.length(),s2);
            cout<<endl<<A<<endl;
        }
        void insert(){
            string A=a;
            A.insert(A.length(),s1);
            A.insert(A.length(),s2);
            cout<<endl<<A<<endl;
        }
        void erase(){
            string A=a;
            A.erase(A.find(s1),s1.length());
            cout<<endl<<A<<endl;
        }

};
int main(){
    system("cls");
    solution a;
    system("cls");
    a.replace();
    a.insert();
    a.erase();
}