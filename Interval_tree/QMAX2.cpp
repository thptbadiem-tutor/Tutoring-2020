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

void update(vector<int>& T, vector<int>& lazy, int id, int l, int r, int u, int v, int k) {
    if (l > r) {
        return;
    }
    // Xử lý các tín hiệu tăng-k đã được ghi nhận trước đó
    T[id] += lazy[id];
    if (l < r) { // Co nut con
        lazy[id * 2] += lazy[id];
        lazy[id * 2 + 1] += lazy[id];
    }
    lazy[id] = 0;
    // Xử lý xong

    /*
     * TH1 [u..v] và [l..r] không giao nhau
     * TH2 [l..r] là con của [u..v]
     * TH3 [u..v] và [l..r] có điểm chung
     */
    if (v < l || r < u) { // TH1 --> không làm gì hết, không quan tâm tới đoạn l..r
        return;
    }
    if (u <= l && r <= v) { // TH2 --> đang có yêu cầu tăng đoạn [u..v] lên k giá trị
        T[id] += k;
        if (l < r) { // Nếu mà nút id có các nút con
            lazy[id * 2] += k;
            lazy[id * 2 + 1] += k;
        }
        return;
    }
    // TH3
    int m = (l + r) / 2;
    update(T, lazy, id * 2,         l, m, u, v, k);
    update(T, lazy, id * 2 + 1, m + 1, r, u, v, k);
    T[id] = max(T[id * 2], T[id * 2 + 1]);
}

int getMax(vector<int>& T, vector<int>& lazy, int id, int l, int r, int u, int v) {
    if (l > r) {
        return -1000000;
    }
    // Xử lý các tín hiệu tăng-k đã được ghi nhận trước đó
    T[id] += lazy[id];
    if (l < r) { // Co nut con
        lazy[id * 2] += lazy[id];
        lazy[id * 2 + 1] += lazy[id];
    }
    lazy[id] = 0;
    // Xử lý xong

    /*
     * TH1 [u..v] và [l..r] không giao nhau
     * TH2 [l..r] là con của [u..v]
     * TH3 [u..v] và [l..r] có điểm chung
     */
    if (v < l || r < u) { // TH1 
        return -1000000;
    }
    if (u <= l && r <= v) { // TH2
        return T[id];
    }
    // TH3
    int m = (l + r) / 2;
    return max(
        getMax(T, lazy, id * 2,         l, m, u, v),
        getMax(T, lazy, id * 2 + 1, m + 1, r, u, v)
    );
}

int main() {
    int n, m, p;
    cin >> n >> m;
    vector<int> a(n + 2, 0);
    vector<int> T(4 * n + 1, 0);
    vector<int> lazy(4 * n + 1, 0); // lazy propagation
    for (int i = 0, q, u, v, k; i < m; ++ i) {
        cin >> q >> u >> v;
        if (q == 0) {
            cin >> k;
            update(T, lazy, 1, 1, n, u, v, k);
        } else {
            cout << getMax(T, lazy, 1, 1, n, u, v) << endl;    
        }
    }
    return 0;
}
