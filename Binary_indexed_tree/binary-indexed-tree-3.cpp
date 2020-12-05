#include <iostream>
#include <vector>

using namespace std;
const int max_val = 2000001;
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
    int offset = 1000001;   
    int n;
    cin >> n;
    for (int i = 0, a; i < n; ++ i) {
        cin >> a;
        cout << Count(a + offset - 1) << endl;
        Update(a + offset, 1);
    }
    return 0;
}
