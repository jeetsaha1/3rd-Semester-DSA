// Write a C program to find the palindrome using appropriate ADT to implement a more powerful version of the is_palindrome() function. As a reminder, this function implements simple palindome verification. Here is the signature and documentation for the function:
// bool is_palindrome(char *text)

// Return true if text is a palindrome, false otherwise. A palindrome is a string that is identical to itself when reversed. For example, "madam", "dad", and "abba" are palindromes. Note: the empty string is a palindrome, as is every string of length one.

// Your solution should ignore whitespace and punctuation, and all comparisons should be case-insensitive. Include some tests in your main function. Examples of valid palindromes:

// Example- "", "a", "aa", "aaa", "aba", "abba", "Taco cat", "Madam, I'm Adam", "A man, a plan, a canal: Panama", "Doc, note: I dissent. A fast never prevents a fatness. I diet on cod."

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct stack{
    int size;
    char *arr;
    int top;
};

int isFull(struct stack *ptr){
    if(ptr->top == ptr->size-1)
        return 1;
    return 0;
}

int isEmpty(struct stack *ptr){
    if(ptr->top == -1)
        return 1;
    return 0;
}

void push(struct stack *ptr,char val){
    if(isFull(ptr)){
        printf("Stack Overflow");
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}

char pop(struct stack *ptr){
    char val;
    if(isEmpty(ptr)){
        printf("Stack Underflow");
    }
    else{
        val = ptr->arr[ptr->top];
        ptr->top--;
    }
    return val;
}

int is_palindrome(char *str){
    struct stack *s = (struct stack*)malloc(sizeof(struct stack));
    s->top = -1;
    int len = strlen(str);
    s->size = len;
    s->arr = (char*)malloc(s->size * sizeof(char));

    for (int i = 0; i < len/2; i++)
    {
        push(s,str[i]);
    }
    int start = (len%2 == 0)?len/2:len/2 +1;
    for (int j = start; j<len ; j++)
    {
        if(str[j]!= pop(s)){
            free(s->arr);
            free(s);
            return 0;
        }
    }
    free(s->arr);
    free(s);
    return 1;
}

void test(char *str){
    if(is_palindrome(str)){
        printf("Palindrome");
    }
    else{
        printf("Not Palindrome");
    }
}

int main(){
    char *val;
    printf("Enter the string: ");
    scanf("%s",val);
    test(val);
    return 0;
}