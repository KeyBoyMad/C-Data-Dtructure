// implement of prefix and postfix manually

/*
  Evaluation Of postfix Expression in C++ 
  Input Postfix expression must be in a desired format. 
  Operands must be integers and there should be space in between two operands.
  Only '+'  ,  '-'  , '*' and '/'  operators are expected. 
*/

#define __STRICT_ANSI__
#include <iostream>
#include <string.h>
#include <stack>

using namespace std;

bool IsDigitNum(char c)
{
    if(c >= '0' && c <= '9') return true;
    return false;
}

bool IsOprator(char c) // 判别是否为运算符
{
    if(c == '+' || c == '-' || c == '*' || c == '/') return true;
    return false;
}

int PerformOperation(char c, int op1, int op2)  // 运算
{
    if(c == '+') return op1+op2;
    else if (c == '-') return op1-op2;
    else if (c == '*') return op1*op2;
    else if (c == '/') return op1/op2;

    else cout<<"Unexpected Error\n";
    return -1;
}

int EavaluatePostfix(string expression) //执行后缀表达式的运算
{
    stack < int > S; 
    for(int i = 0; i<expression.length(); i++)
    {
        if(expression[i] == ' ' || expression[i] == ',') continue;
        else if (IsOprator(expression[i]))
        {   
            char opration = expression[i];
            int op2 = S.top(); S.pop();
            int op1 = S.top(); S.pop();
            int result =  PerformOperation(opration, op1, op2);
            S.push(result);
        }
        else if(IsDigitNum(expression[i]))
        {
            int operand = 0;
            while(i<expression.length() && IsDigitNum(expression[i]))
            {
                operand = operand * 10 + (expression[i] - '0');
                i++;
            }
            i--;
            S.push(operand);
        } 
        
    }
    return S.top();
} 

int main()
{
    string expression = "2 3*1+";
    
    int result = EavaluatePostfix(expression);
    cout << result << endl;
}