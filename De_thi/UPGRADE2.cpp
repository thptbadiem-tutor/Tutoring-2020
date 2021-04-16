#include <iostream>
#include <vector>
#include <queue>

using namespace std;
const int N = 100001;
int n, m;
vector<pair<int, int> > adj[N]; // ke - adjacent

struct Edge {
    int u, v, w;
    Edge(int x, int y, int z) {
        u = x;
        v = y;
        w = z;
    }
};

vector<Edge> edges;

void input() {
    cin >> n >> m;
    for (int i = 0; i < m; ++ i) {
        int u, v, t;
        cin >> u >> v >> t;
        edges.push_back(Edge(u, v, t));
        adj[u].push_back(make_pair(v, t));
        adj[v].push_back(make_pair(u, t));
    }
}

void dijkstra(int start, vector<long long> &distance, vector<int> &cnt) {
    priority_queue<pair<int /* distance */, int /* vertex */> > Q;
    for (int i = 1; i <= n; ++ i) {
        distance[i] = 212345678901ll;
        cnt[i] = 0;
    }
    distance[start] = 0;
    cnt[start] = 1;
    Q.push(make_pair(0, start));
    while (!Q.empty()) {
        // Tìm đỉnh có distance nhỏ nhất
        int d = -Q.top().first, u = Q.top().second;
        Q.pop();
        if (d != distance[u]) continue; // Nếu d != distance[u] --> cặp (d, u) trong heap bị out-of-date/không còn đúng nữa
        
        // Xét tất cả các đỉnh kề với u
        for (int i = 0; i < adj[u].size(); ++ i) {
            int v = adj[u][i].first;
            int w = adj[u][i].second;
            if (distance[u] + w < distance[v]) {
                distance[v] = distance[u] + w;
                cnt[v] = cnt[u];
                Q.push(make_pair(-distance[v], v));
            } else if (distance[u] + w == distance[v]) {
                cnt[v] += cnt[u];
            }
        }
    }
}

void solve() {
    vector<long long> distance1(n + 1), distance2(n + 1); 
    vector<int> cnt1(n + 1), cnt2(n + 1);
    dijkstra(1, distance1, cnt1);
    dijkstra(n, distance2, cnt2);
    // ----
    int result = 0;
    for (int i = 0; i < m; ++ i) {
        int u, v, w;
        u = edges[i].u;
        v = edges[i].v;
        w = edges[i].w;
        if (distance1[u] > distance1[v]) {
            swap(u, v);
        }
        if (
            distance1[u] + w == distance1[v] && cnt1[u] == cnt1[v]         
            &&
            distance2[u] == distance2[v] + w && cnt2[u] == cnt2[v]
        ) {
            ++ result;
        }
    }
    cout << result << endl;
}

int main() {
    freopen("UPGRADE.INP", "r", stdin);
    freopen("UPGRADE.OUT", "w", stdout);
    input(); 
    solve();
    return 0;
}
