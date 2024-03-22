/*
14.   Create a class called 'Matrix' containing constructor that initializes the number of rows and the number of columns of a new Matrix object. The Matrix class has the following information:
1 - number of rows of matrix
2 - number of columns of matrix
3 - elements of matrix (You can use 2D vector)

The Matrix class has functions for each of the following:
1 - get the number of rows
2 - get the number of columns
3 - set the elements of the matrix at a given position (i,j)
4 - adding two matrices.
5 - multiplying the two matrices
You can assume that the dimensions are correct for the multiplication and addition.
*/

#include<iostream>
using namespace std;

class matrix{
    private:
        int rows,columns;
        int **a;
    public:
        matrix(){
            cout<<"Enter the number of rows and columns respecytively: ";
            cin>>rows>>columns;
            a = (int**)malloc(rows*sizeof(int*));
            cout<<"Enter the elements of the matrix: ";
            for(int i=0;i<rows;i++){
                a[i]=(int*)malloc(columns*sizeof(int));

                for(int j=0;j<columns;j++){
                    cin>>a[i][j];
                }
            }
        }
        matrix(int m,int n){
            rows=m;
            columns=n;
            a = (int**)malloc(rows*sizeof(int*));
            for(int i=0;i<rows;i++){
                a[i]=(int*)malloc(columns*sizeof(int));
            }
        }
        void get_rows(){
            cout<<rows<<endl;
        }
        void get_columns(){
            cout<<columns<<endl;
        }
        void print(){
            for(int i=0;i<rows;i++){
                for(int j=0;j<columns;j++){
                    cout<<a[i][j]<<" ";
                }
                cout<<endl;
            }
            cout<<endl;
        }
        void set_element(){
            cout<<"Enter position (eg. if 3rd row 5 columns, then 3,5): ";
            int i,j,n;
            cin>>i>>j;
            cout<<"Enter the replaced element: ";
            cin>>n;
            a[i-1][j-1]=n;
            cout<<"Elements set!";
        }
        matrix add(matrix b){
            matrix c(rows,columns);
            for(int i=0;i<rows;i++){
                for(int j=0;j<columns;j++){
                    c.a[i][j]= a[i][j]+b.a[i][j];
                }
            }
            return c;
        }
        matrix multiply(matrix b){
            matrix c(rows,b.columns);
            if(columns!= b.rows){
                cout<<"Matrix can not be multiplied.\nOutput consists garbage value!";
            }else{
                int i=0;
                for(int i=0;i<rows;i++){
                    for(int j=0;j<b.columns;j++){
                        c.a[i][j]=0;
                        for(int k=0;k<columns;k++){
                            c.a[i][j]+= a[i][j] * b.a[j][i];
                        }
                    }
                }
                return c;
            }
        }
};

int main(){
    matrix a,b,c;
    a.print();
    b.print();
    c.print();

    (a.add(b)).print();
    ((a.add(b)).add(c)).print();
    (a.multiply(b)).print();
}