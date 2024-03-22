#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(string s) {
        string a="";
        for(int i=0;i<s.length();i++){
            if(s[i]>='A' && s[i]<='Z'){
                a+=s[i]-'A'+'a';
            }else if(s[i]>='a' && s[i]<='z'){
                a+=s[i];
            }else if(s[i]>='0' && s[i]<='9'){
                a+=s[i];
            }
        }
        string b="";
        for(int i=a.length()-1; i>=0; i--){
            b+=a[i];
        }
        
        if(a.compare(b)==0){
            return true;
        }else{
            return false;
        }
}

int main(){
    string str;
    cout<<"Enter the string: ";
    getline(cin,str);
    if(isPalindrome(str)){
        cout<<"The given string is palindrome";
    }else{
        cout<<"Not a palindrome";
    }
}