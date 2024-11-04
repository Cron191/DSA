#include <iostream>
using namespace std;

struct NODE
{
    int info;
    NODE *pNext;
};
struct queue
{
    NODE *front;
    NODE *back;
};
NODE *CreatNode(int x)
{
    NODE *p = new NODE;
    p->info = x;
    p->pNext = NULL;
    return p;
}
bool isEmpty(queue &q)
{
    if (q.front == NULL)
        return 1;
    return 0;
}
void Dequeue(queue &q)
{
    if (!isEmpty(q))
    {
        if (q.front->pNext == NULL)
        {
            q.back = NULL;
            q.front = NULL;
        }
        else
        {
            NODE *p = q.front;
            q.front = q.front->pNext;
            delete p;
        }
    }
}
NODE *CreateNODE(int x)
{
    NODE *p = new NODE();
    p->info = x;
    p->pNext = NULL;
    return p;
}
void Enqueue(queue &q, int x)
{
    NODE *p = CreateNODE(x);
    if (isEmpty(q))
    {
        q.front = p;
        q.back = p;
    }
    else
    {
        q.back->pNext = p;
        q.back = p;
    }
}
void CreateEmptyQueue(queue &q)
{
    q.front = NULL;
    q.back = NULL;
}
int Front(queue &q)
{
    return q.front->info;
}

int Back(queue &q)
{
    return q.back->info;
}

void createQueue(queue &q)
{
    CreateEmptyQueue(q);
    cout << "output: ";
    int x;
    cin >> x;
    while (x != -1)
    {
        if (x != 0)
            Enqueue(q, x);
        else
        {
            if (!isEmpty(q))
            {
                cout << Front(q) << " ";
                Dequeue(q);
            }
        }
        cin >> x;
    }
    cout << "\nfront: ";
    if (!isEmpty(q))
        cout << Front(q);
    cout << "\nback: ";
    if (!isEmpty(q))
        cout << Back(q);
    ;
}
int main()
{
    queue q;
    createQueue(q);
    return 0;
}
