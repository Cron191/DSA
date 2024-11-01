
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
    NODE* p=new NODE();
    p->info=x;
    p->pNext=NULL;
    return p;
}
void AddTail(LIST& l, NODE* p)
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
    while(cin)
    {
        int x;
        cin>>x;
        if(x==-1) break;
        else 
        {
            NODE* p=CreateNode(x);
            AddTail(l,p);
        }
    }
}
void InsertTail(LIST &L, int x)
{
    NODE* p=CreateNode(x);
    if(L.pHead==NULL)
    {
        L.pHead=p;
        L.pTail=p;
    }
    else
    {
        L.pTail->pNext=p;
        L.pTail=p;
    }
}
void Partition(LIST &L, LIST &L1, NODE* &pivot, LIST &L2)
{
    pivot=L.pHead;
    L.pHead=L.pHead->pNext;
    while(L.pHead!=NULL)
    {
        if(L.pHead->info <= pivot->info) InsertTail(L1,L.pHead->info);
        else InsertTail(L2,L.pHead->info);
        L.pHead=L.pHead->pNext;
    }
}
void PrintList(LIST L)
{
    if(L.pHead==NULL) cout<<"Empty List.";
    while(L.pHead!=NULL)
    {
        cout<<L.pHead->info<<" ";
        L.pHead=L.pHead->pNext;
    }
    cout<<'\n';
}
int main() {
    LIST L, L1, L2;
	NODE *pivot;

	CreateEmptyList(L);
	CreateEmptyList(L1);
	CreateEmptyList(L2);
	CreateList(L);
	if(L.pHead==NULL) {
		cout << "Empty List.";
		return 0;
	}

	Partition(L, L1, pivot, L2);

	cout << pivot->info << endl;
	PrintList(L1);
	PrintList(L2);
	PrintList(L);

    return 0;
}


