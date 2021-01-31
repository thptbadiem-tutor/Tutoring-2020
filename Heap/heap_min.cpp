#include <iostream>
#include <vector>

using namespace std;

void upheap(vector<int> &v, int con) {
    int value = v[con];
    while (con / 2 > 0) {
        int cha = con / 2;
        if (v[cha] < value) { // min-heap --> use "<"; min-heap nên dùng dấu nhỏ hơn <
            break;
        }
        v[con] = v[cha];
        con = cha;
    }
    v[con] = value;
}

void downheap(vector<int> &v, int cha) {
    int n = v.size() - 1; // Do not count 1 dummy item at index [0]; không tính phần tử dummy ở vị trí [0]
    int value = v[cha];
    while (cha * 2 <= n) {
        int con = cha * 2;
        if (con + 1 <= n && v[con + 1] < v[con]) { // min-heap --> use "<"; min-heap nên dùng dấu nhỏ hơn <
            con = con + 1;
        }
        if (value < v[con]) { // min-heap --> use "<"; min-heap nên dùng dấu nhỏ hơn <
            break;
        }
        v[cha] = v[con];
        cha = con;
    }
    v[cha] = value;
}

/*
Heap cung cấp các hàm
- Thêm phần tử - Push
- Lấy ra và hủy phần tử tốt nhất - Pop
- Lấy giá trị phần tử tốt nhất - Top
- Kiểm tra heap rỗng
*/

void push(vector<int> &v, int value) {
    v.push_back(value);
    int n = v.size() - 1; 
    upheap(v, n);
}

void pop(vector<int> &v) {
    swap(v[1], v[v.size() - 1]);
    v.pop_back();
    downheap(v, 1);
}

int top(vector<int> v) {
    return v[1];
}

bool empty(vector<int> v) {
    return v.size() == 1;
}

void viDu1() {
    // Thêm phần tử dummy ở index [0]
    // Add 1 dummy value at index [0]
    vector<int> v(1, -1); // Giá trị bất kì
    //
    cout << "Ví dụ 1: Min heap" << endl;
    int n;
    cout << "Nhập số n là số lượng phần tử ";
    cin >> n;
    for (int i = 0, num; i < n; ++ i) {
        cin >> num;
        push(v, num);
        cout << "Giá trị nhỏ nhất là " << top(v) << endl;
    }
    for (int i = 0; i < n; ++ i) {
        cout << "Pop giá trị " << top(v);
        pop(v);
        if (empty(v)) {
            cout << " Heap rỗng " << endl;
        } else {
            cout << " giá trị nhỏ nhất hiện tại " << top(v) << endl;
        }
    }
}

int main() {
    viDu1();
    return 0;
}
