#include <iostream>
using namespace std;
struct Node
{
    int info;
    Node* next;
};


struct LIST
{
    Node *pHead;
    Node *pTail;
};

void CreateEmptyList(LIST &L)
{
    L.pHead=NULL;
    L.pTail=NULL;
}
void AddHead(LIST &l,int x)
{
    Node* p=new Node;
    p->info=x;
    p->next=NULL;
    if(l.pHead==NULL) 
    {
        l.pHead=p;
        l.pTail=p;
    }
    else
    {
        p->next=l.pHead;
        l.pHead=p;
    }
}
void CreateList(LIST &L)
{
    while(cin)
    {
        int x;
        cin>>x;
        if(x==-1) break;
        else
        AddHead(L,x);
    }
}
int length(LIST L)
{
    int len=0;
    while(L.pHead!=NULL)
    {
        len++;
        L.pHead=L.pHead->next;
    }
    return len;
}
int main() {
    LIST L;
	CreateEmptyList(L);

	CreateList(L);

    cout << length(L);

    return 0;
}
