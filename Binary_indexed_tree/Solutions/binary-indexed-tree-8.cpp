#include <iostream>
#include <vector>

using namespace std;
const int MAXVAL = 1000000;
int max_label;

void Update(vector<int> &T, int label, int val) {
    while (label <= max_label) {
        T[label] = max(T[label], val);
        label += label & -label;
    }
}

int Get_max(vector<int> &T, int label) {
    int res = -MAXVAL - 1;
    while (label) {
        res = max(res, T[label]);
        label -= label & -label;
    }
    return res;
}

int main() {
    vector<int> T(MAXVAL * 2 + 2, -MAXVAL - 1);
    max_label = MAXVAL * 2 + 1;
    int n;
    cin >> n;
    for (int i = 0, ai; i < n; ++ i) {
        cin >> ai;
        int label = ai + MAXVAL + 1;
        int res = Get_max(T, label);
        if (res < -MAXVAL) {
            cout << "No solution" << endl;
        } else {
            cout << res << endl;
        }
        Update(T, label, ai);
    }
    return 0;
}
