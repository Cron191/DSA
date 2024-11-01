/*  COMPARATOR
    // a trước b -> TRUE
    // b trước a -> FALSE
EX: sort(a, a+n, cmp);
bool cmp(int a, int b)
{
    if( a> b ) return 1;
    else return 0;
}
*/

/*
    ***TÌM KIẾM TUYẾN TÍNH
    find(a,a+n,x);
    -> trả về con trỏ
    + nếu không tìm thấy x trả về a+n
    + nếu tìm thấy x trả về !(a+n)
    EX:
    int * p= find(a,a+n,5);
    if( p = a+n) cout<<"Khong tim thay";
    else cout<<"Tim thay";

    
    ***TÌM KIẾM NHỊ PHÂN
    binary_search(a,a+n,x);
    -> trả về đúng, sai
    + có trả về SAI
    + không có trả về SAI


    *** LOWER_BOUND
    áp dụng mãng tăng dần
    -> trả về con trỏ vị trí phần tử nhỏ nhất đầu tiên >=X, nếu không tìm thấy trản về (a+n)||a.end()
    EX:
    int a[];
    int *p=lower_bound(a,a+n,x);


    ***UPPER_BOUND
    áp dụng mãng tăng dần
    -> trả về con trỏ vị trí phần tử đầu tiên >X, nếu không tìm thấy trản về (a+n)||a.end()
    EX:
    int a[];
    int *p=upper_bound(a,a+n,x);

*/