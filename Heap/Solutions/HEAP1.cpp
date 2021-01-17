#include <iostream>
#include <queue> /// Library for priority_queue

using namespace std;

void solve() {
    priority_queue<int, vector<int>, greater<int> > Q;
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++ i) {
        cin >> a[i];
        Q.push(a[i]);
    }
    long long result = 0;
    while (Q.size() > 1) {
        int tmp = Q.top();
        Q.pop();
        tmp += Q.top();
        Q.pop();
        result += tmp;
        Q.push(tmp);
    }
    cout << result << endl;
}

int main() {
    int test;
    cin >> test;
    for (; test; -- test) {
        solve();
    }
    return 0;
}
