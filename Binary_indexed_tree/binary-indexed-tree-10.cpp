#include <iostream>
#include <vector>

using namespace std;
const int MAX_LABEL = 2000001;
const int MAX_VAL = 1000000;
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
    vector<pair<int, int> > a(n);
    for (int i = 0; i < n; ++ i) {
        cin >> a[i].first;
        // mapping 1 to 1e6, 2 to 1e6 - 1, ..., 1e6 to 1
        a[i].second = MAX_VAL - a[i].first + 1; 
        // Print answer for this query
        int answer = Get_min(a[i].second - 1);
        answer = (answer <= MAX_VAL) ? answer : 0;
        cout << answer << endl;
        // Update
        Update(a[i].second, a[i].first);

    }
    return 0;
}
