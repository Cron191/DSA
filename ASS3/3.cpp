
#include <iostream>
using namespace std;

// Cấu trúc của một node
struct NODE {
	int info;
	NODE* pNext;
};
// Cấu trúc của một DSLK
struct LIST {
	NODE* pHead;
	NODE* pTail;
};
void CreateEmptyList(LIST &l)
{
    l.pHead=NULL;
    l.pTail=NULL;  
}
NODE* CreateNode(int x)
{
    NODE* p= new NODE();
    p->info=x;
    p->pNext=NULL;
    return p;
}
void AddTail(LIST &l, NODE* p)
{
    if(l.pHead==NULL)
    {
        l.pHead=p;
        l.pTail=p;
    }
    else
    {
        l.pTail->pNext=p;
        l.pTail=p;
    }
}
void CreateList(LIST &l)
{
    int x;
    int y;
    cin>>x;
    while(x!=-1)
    {
        if(y==x) 
        {
            cin>>x;
        }
        else
        {
            y=x;
            NODE* p=CreateNode(x);
            AddTail(l,p);
            cin>>x;
        }
    }
}

bool isSorted(NODE* p)
{
    if(p==NULL) return 0;
    if(p->pNext==NULL) return 0;
    while(p->pNext!=NULL)
    {
        if(p->info>p->pNext->info) return 0;
        p=p->pNext;
    }
    return 1;
}
int main() {
    LIST *L=new LIST;

	CreateEmptyList(*L);
	CreateList(*L);
	cout <<boolalpha << isSorted(L->pHead);
    return 0;
}
