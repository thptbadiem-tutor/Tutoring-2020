#include <iostream>
#include <vector>

using namespace std;

class BIT {
private:
    int max_val;
    vector<long long> T;
public:
    BIT(int size) {
        this->max_val = size;
        T.resize(max_val + 1, 0);
    }
    void Update(int label, int val) {
        while (label <= max_val) {
            T[label] += val;
            label += label & -label;
        }
    }
    long long Get_sum(int label) {
        long long res = 0;
        while (label) {
            res += T[label];
            label -= label & -label;
        }
        return res;
    }
};

int main() {
    int offset = 1000001;   
    BIT Tree(2 * 1000000 + 1);
    int n;
    cin >> n;
    for (int i = 0, a; i < n; ++ i) {
        cin >> a;
        Tree.Update(a + offset, a);
        cout << Tree.Get_sum(a + offset - 1) << endl;
    }
    return 0;
}
