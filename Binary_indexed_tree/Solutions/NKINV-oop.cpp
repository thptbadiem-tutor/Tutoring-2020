#include <iostream>
#include <vector>

using namespace std;
const int MAX_LABEL = 60000;
const int MAX_VAL = 60000;

class BIT {
private:
    int max_label;
    vector<int> T;
public:
    BIT(int size) {
        max_label = size;
        T.resize(max_label + 1, 0);
    }
    void Update(int label) {
        for (int i = label; i <= max_label; i += i & -i) {
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
};

int main() {
    BIT Tree(MAX_LABEL);
    int n, result = 0;
    cin >> n;
    for (int i = 0, ai; i < n; ++ i) {
        cin >> ai;
        ai = MAX_VAL - ai + 1;
        result += Tree.Count(ai - 1);
        Tree.Update(ai);
    }
    cout << result << endl;
    return 0;
}
