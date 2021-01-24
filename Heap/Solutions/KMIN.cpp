#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

typedef pair<int, int> data;

vector<int> a, b;

class comparator_class {
public:
    bool operator() (data x, data y) {
        return a[x.first] + b[x.second] > a[y.first] + b[y.second];
    }
    // We want min queue 
    // and the queue.top() element always lies at the end of the vector/container
    // --> comparision policy: smaller values stands before greater values
    // --> use '<'
};

int main() {
    int m, n, k;
    cin >> m >> n >> k;
    for (int i = 0, num; i < m; ++ i) {
        cin >> num;
        a.push_back(num);
    }
    for (int i = 0, num; i < n; ++ i) {
        cin >> num;
        b.push_back(num);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    priority_queue<data, vector<data>, comparator_class> Q;
    for (int i = 0; i < m; ++ i) {
        Q.push(make_pair(i, 0)); // a[i] + b[0]
    }
    while (!Q.empty() && k) { // Pop out k - 1 greatest elements
        int i = Q.top().first, j = Q.top().second;
        cout << a[Q.top().first] + b[Q.top().second] << endl;
        Q.pop();
        Q.push(make_pair(i, j + 1));
        -- k;
    }
    return 0;
}
