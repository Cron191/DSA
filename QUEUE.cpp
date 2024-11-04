#include <iostream>
using namespace std;

struct NODE
{
    int info;
    NODE *pNext;
};

struct QUEUE
{
    NODE *Front;
    NODE *Back;
};

NODE *CreateNODE(int x)
{
    NODE *p = new NODE();
    p->info = x;
    p->pNext = NULL;
    return p;
}
void CreateEmptyQueue(QUEUE &q)
{
    q.Front = NULL;
    q.Back = NULL;
}
bool isEmpty(QUEUE &q)
{
    if (q.Front == NULL)
        return 1;
    return 0;
}

void DeQueue(QUEUE &q)
{
    if (!isEmpty(q))
    {
        if (q.Front->pNext == NULL)
        {
            q.Back = NULL;
            q.Front = NULL;
        }
        else
        {
            NODE *p = q.Front;
            q.Front = q.Front->pNext;
            delete p;
        }
    }
}
void EnQueue(QUEUE &q, int x)
{
    NODE *p = CreateNODE(x);
    if (isEmpty(q))
    {
        q.Front = p;
        q.Back = p;
    }
    else
    {
        q.Back->pNext = p;
        q.Back = p;
    }
}
int TopQueue(QUEUE &q)
{
<<<<<<< HEAD
    if (!isEmpty(q))
        return q.Front->info;
=======
    if(!isEmpty(q)) return q.Front->info;
>>>>>>> 3c496e49afdb9b2a6dd8d5a495fbd4c1f664de08
}
int main()
{
    QUEUE q;
}