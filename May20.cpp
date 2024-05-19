/*
Given a sorted array arr[] of positive integers. The task is to find the closest value in the array to the given number k.
The array may contain duplicate values.
Note: If the difference with k is the same for two values in the array return the greater value.
*/
#include <iostream>
#include <climits>
using namespace std;
class closest
{
public:
    static int findClosest(int arr[], int n, int k)
    {
        int min_diff = INT_MAX;
        int closest_val = 0;
        for (int i = 0; i < n; i++)
        {
            int diff = abs(arr[i] - k);
            if (diff <= min_diff)
            {
                min_diff = diff;
                closest_val = arr[i];
            }
        }
        return closest_val;
    }
};

int main()
{
    int n;
    int flag = 1;
    while (flag == 1)
    {
        cout << "Enter the number of elements in the array: ";
        cin >> n;
        if(n<=105){
            flag=0;
        }else{
            cout<<"Invalid Input!!\nEnter the value of n within 106.\n";
        }
    }
    
    int arr[n];
    cout << "Enter " << n << " number of elements of array in sorted order: \n";
    int i = 0;
    while (i < n)
    {
        cout << "Enter " << i + 1 << " element of the array: ";
        cin >> arr[i];
        if (arr[i] > 106)
        {
            cout << "Element greater than 106,\nNot Valid!!\nTry again: ";
            i--;
        }
        i++;
    }

    int k;
    cout << "Enter the value of k: ";
    cin >> k;

    closest c;
    cout <<"Closest value to "<<k<<" in the given array is: "<<c.findClosest(arr, n, k) << endl;
    return 0;
}