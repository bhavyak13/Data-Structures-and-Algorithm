#include <bits/stdc++.h>
using namespace std;

template <class T>
struct node
{
    T data;
    struct node<T> *next;
};
template <class T>

class Stack

{
private:
    struct node<T> *top = NULL;

public:
    void Push(T x);
    int Pop(void);
    int peek(int index);
    int stacktop(void);
    bool isempty(void);
    bool isfull(void);
    bool ismatching(string s);
    bool isMmatching(string s);
    string Convert(string infix);
    int evaluate(string infix);
};

template <class T>
void Stack<T>::Push(T x)
{
    struct node<T> *tem = new node<T>;
    tem->data = x;
    tem->next = NULL;
    if (top != NULL)
        tem->next = top;
    top = tem;
}
template <class T>
int Stack<T>::Pop(void)
{
    T x = -1;
    if (top != NULL)
    {
        struct node<T> *tem = top;
        x = top->data;
        top = top->next;
        delete tem;
    }
    else
    {
        cout << "Stack Underflow!\n";
    }
    return x;
}
template <class T>
int Stack<T>::peek(int index)
{
    if (top == NULL)
        return -1;
    struct node<T> *temp = top;
    for (int i = 0; i < index - 1; i++)
    {
        temp = temp->next;
        if (temp == NULL)
            return -1;
    }
    return temp->data;
}
template <class T>
int Stack<T>::stacktop(void)
{
    if (top != NULL)
    {
        return top->data;
    }
    return -1;
}
template <class T>
bool Stack<T>::isempty(void)
{
    if (top != NULL)
        return false;
    return true;
}
template <class T>
bool Stack<T>::isfull(void)
{
    struct node<T> *t = new node<T>;
    if (t)
    {
        delete t;
        return false;
    }
    return true;
}
template <class T>
bool Stack<T>::ismatching(string s)
{
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
            Push(1);
        else if (s[i] == ')')
        {
            if (isempty())
                return 0;
            Pop();
        }
    }
    if (isempty())
        return 1;
    return 0;
}
template <class T>
bool Stack<T>::isMmatching(string s)
{
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{')
            Push(s[i]);
        else if (s[i] == ')' || s[i] == ']' || s[i] == '}')
        {
            if (isempty())
                return false;
            T z = Pop();
            if (s[i] == ')')
            {
                if (z == '(')
                    continue;
                else
                    return false;
            }
            else if (s[i] == ']')
            {
                if (z == '[')
                    continue;
                else
                    return false;
            }
            else if (s[i] == '}')
            {
                if (z == '{')
                    continue;
                else
                    return false;
            }
        }
    }
    if (isempty())
        return true;
    return false;
}
bool isoperand(char x)
{
    if (x == '+' || x == '-' || x == '*' || x == '/' || x == ')' || x == '(' || x == '^')
        return false;
    return true;
}
int outpre(char x)
{
    if (x == '+' || x == '-')
        return 1;
    else if (x == '*' || x == '/')
        return 3;
    else if (x == '^')
        return 6;
    else if (x == '(')
        return 7;
    else if (x == ')')
        return 0;
    return 0;
}
int inpre(char x)
{
    if (x == '+' || x == '-')
        return 2;
    else if (x == '*' || x == '/')
        return 4;
    else if (x == '^')
        return 5;
    else if (x == '(')
        return 0;
    return 0;
}
template <class T>
string Stack<T>::Convert(string infix)
{
    // ((a+b)*c)-d^e^f
    string postfix;
    for (int i = 0; i < infix.length(); i++)
    {
        if (isoperand(infix[i]))
            postfix += infix[i];
        else
        {
            if (top == NULL || (outpre(infix[i]) > inpre(stacktop())))
            {
                Push(infix[i]);
            }
            else
            {
                while (!isempty() && outpre(infix[i]) < inpre(stacktop()))
                {
                    postfix += Pop();
                }
                if (outpre(infix[i]) == inpre(stacktop()))
                {
                    Pop();
                    continue;
                }
                Push(infix[i]);
            }
        }
    }
    while (!isempty())
    {
        postfix += Pop();
    }
    return postfix;
}
template <class T>
int Stack<T>::evaluate(string postfix)
{
    for (int i = 0; i < postfix.length(); i++)
    {
        if (isoperand(postfix[i]))
            Push(postfix[i] - 48);
        else
        {
            int x2 = Pop(), x1 = Pop(), r;
            switch (postfix[i])
            {
            case '+':
                r = x1 + x2;
                break;
            case '-':
                r = x1 - x2;
                break;
            case '*':
                r = x1 * x2;
                break;
            case '/':
                r = x1 / x2;
                break;
            }
            Push(r);
        }
    }
    return Pop();
}
int main()
{
    string s1;
    cin >> s1;
    Stack<char> s;
    string s2 = s.Convert(s1);
    cout << s2<<endl;
    cout << s.evaluate(s2);
}