#include <iostream>
#include <stack>
#include <vector>
 
using namespace std;
 
void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1), left(n + 1), right(n + 1);
    stack<int> S;
    // Input
    for (int i = 0; i < n; ++ i) {
        cin >> a[i];
    }
    a[n] = -1e9; // dummy val a[n] < all a[i]
    // Solve
    for (int i = 0; i < n + 1; ++ i) {
        left[i] = i;
        while (!S.empty() && a[S.top()] > a[i]) {
            right[S.top()] = i - 1;
            left[i] = left[S.top()];
            S.pop();
        }
        S.push(i);
    }
    // Get result
    int result = 0, resL, resR;
    for (int i = 0; i < n; ++ i) {
        if ((right[i] - left[i] + 1) * a[i] > result) {
            result = (right[i] - left[i] + 1) * a[i];
            resL = left[i];
            resR = right[i];
        }
    }
    resL += 1;
    resR += 1;
    cout << result << ' ' << resL << ' ' << resR << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    int test;
    cin >> test;
    for (; test; -- test) {
        solve();
    }
    return 0;
}
