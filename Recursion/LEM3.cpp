/* Đề bài
 * https://codeforces.com/group/FLVn1Sc504/contest/274821/problem/E
 * https://vn.spoj.com/problems/LEM3/
 * Code này giải bài LEM3 bằng thuật toán đệ quy kết hợp nhánh cận --> chỉ được 66.7/100 điểm
 * Để đạt 100 điểm, cần giải bằng thuật toán quy hoạch động trạng thái
 */
#include <iostream>
#include <vector>

using namespace std;

int finalResult = 68686868; // Positive infinity, dương vô cực

void recursion(int n, int index, int currentLocation, int cost, vector<vector<int> > &c, vector<int> &visited) {
    if (index == n) {
        finalResult = min(finalResult, cost);
    } else {
        if (index == 0) {
            for (int startLocation = 0; startLocation < n; ++ startLocation) {
                visited[startLocation] = true;
                recursion(n, index + 1, startLocation, cost, c, visited);
                visited[startLocation] = false;
            }
        } else {
            for (int nextLocation = 0; nextLocation < n; ++ nextLocation) {
                if (!visited[nextLocation]) {
                    cost += c[currentLocation][nextLocation];
                    visited[nextLocation] = true;
                    if (cost < finalResult) {
                        recursion(n, index + 1, nextLocation, cost, c, visited);
                    }
                    cost -= c[currentLocation][nextLocation];
                    visited[nextLocation] = false;
                }
            }
        }
    }
}

void solve() {
    int n;
    cin >> n;
    vector<vector<int> > c(n, vector<int> (n));
    vector<int> visited(n, 0);
    for (int i = 0; i < n; ++ i) {
        for (int j = 0; j < n; ++ j) {
            cin >> c[i][j];
        }
    }
    recursion(n, 0, 0, 0, c, visited);
    cout << finalResult << endl;
}

int main() {
    solve();
    return 0;
}
