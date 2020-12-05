#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int max_val = 100000;
int T[max_val + 1] = {0};

void Update(int label, int val) {
    while (label <= max_val) {
        T[label] += val;
        label += label & -label;
    }
}
int Count(int label) {
    int res = 0;
    while (label) {
        res += T[label];
        label -= label & -label;
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<pair<int, int> > b(n);
    for (int i = 0; i < n; ++ i) {
        cin >> a[i];
        b[i] = make_pair(a[i], i);
    }
    sort(b.begin(), b.end()); // Hàm compare mặc định của sort là < (nhỏ hơn)
    // Với pair thì hàm compare mặc định sẽ so sánh first, rồi mới so sánh second (khi first bằng nhau)
    int last_val = b[0].first - 1, new_val = 0;
    for (int i = 0; i < n; ++ i) {
        if (last_val == b[i].first) {
            a[b[i].second] = new_val;
        } else {
            last_val = b[i].first;
            a[b[i].second] = ++ new_val;
        }
    }
    for (int i = 0; i < n; ++ i) {
        cout << Count(a[i] - 1) << endl;
        Update(a[i], 1);
    }
    return 0;
}
