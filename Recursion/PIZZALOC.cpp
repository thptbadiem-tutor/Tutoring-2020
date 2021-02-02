/* Đề bài
 * https://codeforces.com/group/FLVn1Sc504/contest/274516/problem/O
 * https://vn.spoj.com/problems/PIZZALOC/
 * */
#include <iostream>
#include <vector>

using namespace std;
/*
    * k: số nhà hàng có thể mở
    * r: bán kính phục vụ (của mỗi nhà hàng)
    * m: số nhà hàng tối đa được mở
    * n: số khu nhà
    * */
int k, r, m, n;

struct Restaurant {
    int x, y; // Tọa độ
};

struct House {
    int x, y; // Tọa độ
    int s;    // Số người
};
vector<Restaurant> restaurant;  // Tọa độ nhà hàng
vector<House>      house;      // Tọa độ nhà ở

void Input() {
    cin >> k >> r;
    cin >> m;
    for (int i = 0, x, y; i < m; ++ i) {
        cin >> x >> y;
        restaurant.push_back({x, y});
    }
    cin >> n;
    for (int i = 0, x, y, s; i < n; ++ i) {
        cin >> x >> y >> s;
        house.push_back({x, y, s});
    }
}

vector<int> canServe[20];
vector<int> cnt;

void Preprocess() { 
    /* Tiền xử lý
     * - canServe[i] là vector chứa index của các nhà dân (0-based) trong phạm vi phục vụ của nhà hàng thứ i (0-based)
     * - có tối đa 20 nhà hàng --> mảng canServe[20]
     * */
    for (int res = 0; res < m; ++ res) {
        for (int h = 0; h < n; ++ h) {
            if ((restaurant[res].x - house[h].x) * (restaurant[res].x - house[h].x)
              + (restaurant[res].y - house[h].y) * (restaurant[res].y - house[h].y) <= r * r) {
                canServe[res].push_back(h);  
            }
        }
    }
    cnt.resize(n, 0); // cnt[h] = số lượng nhà hàng có thể phục vụ nhà h ĐÃ ĐƯỢC MỞ
}

vector<int> chosens(1, -1); // Chứa index của các Restaurant được chọn, 1-based
int result = 0;

void Recursion(int index, int servedPeople) {
    /*
     * index: nhà hàng thứ index sẽ được chọn trong hàm này, (1-based)
     * servedPeople: số người đã được phục vụ, trước khi vào hàm này
     * */
    if (index <= k) {
        for (int res = chosens[index - 1] + 1; res < m; ++ res) {
            int t = servedPeople;
            // Chọn nhà hàng res --> Cập nhật các trạng thái
            chosens.push_back(res); // Thử chọn nhà hàng thứ res
            for (int i = 0; i < canServe[res].size(); ++ i) {
                int h = canServe[res][i]; // nhà dân h
                t += (cnt[h] == 0) * house[h].s; // Nếu cnt[h] == 0 (chưa được ai phục vụ)
                ++ cnt[h];
            }
            // Gọi đệ quy level tiếp theo
            Recursion(index + 1, t);
            // Khôi phục tất cả trạng thái
            chosens.pop_back();
            for (int i = 0; i < canServe[res].size(); ++ i) {
                int h = canServe[res][i];
                -- cnt[h];
            }
        }
    } else {
        result = max(result, servedPeople);
    }
}

void Solve() {
    Recursion(1, 0); 
    cout << result << endl;
}

int main() {
    /* Tóm tắt
     * nhà hàng: 0-based
     * nhà dân: 0-based
     * */
    Input();
    Preprocess();
    Solve();
    return 0;
}
