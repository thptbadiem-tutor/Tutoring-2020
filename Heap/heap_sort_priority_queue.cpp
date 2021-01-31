#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void input(vector<int> &v) {
    int n;
    cout << "Nhập số n là số lượng phần tử ";
    cin >> n;
    v.clear();
    v.resize(n);
    for (int i = 0; i < n; ++ i) {
        cout << "Nhập phần tử thứ " << i + 1 << ": ";
        cin >> v[i];
    }
}

void output(vector<int> v) {
    for (int i = 0; i < v.size(); ++ i) {
        cout << v[i] << ' ';
    }
    cout << endl;
}

void sortIncreasing(vector<int> &v) {
    // sử dụng min queue
    priority_queue<int, vector<int>, greater<int> > Qmin;
    for (int i = 0; i < v.size(); ++ i) {
        Qmin.push(v[i]);
    }
    for (int i = 0; i < v.size(); ++ i) {
        v[i] = Qmin.top();
        Qmin.pop();
    }
}

void sortIncreasing2(vector<int> &v) {
    // sử dụng max queue
    priority_queue<int, vector<int>, less<int> > Qmax;
    for (int i = 0; i < v.size(); ++ i) {
        Qmax.push(v[i]);
    }
    for (int i = v.size() - 1; i >= 0; -- i) {
        v[i] = Qmax.top();
        Qmax.pop();
    }
}

void sortDecreasing(vector<int> &v) {
    // sử dụng max queue
    priority_queue<int, vector<int>, less<int> > Qmax;
    for (int i = 0; i < v.size(); ++ i) {
        Qmax.push(v[i]);
    }
    for (int i = 0; i < v.size(); ++ i) {
        v[i] = Qmax.top();
        Qmax.pop();
    }
}

void sortDecreasing2(vector<int> &v) {
    // sử dụng min queue
    priority_queue<int, vector<int>, greater<int> > Qmin;
    for (int i = 0; i < v.size(); ++ i) {
        Qmin.push(v[i]);
    }
    for (int i = v.size() - 1; i >= 0; -- i) {
        v[i] = Qmin.top();
        Qmin.pop();
    }
}

void viDu1() {
    vector<int> a;
    input(a);
    cout << "Sắp xếp tăng dần " << endl;
    sortIncreasing(a);
    output(a);
    input(a);
    sortIncreasing2(a);
    cout << "Sắp xếp tăng dần " << endl;
    output(a);
    input(a);
    sortDecreasing(a);
    cout << "Sắp xếp giảm dần " << endl;
    output(a);
    input(a);
    sortDecreasing2(a);
    cout << "Sắp xếp giảm dần " << endl;
    output(a);
}

int main() {
    viDu1();
    return 0;
}
