#include <iostream>

using namespace std;
const int MAXVAL = 1000000;

int T[MAXVAL + 1] = {0};

void Update(int label) {
    while (label <= MAXVAL) {
        ++T[label];
        label += label & -label;
    }
}

int Get_sum(int label) {
    int result = 0;
    while (label) {
        result += T[label];
        label -= label & -label;
    }
    return result;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0, a; i < n; ++ i) {
        cin >> a;
        cout << Get_sum(a - 1) << endl;
        Update(a);
    }
    return 0;
}
