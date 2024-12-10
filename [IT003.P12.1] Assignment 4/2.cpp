
#include <iostream>
#include <string>

using namespace std;

#define LOAD 0.7
#define EMPTY 0
#define DELETED -1
#define OCCUPIED 1

struct NODE
{
    int flag; // Lưu trạng thái của NODE: -1:DELETE, 0:EMPTY, Giá trị khác: Node đang tồn tại giá trị
    int key;
};

struct HASHTABLE
{
    int M; // Kich thuoc bang bam
    int n; // so phan tu hien tai trong bang bam
    NODE *table;
};

int HF(HASHTABLE ht, int key) { return key % ht.M; }

int HF_LinearProbing(HASHTABLE ht, int key, int i)
{
    int h = HF(ht, key);
    return (h + i) % ht.M;
}

void DeleteHashtable(HASHTABLE &ht)
{
    delete[] ht.table;
    ht.table = NULL;
    ht.M = 0;
}
bool LoadFactor(HASHTABLE H)
{
    return 1.0 * H.n / H.M > 0.7;
}

void Insert(HASHTABLE &H, int y)
{
    if (LoadFactor(H))
    {
        return;
    }
    int index = HF(H, y);
    if (H.table[index].flag == 0 )
    {
        H.table[index].key = y;
        H.table[index].flag = 1;
        H.n++;
        return;
    }
    else
    {
        while (H.table[index].flag == 1 && H.table[index].key == y)
            index = HF_LinearProbing(H, y, index);
        H.table[index].key = y;
        H.table[index].flag = 1;
        H.n++;
    }
}

void Delete(HASHTABLE &H, int y)
{
    H.n--;
    int index = HF(H, y);
    if (H.table[index].flag == 0)
        return;
    if (H.table[index].key == y)
    {
        H.table[index].flag = -1;
        return;
    }
    else
    {
        while (H.table[index].flag == 1 || H.table[index].flag == -1)
            index = HF_LinearProbing(H, y, index);
        if (H.table[index].key == y)
            H.table[index].flag = -1;
    }
}
void CreateHashTable(HASHTABLE &H)
{
    cin >> H.M;
    H.n = 0;
    H.table = new NODE[H.M];
    for (int i = 0; i < H.M; i++)
        H.table[i].flag = 0;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        if (x == 1)
        {
            Insert(H, y);
        }
        if (x == 0)
            Delete(H, y);
    }
}
void Traverse(HASHTABLE H)
{
    for (int i = 0; i < H.M; i++)
    {
        cout << i << " --> ";
        if (H.table[i].flag == 0)
            cout << "EMPTY" << endl;
        else if (H.table[i].flag == -1)
            cout << "DELETED" << endl;
        else if (H.table[i].flag == 1)
            cout << H.table[i].key << endl;
    }
}
int main()
{
    HASHTABLE H;
    CreateHashTable(H);
    Traverse(H);
    DeleteHashtable(H);
    return 0;
}
