// last unclosed, first closed

// Solution:
// scan from left to right,if opening symbal,add it to a list;if closing symbol,remove last opening symbol in list
// 同消消乐，遇到匹配的右括号就从列表中移除之前的左括号，如果出现新的左括号就添加到列表中，在一切正常的结束后会得到一个空列表
// 注意到最先进来的符号最后出去，遵循first in last out,所以使用栈

#define __STRICT_ANSI__
#include <iostream>
#include <stack>
#include <string.h>
using namespace std;

bool ArePair(char opening, char closing)
{
    if(opening == '[' && closing == ']') return true;
    else if(opening == '{' && closing == '}') return true;
    else if(opening == '(' && closing == ')') return true;

    return false;
}

bool CheackParentheses(string C) // 用string s[]时，在比较时会报错类型比较不一样
{
    stack < char > S;
    for(int i = 0; i<C.length(); i++)
    {
        if(C[i] == '(' || C[i] == '{' || C[i] == '[')
        {
            S.push(C[i]);
        }
        else if(C[i] == ')' || C[i] == '}' || C[i] == ']')
        {
            if (S.empty() || !ArePair(S.top(), C[i])) //这里的C[i]是当前栈顶字符的下一个字符，所以.top()为openning，C[i]为closing
            {
                return false;
            }
            else
            {
                S.pop();
            }
        }
    }
    return S.empty() ? true:false;
}

int main()
{
    string expression;
    cout<<"Enter an expression:  ";
    cin>>expression;
    if(CheackParentheses(expression))
		cout<<"Balanced\n";
	else
		cout<<"Not Balanced\n";

}