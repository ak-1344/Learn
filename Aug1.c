/*
Problem Statement
Uma is passionate about exploring different countries and their unique characteristics. She recently obtained a sorted list of country names and wanted to create a program to find the index of a given country in the list.
Knowing about binary search, she reached out to you for assistance in implementing this efficient search algorithm. 
Can you help Uma achieve her goal?

Input format :
The first line of input consists of an integer n, representing the number of countries in the list.
The second line consists of n space-separated strings, representing the names of n countries.
The third line consists of a string t, representing the country name Uma wants to find in the list.

Output format :
If the target country is found in the list, print "The country [t] is found at index [x]." where t is the target country name and x is its index (0-based) position.
If the target country is not found, print "[t] is not found." where t is the target country name.

Refer to the sample output for formatting specifications.
Code constraints :
1 ≤ n ≤ 8
The country names are case-sensitive.
Sample test cases :
Input 1 :
5
Canada India Japan Spain UK
India
Output 1 :
The country India is found at index 1.
Input 2 :
5
Canada India Japan Spain UK
Germany
Output 2 :
Germany is not found.
Input 3 :
3
India Russia UK
russia
Output 3 :
russia is not found.
*/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int binary_search(char *arr[], int left, int right, char *f){
    if(right>=left){
        int mid = (right +left) /2;
        
        if(strcmp(arr[mid],f)==0){
            return mid;
        }
        if(strcmp(arr[mid],f)>0){
            return binary_search(arr,left,mid-1,f);
        }
        if(strcmp(arr[mid],f)<0){
            return binary_search(arr,mid+1,right,f);
        }
        
    }
    return -1;
    
}

int main(){
    int n;
    scanf("%d",&n);
    char *str[n];
    for(int i=0;i<n;i++){
        str[i] = (char *)malloc(20*sizeof(char));
        scanf("%s",str[i]);
    }
    char *find;
    scanf("%s",find);
    
    int pos = binary_search(str,0,n-1,find);
    
    if(pos==-1){
        printf("%s is not found.",find);
    }else{
        printf("The country %s is found at index %d.",find,pos);
    }
    
    
}