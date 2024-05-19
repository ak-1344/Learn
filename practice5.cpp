//{ Driver Code Starts
// Initial Template for C
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void valueEqualToIndex(int arr[], int n);

// } Driver Code Ends
// User function Template for C
void valueEqualToIndex(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == i + 1)
        {
            continue;
        }
        else
        {
            arr[i] = -1;
        }
    }
}

//{ Driver Code Starts.

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
        }
        valueEqualToIndex(arr, n);
        bool flag = false;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == -1)
                continue;
            flag = true;
            printf("%d ", arr[i]);
        }
        if (flag == false)
            printf("Not Found");
        printf("\n");
    }
}
// } Driver Code Ends