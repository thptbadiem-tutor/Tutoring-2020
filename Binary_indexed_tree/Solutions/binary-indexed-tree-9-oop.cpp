#include <iostream>
#include <vector>

using namespace std;
const int NEGATIVE_INFINITY = -1000000001;

class BIT {
private:
    int max_label;
    vector<int> T;
public:
    BIT(int size) {
        max_label = size;
        T.resize(max_label + 1, NEGATIVE_INFINITY);
    }
    void Update(int label, int val) {
        while (label <= max_label) {
            T[label] = max(T[label], val);
            label += label & -label;
        }
    }
    int Get_max(int label) {
        int res = NEGATIVE_INFINITY; // -1000000001 < min limti of a[i] (1e9)
        while (label) {
            res = max(res, T[label]);
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
        int res = Tree.Get_max(a[i].second - 1);
        if (res == NEGATIVE_INFINITY) {
            cout << "No solution" << endl;
        } else {
            cout << res << endl;
        }
        Tree.Update(a[i].second, a[i].first);
    }
    return 0;
}
