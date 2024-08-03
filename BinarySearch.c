/*
Imagine you are working as a librarian in a large library. The library uses an automated system to keep track of book positions on the shelves. Each book is assigned a unique ID, but some IDs are more common than others due to the popularity of certain editions.



The system logs the positions of books in a sorted list based on their IDs. You need to find the first and last positions of a specific book ID in this sorted list using binary search.



Example



Input:

10 

1 2 2 2 2 3 4 8 8 8 

8 

Output:

7 9

Explanation:

The first and last positions of book ID 8 are [7, 9] since the index is 0-based.



Company Tags: Amazon and Microsoft

Input format :
The first line of input consists of an integer n, representing the total number of book IDs.

The second line consists of a sorted list of n integers representing the book IDs.

The third line consists of an integer x, representing the specific book ID to find.

Output format :
The output displays indexes of the first and last occurrence of x, separated by a space.

If book ID x is not present in the shelves, print "NO OCCURRENCES".



Refer to the sample output for formatting specifications.

Code constraints :
1 ≤ n ≤ 20

1 ≤ book ID, x ≤ 100

Sample test cases :
Input 1 :
10 
1 2 2 2 2 3 4 8 8 8 
8
Output 1 :
7 9
Input 2 :
10 
1 2 2 2 2 3 4 8 8 8 
5
Output 2 :
NO OCCURRENCES
*/



// You are using GCC
#include <stdio.h>
int binary_search(int arr[],int left, int right, int target){
    if(left<=right){
        int mid = (right+left)/2;
        
        if(arr[mid]==target){
            return mid;
        }
        if(target<arr[mid]){
            return binary_search(arr,left,mid-1,target);
        }
        if(target>arr[mid]){
            return binary_search(arr,mid+1,right,target);
        }
    }
    return -1;
}


int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int target;
    scanf("%d",&target);
    int pos = binary_search(arr,0,n-1,target);
    
    if(pos==-1){
        printf("NO OCCURRENCES");
        return 0;
    }
    
    int start,end;
    
    for(int i=pos; arr[i]==target && i>=0;i--){
        start=i;
    }
    for(int i=pos; arr[i]==target && i<=n-1;i++){
        end=i;
    }
    
    printf("%d %d",start,end);
    return 0;
}