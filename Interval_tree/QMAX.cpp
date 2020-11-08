#include <iostream>
#include <vector>

using namespace std;

/*
class Node {
public:
    int lrange, rrange;
    //int value;
    int maxValue;
    Node *left, *right, *parent;
}
*/

void update(vector<int>& T, int id, int l, int r, int i, int k) {
    /*
    1. l..r khong chua index i
    l..r co chua index i
        2. 1 - l..r = i..i (chỉ chứa i) --> nút id là nút lá
        2. 2 - l..r        đoạn l..r dài hơn/chứa nhiều hơn 1 phần tử --> nút id không phải là nút lá
    */
    if (i < l || r < i) { // TH1
        return;
    }
    if (l == r) { // l == i --> TH 2.1
        T[id] = k;
        return;
    }
    // l <= i && i <= r --> TH 2.2
    int m = (l + r) / 2;
    update(T, id * 2,         l, m, i, k);
    update(T, id * 2 + 1, m + 1, r, i, k);
    T[id] = max(T[id * 2], T[id * 2 + 1]);
}

int getMax(vector<int>& T, int id, int l, int r, int u, int v) {
    /*
     * TH1. [u..v] và [l..r] không giao nhau --> không cần quan tâm đến nút id và tất cả nút con
     * TH2. [l..r] là con của [u..v] --> chỉ quan tâm đến nút id, không cần quan tâm các nút con của id
     * TH3. [u..v] và [l..r] có phần chung
     */
    if (l > r || v < l || r < u) { // l > r --> range không có thật, invalid, không hợp lệ
        return -1000000;
    }
    if (u <= l && r <= v) { // TH2
        return T[id];
    }
    // TH3
    int m = (l + r) / 2;
    return max(
        getMax(T, id * 2,         l, m, u, v),
        getMax(T, id * 2 + 1, m + 1, r, u, v)
    );
}

int main() {
    int n, m, p;
    cin >> n >> m;
    vector<int> a(n + 2, 0);
    vector<int> T(4 * n + 1, 0);
    for (int i = 0; i < m; ++ i) {
        int u, v, k;
        cin >> u >> v >> k;
        a[u] += k;
        a[v + 1] -= k;
    }
    for (int i = 1; i <= n; ++ i) {
        a[i] += a[i - 1];
    }
    
    for (int i = 1; i <= n; ++ i) {
        update(T, 1, 1, n, i, a[i]);
    }

    cin >> p;
    for (int i = 0; i < p; ++ i) {
        int u, v;
        cin >> u >> v;
        cout << getMax(T, 1, 1, n, u, v) << endl;
    }
    return 0;
}
/*
6
1 3 2
4 6 3
2 4 5
3 6 1

   1  2  3  4  5  6        1   2   3   4   5   6
   ----------------        ---------------------     
   2  2  2                 2          -2            
            3  3  3                    3          -3          
      5  5  5                  5          -5              
         1  1  1  1                1              -1     
   9  9  9  9  9  9        9                      -9
   9  9  9  9  9  9        9                      -9
   9  9  9  9  9  9        9                      -9
   9  9  9  9  9  9        9                      -9
   9  9  9  9  9  9        9                      -9
   9  9  9  9  9  9        9                      -9
   9  9  9  9  9  9        9                      -9
   9  9  9  9  9  9        9                      -9
   9  9  9  9  9  9        9                      -9
   9  9  9  9  9  9        9                      -9
   ----------------        ---------------------    
                           2   7   8   9   4   4                                 
*/ 
