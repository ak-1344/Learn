// Sort the sides of triangle according to their area.

#include <iostream>
#include <cmath>
using namespace std;

typedef class triangle{
    private:
        int s1,s2,s3,p; 
    public:
        double area;
        triangle(){
            cout<< "\nEnter the three sides of the triangle respectively: ";
            cin >> s1 >> s2 >> s3;
            p=s1+s2+s3;
            int s = p/2;
            area= sqrt(s*(s-s1)*(s-s2)*(s-s3));
        }
        void print(){
            cout<<s1<<" "<<s2<<" "<<s3<<"\n";
        }
}tri;
int main(){
    int n;
    cout<<"Enter the number of triangles: ";
    cin>>n;
    tri t[n];
// sorting.....    
    int i=0;
    while(i<n-1){
        if(t[i].area > t[i+1].area){
            tri temp = t[i+1];
            t[i+1] = t[i];
            t[i] = temp;
            i=-1;
        }
        i++;
    }

    for(int i=0;i<n;i++){
        t[i].print();
    }

}