#include<bits/stdc++.h>
using namespace std;
struct List
{
    public:
    node pHead, pTail;
};
void CreatList(List &l)
{
    l.pHead=NULL;
    l.pTail=NULL;
}
void AddHead(List &l,node p)
{
    if(l.pHead==NULL) 
    {
        l.pHead=p;
        l.pTail=l.pHead;
    }
    else
    {
        p=l.pHead;
        l.pHead=p;
    }
}
void AddTail(List &l, node p)
{
    if(l.pHead==NULL) 
    {
        l.pHead=p;
        l.pTail=l.pHead;
    }
    else 
    {
        l.pTail->next=p;
        l.pTail=p;
    }
}
void InsertAffer(List &l, node p, node q)
{
    if(q!=NULL)
    {
        p->next=q->next;
        q->next=p;
        if(p==l.pTail) l.pTail=q;
    }
    else AddHead(l,p);
}
void RemoveHead(List & l)
{
    node p;
    if(l.pHead!=NULL)
    {
        p=l.pHead;
        l.pHead=l.pHead->next;
        delete(p);
        if(l.pHead==NULL) l.pTail=NULL;
    }
}
void RemoveAffterQ(List &l, node q)
{
    if(q!=NULL)
    {
        node p=q->next;
        if(p!=NULL) 
        {
            if(p==l.pTail) l.pTail=q;
            q->next=p->next;
            delete p;
        }
    }
}
struct NODE
{
    public:
    int data;
    NODE *next;
};

typedef struct NODE* node;



node makeNODE(int x)
{
    node tmp= new NODE();
    tmp->data=x;
    tmp->next= NULL;
    return tmp;
}
int sizeofNODE(node a)
{
    int cnt=0;
    while(a!=NULL)
    {
        a=a->next;
        ++cnt;
    }
    return 0;
}
bool emptyNODE(node a)
{
    return a==NULL;
}

void insertfirtNODE(node &a, int x)
{
    if(a==NULL) a=makeNODE(x);
    else 
    {
        node p=makeNODE(x);
        p->next=a;
        a=p;
    }
}
void insertlastNODE(node &a, int x)
{
    if( a== NULL) a=makeNODE(x);
    else
    {
        node p=a;
        while(p->next!=NULL) p=p->next;
        p->next=makeNODE(x);
    }
}
int  main()
{
    List l;
    CreatList(l);
    node a=NULL;
    a = makeNODE(1);
}