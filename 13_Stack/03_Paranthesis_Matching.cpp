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
int main()
{
    Stack<char> s1;
    string s;
    cin >> s;
    cout << s1.isMmatching(s);
}