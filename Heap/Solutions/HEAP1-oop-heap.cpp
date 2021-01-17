#include <iostream>
#include <vector>

using namespace std;

class MinHeap {
private:
    vector<int> heap;
    int current_size;
    
    void upheap(int con) {
        int value = heap[con];
        int cha;
        while (con / 2 > 0) {
            cha = con / 2;
            if (heap[cha] < value) {
                break;
            }
            heap[con] = heap[cha];
            con = cha;
        }
        heap[con] = value;
    }
    void downheap(int cha) {
        int value = heap[cha];
        int con;
        while (cha * 2 <= current_size) {
            con = cha * 2; // Suppose the left child is better
            if (con + 1 <= current_size && heap[con + 1] < heap[con]) { // Check if the right child is better
                con = con + 1;
            }
            if (value < heap[con]) {
                break;
            }
            heap[cha] = heap[con];
            cha = con;
        }
        heap[cha] = value;
    }
public:
    MinHeap() {
        heap.push_back(-1); // Dummy element
        current_size = 0;
    }
    int size() {
        return current_size;
    }
    void push(int value) {
        heap.push_back(value);
        ++ current_size;
        upheap(current_size);
    }
    int top() {
        return heap[1];
    }
    void pop() {
        swap(heap[1], heap[current_size]);
        heap.pop_back(); 
        -- current_size;
        downheap(1);
    }
};

void solve() {
    MinHeap H;
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++ i) {
        cin >> a[i];
        H.push(a[i]);
    }
    long long result = 0;
    while (H.size() > 1) {
        int tmp = H.top();
        H.pop();
        tmp += H.top();
        H.pop();
        result += tmp;
        H.push(tmp);
    }
    cout << result << endl;
}

int main() {
    int test;
    cin >> test;
    for (int i = 0; i < test; ++ i) {
        solve();
    }
    return 0;
}
