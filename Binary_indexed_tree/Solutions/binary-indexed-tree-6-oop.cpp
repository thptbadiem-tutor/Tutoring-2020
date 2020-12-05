#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class BIT {
private:
    int max_val;
    vector<long long> T;
public:
    BIT(int size) {
        this->max_val = size;
        T.resize(max_val + 1, 0);
    }
    void Update(int label, int val) {
        while (label <= max_val) {
            T[label] += val;
            label += label & -label;
        }
    }
    long long Count(int label) {
        long long res = 0;
        while (label) {
            res += T[label];
            label -= label & -label;
        }
        return res;
    }
};

int main() {
    BIT Tree(100000); // 1e5
    int n;
    cin >> n;
    vector<pair<int, int> > a(n);
    vector<pair<int, int> > b(n);
    for (int i = 0; i < n; ++ i) {
        cin >> a[i].first;
        b[i] = make_pair(a[i].first, i);
    }
    sort(b.begin(), b.end()); // Hàm compare mặc định của sort là < (nhỏ hơn)
    // Với pair thì hàm compare mặc định sẽ so sánh first, rồi mới so sánh second (khi first bằng nhau)
    int last_val = b[0].first - 1, new_val = 0;
    for (int i = 0; i < n; ++ i) {
        if (last_val == b[i].first) {
            a[b[i].second].second = new_val;
        } else {
            last_val = b[i].first;
            a[b[i].second].second = ++ new_val;
        }
    }
    for (int i = 0; i < n; ++ i) {
        cout << Tree.Count(a[i].second - 1) << endl;
        Tree.Update(a[i].second, a[i].first);
    }
    return 0;
}
