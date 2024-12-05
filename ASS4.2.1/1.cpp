
#include <iostream>
#include <cmath>
using namespace std;
#define MAXN 100

struct NODE
{
    float info;
    NODE *pNext;
};

NODE *CreateNode(float x)
{
    NODE *p = new NODE;
    p->info = x;
    p->pNext = NULL;
    return p;
}
struct stack
{
    NODE *top;
};
bool empty(const stack &s)
{
    return (s.top == NULL);
}
void CreateEmptyStack(stack &s)
{
    s.top = NULL;
}
void push(stack &s, float x)
{
    NODE *p = CreateNode(x);
    if (s.top == NULL)
        s.top = p;
    else
    {
        p->pNext = s.top;
        s.top = p;
    }
}
void pop(stack &s)
{
    if (s.top == NULL)
        return;
    NODE *p = s.top;
    s.top = s.top->pNext;
    delete p;
}
float &top(stack s)
{
    return s.top->info;
}
bool isOperator(char x)
{
    return ((x == '-') || (x == '+') || (x == '*') || (x == '/') || (x == '^'));
}
bool isBracket(char x)
{
    return ((x == '(') || (x == ')'));
}
void InputPostFix(char postix[], int &n)
{
    char k;
    cin >> k;
    n = 0;
    while (k != '#')
    {
        postix[n++] = k;
        cin >> k;
    }
}
float evaluate_expression(char postix[], int n)
{
    stack s;
    for (int i = 0; i < n; i++)
    {
        if (postix[i] <= '9' && postix[i] >= '0')
            push(s, postix[i] - '0');
        if (isOperator(postix[i]) == 1)
        {
            float z;
            float x = top(s);
            pop(s);
            float y = top(s);
            pop(s);
            if (postix[i] == '+')
                z = x + y;
            if (postix[i] == '-')
                z = y - x;
            if (postix[i] == '*')
                z = y * x;
            if (postix[i] == '/')
                z = y / x;
            if (postix[i] == '^')
                z = pow(y, x);
            push(s, z);
        }
    }
    return top(s);
}
int main()
{
    char postfix[MAXN];
    int np;

    InputPostFix(postfix, np);
    // Output(postfix, np);

    cout.precision(3);
    cout << evaluate_expression(postfix, np);

    return 0;
}
