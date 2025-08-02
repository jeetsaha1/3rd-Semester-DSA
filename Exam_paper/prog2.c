// In an AI robotics lab, every robot assistant is assigned a power calibration level
// before being activated. These levels follow a hybrid mathematical pattern. At odd- 
// numbered calibration steps and at even-numbered calibration steps, the power level 
// is derived from different series like:
//             2,2,3,4,5,7,8,9,11,13,12,17,14,19,16.........
// The calibration levels are used for internal adjustment only, so dduplicates are 
// allowed. Your task is to determine the power level assigned at that steps for given 
// calibration step number N, N can be (1<= N <= 100)

// Input:
// 9 - Value of N

// Output:
// 11

// Input:
// 11 - Value of N

// Output:
// 13

#include <stdio.h>

int next_prime(int val) {
    int num = val;
    while (1) {
        int isPrime = 1;
        for (int i = 2; i * i <= num; i++) {
            if (num % i == 0) {
                isPrime = 0;
                break;
            }
        }
        if (isPrime) return num;
        num++;
    }
}

int next_even(int val) {
    if (val % 2 == 0)
        return val;
    else
        return val + 1;
}

int main() {
    int prime_val = 2;
    int even_val = 2;
    int list[100]={0};
    int k=0;
    for (int i = 1; i <= 100; i++) {
        if (i % 2 == 0) {
            list[k++] = even_val+1;
            even_val += 2;
        } else {
            list[k++] = prime_val+1;
            prime_val = next_prime(prime_val + 1);
        }
    }
    int n;
    printf("Enter the number : ");
    scanf("%d",&n);
    for (int i = 0; i < 100; i++)
    {
        if(i == n){
            printf("%d",list[i]);
        }
    }
    
    return 0;
}
