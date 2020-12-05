#include <iostream>

using namespace std;
const int MAXVAL = 1000000;

long long T[MAXVAL + 1] = {0};

void Update(int label, int value) {
    while (label <= MAXVAL) {
        T[label] += value;
        label += label & -label;
    }
}

long long Get_sum(int label) {
    long long result = 0;
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
        Update(a, a);
    }
    return 0;
}
