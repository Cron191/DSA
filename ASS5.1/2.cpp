
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

void InsertHashTable(HASHTABLE &H, int y)
{
    int j = 0;
    int index = HF(H, y);
    while (H.table[index].flag == OCCUPIED)
    {
        if (H.table[index].key == y)
            break;
        j++;
        index = HF_LinearProbing(H, y, j);
    }
    H.table[index].key = y;
    H.n++;
    H.table[index].flag = OCCUPIED;
}

void CreateHashTable(HASHTABLE &H)
{
    int n;
    H.n = 0;
    cin >> H.M >> n;
    H.table = new NODE[H.M];
    for (int i = 0; i < H.M; i++)
        H.table[i].flag = EMPTY;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        if (x == 1)
        {
            if ((float)H.n / H.M < LOAD)
                InsertHashTable(H, y);
        }
        else if (x == 0)
        {
            int cnt = 0;
            int index = HF(H, y);
            while (H.table[index].flag != EMPTY && H.table[index].key != y)
            {
                cnt++;
                index = HF_LinearProbing(H, y, cnt);
            }
            if (H.table[index].flag == OCCUPIED && H.table[index].key == y)
            {
                H.table[index].flag = DELETED;
                H.n--;
            }
        }
    }
}

void Traverse(HASHTABLE &H)
{
    for (int i = 0; i < H.M; i++)
    {
        cout << i << " --> ";
        if (H.table[i].flag == OCCUPIED)
            cout << H.table[i].key << endl;
        else if (H.table[i].flag == DELETED)
            cout << "DELETED\n";
        else if (H.table[i].flag == EMPTY)
            cout << "EMPTY\n";
    }
}
void DeleteHashtable(HASHTABLE &ht)
{
    delete[] ht.table;
    ht.table = NULL;
    ht.M = 0;
}
int main()
{
    HASHTABLE H;
    CreateHashTable(H);
    Traverse(H);
    DeleteHashtable(H);
    return 0;
}
