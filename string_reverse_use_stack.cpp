#define __STRICT_ANSI__
#include<iostream>
#include <stack>
#include <string.h>
using namespace std;

// class stack
// {
//     private:
//         char A[101];
//         int top;

//     public:
//         void Push(int x);
//         void Pop();
//         int Top();
//         bool IsEmpty();
// };
void Reverse(char c[], int n)
{
    stack<char>S;
    // loop for push
    for(int i = 0; i<n; i++)
    {
        S.push(c[i]);
    }
    // loop for pop
    for(int i = 0; i<n; i++)
    {
        c[i] = S.top(); // overwrite the character at index i.
        S.pop();
    }
}

int main()
{
    char C[51];
    printf("Enter a string:");
    gets(C);
    Reverse(C, strlen(C));
    printf("output: %s\n", C);
}