#include <iostream>
#include <vector>

using namespace std;

class Max_heap {
private: 
    vector<int> v;
    void upheap(int con) {
        int value = v[con];
        while (con / 2 > 0) {
            int cha = con / 2;
            if (v[cha] > value) { // max-heap --> use ">"; max-heap nên dùng dấu lớn hơn >
                break;
            }
            v[con] = v[cha];
            con = cha;
        }
        v[con] = value;
    }
    void downheap(int cha) {
        int n = v.size() - 1; // Do not count 1 dummy item at index [0]; không tính phần tử dummy ở vị trí [0]
        int value = v[cha];
        while (cha * 2 <= n) {
            int con = cha * 2;
            if (con + 1 <= n && v[con + 1] > v[con]) { // max-heap --> use ">"; max-heap nên dùng dấu lớn hơn >
                con = con + 1;
            }
            if (value > v[con]) { // max-heap --> use ">"; max-heap nên dùng dấu lớn hơn >
                break;
            }
            v[cha] = v[con];
            cha = con;
        }
        v[cha] = value;
    }
public:
    Max_heap() {
        v.push_back(-1); // Giá trị bất kì
        // Thêm phần tử dummy ở index [0]
        // Add 1 dummy value at index [0]
    }
    void push(int value) {
        v.push_back(value);
        int n = v.size() - 1; 
        upheap(n);
    }
    void pop() {
        swap(v[1], v[v.size() - 1]);
        v.pop_back();
        downheap(1);
    }
    int top() {
        return v[1];
    }
    bool empty() {
        return v.size() == 1;
    }
};

class Min_heap {
private: 
    vector<int> v;
    void upheap(int con) {
        int value = v[con];
        while (con / 2 > 0) {
            int cha = con / 2;
            if (v[cha] < value) { // min-heap --> use ">"; min-heap nên dùng dấu lớn hơn >
                break;
            }
            v[con] = v[cha];
            con = cha;
        }
        v[con] = value;
    }
    void downheap(int cha) {
        int n = v.size() - 1; // Do not count 1 dummy item at index [0]; không tính phần tử dummy ở vị trí [0]
        int value = v[cha];
        while (cha * 2 <= n) {
            int con = cha * 2;
            if (con + 1 <= n && v[con + 1] < v[con]) { // min-heap --> use ">"; min-heap nên dùng dấu lớn hơn >
                con = con + 1;
            }
            if (value < v[con]) { // min-heap --> use ">"; min-heap nên dùng dấu lớn hơn >
                break;
            }
            v[cha] = v[con];
            cha = con;
        }
        v[cha] = value;
    }
public:
    Min_heap() {
        v.push_back(-1); // Giá trị bất kì
        // Thêm phần tử dummy ở index [0]
        // Add 1 dummy value at index [0]
    }
    void push(int value) {
        v.push_back(value);
        int n = v.size() - 1; 
        upheap(n);
    }
    void pop() {
        swap(v[1], v[v.size() - 1]);
        v.pop_back();
        downheap(1);
    }
    int top() {
        return v[1];
    }
    bool empty() {
        return v.size() == 1;
    }
};

void viDu1() {
    cout << "Ví dụ 1: Max heap" << endl;
    Max_heap H;
    int n;
    cout << "Nhập số n là số lượng phần tử ";
    cin >> n;
    for (int i = 0, num; i < n; ++ i) {
        cin >> num;
        H.push(num);
        cout << "Giá trị lớn nhất là " << H.top() << endl;
    }
    for (int i = 0; i < n; ++ i) {
        cout << "Pop giá trị " << H.top();
        H.pop();
        if (H.empty()) {
            cout << " Heap rỗng " << endl;
        } else {
            cout << " giá trị lớn nhất hiện tại " << H.top() << endl;
        }
    }
}

void viDu2() {
    cout << "Ví dụ 2: Min heap" << endl;
    Min_heap H;
    int n;
    cout << "Nhập số n là số lượng phần tử ";
    cin >> n;
    for (int i = 0, num; i < n; ++ i) {
        cin >> num;
        H.push(num);
        cout << "Giá trị nhỏ nhất là " << H.top() << endl;
    }
    for (int i = 0; i < n; ++ i) {
        cout << "Pop giá trị " << H.top();
        H.pop();
        if (H.empty()) {
            cout << " Heap rỗng " << endl;
        } else {
            cout << " giá trị nhỏ nhất hiện tại " << H.top() << endl;
        }
    }
}

int main() {
    viDu1(); 
    viDu2();
    return 0;
}
