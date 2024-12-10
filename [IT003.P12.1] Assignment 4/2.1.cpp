
#include <iostream>
#include <string>

using namespace std;

#define LOAD 0.7
#define EMPTY 0
#define DELETED -1
#define OCCUPIED 1

struct NODE {
    int flag; // Lưu trạng thái của NODE: -1:DELETE, 0:EMPTY, Giá trị khác: Node đang tồn tại giá trị
    int key;
};

struct HASHTABLE {
    int M; // Kich thuoc bang bam
    int n; // so phan tu hien tai trong bang bam
    NODE *table;
};

int HF(HASHTABLE ht, int key) { return key % ht.M; }

int HF_LinearProbing(HASHTABLE ht, int key, int i) {
    int h=HF(ht, key);
    return (h + i) % ht.M;
}
//###INSERT CODE HERE -
void Insert(HASHTABLE &H, int b)
{
    int index = HF(H, b);
    int j = 0;
    while (H.table[index].flag == OCCUPIED)
    {
        if (H.table[index].key == b)
            break;
        j++;
        index = HF_LinearProbing(H, b, j);
    }
    H.table[index].key = b;
    H.table[index].flag = OCCUPIED;
    H.n++;
}
void CreateHashTable(HASHTABLE &H)
{
    cin >> H.M;
    H.n = 0;
    int alteration_count = 0;
    cin >> alteration_count;
    H.table = new NODE[H.M];
    for (int i = 0; i < H.M; i++)
    {
        H.table[i].flag = EMPTY;
    }
    for (int i = 0; i < alteration_count; i++)
    {
        int a = 0, b = 0;
        cin >> a >> b;
        if (a == 1)
        {
            if (H.n >= H.M * LOAD)
                continue;
            Insert(H, b);
        }
        else if (a == 0)
        {
            int index = HF(H, b);
            int j = 0;
            while (H.table[index].flag != EMPTY && H.table[index].key != b)
            {
                j++;
                index = HF_LinearProbing(H, b, j);
            }
            if (H.table[index].flag == OCCUPIED && H.table[index].key == b)
            {
                H.table[index].flag = DELETED;
                H.n--;
            }
        }
    }
}

void Traverse(HASHTABLE H)
{
    for (int i = 0; i < H.M; i++)
    {
        cout << i;
        cout << " --> ";
        if (H.table[i].flag == OCCUPIED)
        {
            cout << H.table[i].key;
            cout << endl;
        }
        else if (H.table[i].flag == DELETED)
        {
            cout << "DELETED";
            cout << endl;
        }
        else
        {
            cout << "EMPTY";
            cout << endl;
        }

    }
}
void DeleteHashtable(HASHTABLE &ht) {
    delete [] ht.table;
    ht.table = NULL;
    ht.M = 0;
}

int main(){
    HASHTABLE H;
    CreateHashTable(H);
    Traverse(H);
    DeleteHashtable(H);
    return 0;
}