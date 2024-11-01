#include <iostream>
using namespace std;
struct NODE 
{
	int info;
	NODE* pNext;
};
struct LIST 
{
	NODE* pHead;
	NODE* pTail;
};

NODE* CreateNode(int x) 
{
	NODE* p;
	p = new NODE;
	p->info = x;
	p->pNext = NULL;
	return p;
}

void CreateEmptyList(LIST &L) 
{
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
    while(n!=-1)
    {
		NODE* p=CreateNode(n);
		AddTail(l,p);
        cin>>n;
    }
}
int count_even(NODE* p)
{
    int cnt=0;
    while(p!=NULL)
    {
        if(p->info%2==0) cnt++;
        p=p->pNext;
    }
    return cnt;
}
int main() {
    LIST L;
	CreateEmptyList(L);

	CreateList(L);
    cout << count_even(L.pHead);

    return 0;
}

