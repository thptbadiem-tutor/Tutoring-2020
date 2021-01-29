#include <deque>
#include <iostream>
#include <vector>
 
using namespace std;
 
void solve() {
    deque<int> Q; 
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    // Input
    for (int i = 0; i < n; ++ i) {
        cin >> a[i];
    }
    // Solve
    for (int i = 0; i < k - 1; ++ i) { // Add k - 1 firts elements
        // Push
        while (!Q.empty() && a[Q.back()] > a[i]) {
            Q.pop_back();
        }
        Q.push_back(i);
    }
    for (int i = k - 1; i < n; ++ i) {
        // Current interval of len k: [i - k + 1 .. i]
        if (!Q.empty() && Q.front() < i - k + 1) {
            Q.pop_front();
        }
        // Push
        while (!Q.empty() && a[Q.back()] > a[i]) {
            Q.pop_back();
        }
        Q.push_back(i);
        // Get result
        cout << a[Q.front()] << ' ';
    }
    cout << endl;
}
 
int main() {
    int test;
    cin >> test;
    for (; test; -- test) {
        solve();
    }
    return 0;
}
