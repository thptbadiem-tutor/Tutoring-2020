#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
const int MAX_LABEL = 1e5;
const int MAX_VAL = 1e9;
vector<int> T(MAX_LABEL + 1, MAX_VAL + 1);

void Update(int label, int val) {
    while (label <= MAX_LABEL) {
        T[label] = min(T[label], val);
        label += label & -label;
    }
}

int Get_min(int label) {
    int res = MAX_VAL + 1;
    while (label) {
        res = min(res, T[label]);
        label -= label & -label;
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    vector<pair<int, int> > a(n), b(n);
    for (int i = 0; i < n; ++ i) {
        cin >> a[i].first;
        b[i] = make_pair(a[i].first, i);
    }
    sort(b.begin(), b.end());
    int last_val = b[0].first - 1, new_val = 0;
    for (int i = 0; i < n; ++ i) {
        if (last_val == b[i].first) {
            a[b[i].second].second = new_val;
        } else {
            last_val = b[i].first;
            a[b[i].second].second = ++ new_val;
        }
    }

    int max_val = new_val;
    for (int i = 0; i < n; ++ i) {
        a[i].second = max_val - a[i].second + 1; 
        int answer = Get_min(a[i].second - 1);
        if (answer == MAX_VAL + 1) {
            cout << "No solution" << endl;
        } else {
            cout << answer << endl;
        }
        Update(a[i].second, a[i].first);
    }
    return 0;
}
