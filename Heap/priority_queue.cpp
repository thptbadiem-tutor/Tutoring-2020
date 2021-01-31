#include <iostream>
#include <queue>

using namespace std;

void viDu1() {
    priority_queue<int> Q; // Mặc định là heap max -> Q.top() là giá trị lớn nhất
    priority_queue<int, vector<int>, less<int> > Qmax; // heap max -> Qmax.top() là giá trị lớn nhất
    priority_queue<int, vector<int>, greater<int> > Qmin; // heap min -> Qmin.top() là giá trị nhỏ nhất
    for (int i = 1; i < 10; ++ i) {
        Q.push(i);
        Qmax.push(i);
        Qmin.push(i);
        cout << "Max: " << Q.top() << ' ' << Qmax.top() << " - Min: " << Qmin.top() << endl;
    }
    for (int i = -1; i >= -10; -- i) {
        Q.push(i);
        Qmax.push(i);
        Qmin.push(i);
        cout << "Max: " << Q.top() << ' ' << Qmax.top() << " - Min: " << Qmin.top() << endl;
    }
}

void viDu2() {
    priority_queue<int> Q; // Mặc định là heap max -> Q.top() là giá trị lớn nhất
    priority_queue<int, vector<int>, less<int> > Qmax; // heap max -> Qmax.top() là giá trị lớn nhất
    priority_queue<int, vector<int>, greater<int> > Qmin; // heap min -> Qmin.top() là giá trị nhỏ nhất
    int n;
    cout << "Nhập số nguyên n ";
    cin >> n;
    for (int i = 0; i < n; ++ i) {
        int tmp;
        cout << "Nhập một số nguyên ";
        cin >> tmp;
        Q.push(tmp);
        Qmax.push(tmp);
        Qmin.push(tmp);
        cout << "Max: " << Q.top() << ' ' << Qmax.top() << " - Min: " << Qmin.top() << endl;
    }
}

int main() {
    viDu1();
    viDu2();
    return 0;
}
