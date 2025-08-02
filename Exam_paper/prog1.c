// A chocolate factory is packing chocolates into the packets. The chocolate packets here represent an array of N
// number of integer values. The task is to find the empty packets(0) of chocolate and push it to the end of the
// conveyor belt(array). (Time complexity O(n) and space compexity is O(1))

// Input:
// 8 - value of N
// [4,5,0,1,9,0,5,0] - Element of arr[0] to arr[N-1], while input each element is separated by newline.

// Output:
// 4 5 1 9 0 0 0

#include<stdio.h>

int main(){
    const int n = 8;                            //1
    int arr[n];                                 //8
    for (int i = 0; i < n; i++)                 //n
    {
        printf("Enter the number : ");
        scanf("%d",&arr[i]);
    }
    int zeros[n];                               //8
    int num[n];                                 //8
    int k = 0,l = 0;                            //2
    for (int i = 0; i < n; i++)                 //n
    {
        if(arr[i] == 0)
            zeros[k++] = arr[i];
        else
            num[l++] = arr[i];
    }
    for (int i = 0; i < l; i++)                 //n
        printf("%d ",num[i]);
    for (int i = 0; i < k; i++)                 //n
        printf("%d ",zeros[i]);
    return 0;                                   //1
}

// space complexity:
// 1+8+8+8+2+1
// =O(1)

// Time complexity:
// n+n+n+n
// =4n
// =O(n)