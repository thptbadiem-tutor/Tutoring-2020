#include <iostream>
#include <vector>

using namespace std;
const int MAX_LABEL = 60000;
const int MAX_VAL = 60000;

int T[MAX_LABEL + 1] = {0};

void Update(int label) {
    for (int i = label; i <= MAX_LABEL; i += i & -i) {
        ++ T[i];
    }
}

int Count(int label) {
    int res = 0;
    for (int i = label; i > 0; i -= i & -i) {
        res += T[i];
    }
    return res;
}

int main() {
    int n, result = 0;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++ i) {
        cin >> a[i];
    }
    for (int i = n - 1; i >= 0; -- i) {
        result += Count(a[i] - 1);
        Update(a[i]);
    }
    cout << result << endl;
    return 0;
}
