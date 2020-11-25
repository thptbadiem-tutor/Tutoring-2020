#include <iostream>
#include <vector>

using namespace std;
const int MAXVAL = 1000000;

void Update(vector<int> &T, int label) {
    while (label <= MAXVAL) {
        ++T[label];
        label += label & -label;
    }
}

int Get_sum(vector<int> &T, int label) {
    int result = 0;
    while (label) {
        result += T[label];
        label -= label & -label;
    }
    return result;
}

int main() {
    vector<int> T(MAXVAL + 1, 0);
    int n;
    cin >> n;
    for (int i = 0, a; i < n; ++ i) {
        cin >> a;
        cout << Get_sum(T, a - 1) << endl;
        Update(T, a);
    }
    return 0;
}
