/*
 * Đề bài: https://codeforces.com/group/FLVn1Sc504/contest/274493/problem/B
 */
#include <iostream>
#include <vector>

using namespace std;
const int NEGATIVE_INFINITY = -15000 * 50000 - 1;
const int MAX_INT = 2147483647;
struct Data {
    int sum, result, max_prefix, max_suffix;
    void Assign(int value) {
        this->sum = value;
        this->result = value;
        this->max_prefix = value;
        this->max_suffix = value;
    }
};

Data Combine(Data left, Data right) {
    Data res;
    res.sum = left.sum + right.sum;
    res.max_prefix = max(left.max_prefix, left.sum + right.max_prefix);
    res.max_suffix = max(left.max_suffix + right.sum, right.max_suffix);
    res.result = max(max(left.result, right.result), left.max_suffix + right.max_prefix);
    return res;
}

Data operator+(Data left, Data right) {
    Data res;
    res.sum = left.sum + right.sum;
    res.max_prefix = max(left.max_prefix, left.sum + right.max_prefix);
    res.max_suffix = max(left.max_suffix + right.sum, right.max_suffix);
    res.result = max(max(left.result, right.result), left.max_suffix + right.max_prefix);
    return res;
}

void Update(vector<Data> &T, int id, int l, int r, int index, int value) {
    if (index < l || r < index) {
        return;
    }
    if (l == r) {
        T[id].Assign(value); 
        return;
    }
    int m = (l + r) / 2, left_id = id * 2, right_id = id * 2 + 1;;
    Update(T, left_id, l, m, index, value);
    Update(T, right_id, m + 1, r, index, value);
    /* T[id] = Combine(T[left_id], T[right_id]); */
    T[id] = T[left_id] + T[right_id];
}

Data GSS(vector<Data> &T, int id, int l, int r, int x, int y) {
    if (x <= l && r <= y) {
        return T[id];
    }
    int m = (l + r) / 2;
    if (y <= m) {
        return GSS(T, id * 2, l, m, x, y);
    }
    if (x > m) {
        return GSS(T, id * 2 + 1, m + 1, r, x, y);
    }
    /* return Combine(GSS(T, id * 2, l, m, x, y), GSS(T, id * 2 + 1, m + 1, r, x, y)); */
    return GSS(T, id * 2, l, m, x, y) + GSS(T, id * 2 + 1, m + 1, r, x, y);
}

int main() {
    int n, m;
    cin >> n;
    vector<Data> T(n * 4 + 1);
    for (int i = 1, a; i <= n; ++ i) {
        cin >> a;
        Update(T, 1, 1, n, i, a);
    }
    cin >> m;
    for (int i = 1, x, y; i <= m; ++ i) {
        cin >> x >> y;
        cout << GSS(T, 1, 1, n, x, y).result << endl;
    }
    return 0;
}
