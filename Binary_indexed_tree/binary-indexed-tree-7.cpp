#include <iostream>
#include <vector>

using namespace std;
const int MAXVAL = 1000000;

void Update(vector<int> &T, int label) {
    int val = label;
    while (label <= MAXVAL) {
        T[label] = max(T[label], val);
        label += label & -label;
    }
}

int Get_max(vector<int> &T, int label) {
    int res = 0;
    while (label) {
        res = max(res, T[label]);
        label -= label & -label;
    }
    return res;
}

int main() {
    vector<int> T(MAXVAL + 1, 0);
    int n;
    cin >> n;
    for (int i = 0, ai; i < n; ++ i) {
        cin >> ai;
        cout << Get_max(T, ai) << endl;
        Update(T, ai);
    }
    return 0;
}
