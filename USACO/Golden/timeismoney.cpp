#include <algorithm>
#include <bitset>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;
// #define int long long

void fileIO(string fileName, string inExt = ".in", string outExt = ".out") {
    string fIn = fileName + inExt;
    string fOut = fileName + outExt;
    freopen(fIn.c_str(), "r", stdin);
    freopen(fOut.c_str(), "w", stdout);
}

template <typename T>
void debug(T const &value, std::string valueName) {
    cout << "DEBUG VALUE " << valueName << ": " << value << '\n';
}
template <typename T>
void debug(T const &value, std::string valueName, int index) {
    cout << "DEBUG VALUE " << valueName << " INDEX " << index << ": " << value
         << '\n';
}

template <typename T>
void print(T const &value, bool newLine = true) {
    cout << value;
    if (newLine) cout << '\n';
}

// Alternative
typedef long long ll;

signed main() {
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    ll n, m, c;
    int a, b;
    fileIO("time");
    cin >> n >> m >> c;
    vector<ll> moni(n);
    vector<ll> best(n, -922337203685477580LL);
    best[0] = 0;
    vector<vector<int>> adj(n);
    queue<pair<int, pair<ll, ll>>> q;
    for (int i = 0; i < n; i++) cin >> moni[i];
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        a--;
        b--;
        adj[a].push_back(b);
    }
    q.push({0, {0, 0}});
    while (!q.empty()) {
        auto [node, dt] = q.front();
        auto [cur, days] = dt;
        q.pop();
        // cout << "Node: " << node << " | Current Cost: " << cur << " | Current days: " << days << '\n';
        days++;
        for (auto x : adj[node]) {
            if(cur + moni[x] - c * (days * days) < best[x]) continue;
            best[x] = max(best[x], cur + moni[x] - c*(days*days));
            q.push({x, {cur+moni[x], days}});
        }
    }
    cout << best[0];
}