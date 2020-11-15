#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
    freopen("test.out", "w", stdout);
    int n = 50000;
    int m = 100000;
    if (argc > 1) {
        n = atoi(argv[1]);
        m = atoi(argv[2]);
    }
    cout << n << ' ' << m << endl;
    int test = m / 2;
    for (int i = 0; i < m; ++ i) {
        /* int c = rand() % 2; */
        int c = i > test;
        if (c) {
            int u = rand() % (n - 1) + 1;
            int v = rand() % (n - u) + u;
            cout << c << ' ' << u << ' ' << v << endl;
        } else {
            cout << c << ' ' << rand() % n + 1 << ' ' << rand() % 10 << endl;
        }
    }
    return 0;
}
