#include <iostream>
#include <vector>

using namespace std;
int n, m;
int a[201][201];

void solve1() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++ i) {
        for (int j = 1; j <= m; ++ j) {
            cin >> a[i][j];
        }
    }
    //int f[405][201][201];
    vector<vector<vector<int> > > f(405, vector<vector<int> > (201, vector<int> (201, -41234)));
    f[0][1][1] = 0;
    for (int cnt = 1; cnt <= m + n - 1; ++ cnt) {
        for (int i = 1; i <= n; ++ i) {
            for (int x = 1; x <= n; ++ x) {
                int j = cnt - (i - 1) + 1;
                int y = cnt - (x - 1) + 1;
                if (i > x) {
                    f[cnt][i][j] = max(
                        max(f[cnt - 1][i - 1][x - 1], f[cnt - 1][i - 1][x]),
                        max(f[cnt - 1][i][x - 1], f[cnt - 1][i][x])
                    ) 
                    + a[i][j] + a[x][y];
                }
                /*
                f[i][j][x][y] = max(
                    max(f[i - 1][j][x - 1][y], f[i - 1][j][x][y - 1]),
                    max(f[i][j - 1][x - 1][y], f[i][j - 1][x][y - 1])
                )
                + a[i][j] + a[x][y];
                */
            }
        }
    }
    cout << f[n + m - 2][n][n] << endl;
}

int main() {
    freopen("BROTHERS.INP", "r", stdin);
    freopen("BROTHERS.OUT", "w", stdout);
    solve1();
    return 0;
}
/*
12345
12345
12345
67890
*/
