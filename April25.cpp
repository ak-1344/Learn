#include <iostream>
using namespace std;

template<typename T>
class Stack {
    private:
        int top;
        int maxSize;
        T *stackPtr;
    
    public:
        Stack(int size) {
            maxSize=size;
            stackPtr=new T[maxSize];
            top=-1;
        }
    
        ~Stack() {
            delete[] stackPtr;
        }
    
        bool isEmpty() {
            return top==-1;
        }
    
        bool isFull() {
            return top==maxSize-1;
        }
    
        void push(T value) {
            if(isFull()) {
                cout<<"Stack overflow"<<endl;
            }
            else {
                top++;
                stackPtr[top]=value;
            }
        }
    
        void pop() {
            if(isEmpty()) {
                cout<<"Stack underflow"<<endl;
            }
            else {
                top--;
            }
        }
    
        void display() {
            if(isEmpty()) {
                cout<<"Stack is empty"<<endl;
            }
            else {
                for(int i=0; i<=top; i++) {
                    cout<<stackPtr[i]<<" ";
                }
                cout<<endl;
            }
        }
    
        T peek() {
            if(isEmpty()) {
                cout<<"Stack is empty"<<endl;
                return -1;
            }
            else {
                return stackPtr[top];
            }
        }
};

int main() {
    Stack<int> intStack(5);
    Stack<char> charStack(5);
    int option;
    
    do {
        cout<<endl<<endl;
        cout<<"Select an option:"<<endl;
        cout<<"1. Push"<<endl;
        cout<<"2. Pop"<<endl;
        cout<<"3. Display"<<endl;
        cout<<"4. Peek"<<endl;
        cout<<"5. Exit"<<endl;
        cout<<"Option: ";
        cin>>option;
        
        switch(option) {
            case 1: {
                int value;
                cout<<"Enter value to push: ";
                cin>>value;
                intStack.push(value);
                break;
            }
            case 2: {
                int temp= intStack.peek();
                intStack.pop();
                cout<<"Element popped: "<<temp;
                break;
            }
            case 3: {
                intStack.display();
                break;
            }
            case 4: {
                cout<<"Top element of int stack: "<<intStack.peek()<<endl;
                break;
            }
            case 5: {
                cout<<"Exiting..."<<endl;
                break;
            }
            default: {
                cout<<"Invalid option"<<endl;
                break;
            }
        }
    } while(option!=5);
    
    return 0;
}