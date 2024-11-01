
#include <iostream>
#include <cstdlib>
#include <ctime>
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

NODE* CreateNode(int x) {
	NODE* p;
	p = new NODE;
	//if (p == NULL)
    //		exit(1);

	p->info = x;
	p->pNext = NULL;
	return p;
}

void CreateEmptyList(LIST &L) {
	L.pHead = NULL;
	L.pTail = NULL;
}
void AddTail(LIST &l, NODE* p)
{
	if(l.pHead==NULL) 
    {
        l.pHead=p;
        l.pTail=l.pHead;
    }
    else 
    {
        l.pTail->pNext=p;
        l.pTail=p;
    }
}
void CreateList(LIST &l)
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
		int x;
        cin>>x;
		NODE* p=CreateNode(x);
		AddTail(l,p);
    }
}
NODE* SeparateHead(LIST &l)
{
	if(l.pHead==NULL) return NULL;
	NODE* p=l.pHead;
	l.pHead=l.pHead->pNext;
	return p;
}
void PrintList(NODE * p)
{	if(p==NULL) cout<<"Empty List.";
	else
	while(p!=NULL)
	{
		cout<<p->info<<" ";
		p=p->pNext;
	}
}
int main() {
    LIST L;
	CreateEmptyList(L);

	CreateList(L);
    NODE*p=SeparateHead(L);
	if( p!=NULL) cout << p->info << endl;
    PrintList(L.pHead);
    return 0;
}
