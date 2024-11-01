
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

NODE* CreateNode(int x) {
	NODE* p;
	p = new NODE;
	//if (p == NULL)
    //		exit(1);

	p->info = x;
	p->pNext = NULL;
	return p;
}
void AddTail(LIST &L, NODE* p) {
	if (L.pHead == NULL) {
		L.pHead = p;
		L.pTail = L.pHead;
	}
	else {
		L.pTail->pNext = p;
		L.pTail=p;
    }
}

void CreateEmptyList(LIST &L) {
	L.pHead = NULL;
	L.pTail = NULL;
}
void CreateList(LIST &L) {
	NODE* p;
	int x, n;
    cin >> n; // Số lượng phần tử của danh sách
	while (n-->0) {
		cin >> x;
		p = CreateNode(x);
		AddTail(L, p);
	}
}


int length(NODE *p){
    int i=0;
    while (p) {
        i++;
        p = p->pNext;
    }
    return i;
}

void PrintList(NODE* p) {
	if (p == NULL)
		cout << "Empty List.";
	else {
        // cout << boolalpha << is_ascending(p) << endl;
        cout << length(p) << endl;
		while (p) {
			cout << p->info << " ";
			p = p->pNext;
		}
	}
}

void PushElementToList(LIST &proto, NODE *p)
{
    if (proto.pHead == nullptr && proto.pTail == nullptr)
    {
        proto.pHead = p;
        proto.pTail = p;
    }
    else
    {
        (proto.pTail)->pNext = p;
        proto.pTail = p;
    }
}

void Partition(LIST &L, LIST &L1, NODE *&pivot, LIST &L2)
{
    pivot = L.pHead;
    L.pHead = (L.pHead)->pNext;
    pivot->pNext = nullptr; 
    while(L.pHead != nullptr)
    {
        NODE* temp = L.pHead;
        L.pHead = L.pHead->pNext;
        temp->pNext = nullptr; 
        if (temp->info <= pivot->info)
        {
            PushElementToList(L1, temp);
        }
        else
        {
            PushElementToList(L2, temp);
        }
    }
}


void quicksort_ascending(LIST &L) {
    if (L.pHead == NULL || L.pHead->pNext == NULL) {
        return; 
    }

    LIST L1, L2;
    CreateEmptyList(L1);
    CreateEmptyList(L2);

    NODE* pivot = NULL;
    Partition(L, L1, pivot, L2); 

   
    quicksort_ascending(L1);
    quicksort_ascending(L2);

 
    if (L1.pHead == NULL) {
        L.pHead = pivot; 
    } else {
        L.pHead = L1.pHead; 
        L1.pTail->pNext = pivot; 
    }

    pivot->pNext = L2.pHead; 
    L.pTail = (L2.pTail != NULL) ? L2.pTail : pivot; 
}
int main() {
    LIST L;
	CreateEmptyList(L);

	CreateList(L);
    quicksort_ascending(L);
    PrintList(L.pHead);

    return 0;
}
