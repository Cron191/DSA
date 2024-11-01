#include <iostream>
using namespace std;
struct NODE
{
    int info;
    NODE* pNext;
};
struct stack
{
    NODE* pHead;
};
bool isEmpty(stack &s)
{
    if(s.pHead==NULL) return 1;
    return 0;
}
void push(stack &s, NODE* p)
{
    if(isEmpty(s))
    {
        s.pHead=p;
    }
    else
    {
        p->pNext=s.pHead;
        s.pHead=p;
    }
}
bool pop(stack &s, int &x)
{
    NODE* p;
    if(isEmpty(s)) return 0;
    else
    {
        p=s.pHead;
        x=p->info;
        s.pHead=s.pHead->pNext;
        return 1;
    }

}
NODE* createNODE(int x)
{
    NODE* p= new NODE;
    p->info=x;
    p->pNext=NULL;
    return p;
}
void Testing_Push_Pop_Top_Stack(stack s)
{
    cout<<"output: ";
    int x;
    cin>>x;
    while(x!=-1)
    {
        if(x==0)
        {
            if(!isEmpty(s))  
            {
            int a;
            pop(s,a);
            cout<<a<<" ";
            }
        }
        else 
        {
            NODE* p = createNODE(x);
            push(s,p);
        }
        cin>>x;
    }
    if(isEmpty(s))cout<<'\n'<<"top: ";
    else 
    cout<<'\n'<<"top: "<<s.pHead->info;
}
int main() {
    stack s;
	Testing_Push_Pop_Top_Stack(s);
    return 0;
}