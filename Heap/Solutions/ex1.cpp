#include <iostream>
#include <vector>

using namespace std;

vector<int> heap(1, 0);
int heap_size = 0;

void up_heap(int index) {
    int value = heap[index];
    int cha;
    while (index / 2 > 0) {  /// index = 2
        cha = index / 2;     /// cha = 1
        if (heap[cha] >= value)  // heap[cha] 7 >= 6
            break;
        heap[index] = heap[cha];  
        index = cha; // index = empty slot, index = cha --> update new empty slot
    }
    heap[index] = value;
}

void down_heap(int index) {
    int value = heap[index];
    int con;
    while (index * 2 < heap_size) {
        con = index * 2;
        if (con + 1 <= heap_size && heap[con + 1] > heap[con]) 
            ++ con;
        if (value >= heap[con]) // !(heap[con] > heap[index])
            break;
        heap[index] = heap[con];
        index = con;
    }
    heap[index] = value;
}

void insert(int value) {
    /* ++ heap_size; */
    /* heap[heap_size] = value; */
    heap[++ heap_size] = value;
    up_heap(heap_size);
}

void remove_root() {
    swap(heap[1], heap[heap_size]);
    -- heap_size;
    down_heap(1);
}

int main() {
    // Nhập dữ liệu
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++ i) {
        cin >> a[i];
        insert(a[i]);
    }
    int q; 
    cin >> q;
    for (int i = 0; i < q; ++ i) {
        int num;
        cin >> num;
        if (num == 0) {
            remove_root();
        } else if (num == 1) {
            int value;
            cin >> value;
            insert(value);
        } else {
            cout << heap[1] << endl;
        }
    }
    // 
    return 0;
}
/*

id_cha = id_con / 2

id_con1 = id_cha * 2
id_con2 = id_cha * 2 + 1

id_root = 1
*/
