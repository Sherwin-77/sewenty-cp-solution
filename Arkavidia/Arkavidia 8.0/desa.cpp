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

void mark(int node, vector<vector<int>> &adj, vector<bool> &covered, int &res) {
    covered[node] = true;

    // debug(node+1, "Mark");

    for (auto x : adj[node]) {
        covered[x] = true;
    }

    res++;
}

void dfs(int node, int parent, vector<vector<int>> &adj, vector<bool> &covered,
         int &res) {
    for (auto x : adj[node]) {
        // Credit to Haiboko 
        if (x == parent) continue;
        dfs(x, node, adj, covered, res);
        if(!covered[x]){
            mark(node, adj, covered, res);
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    int n;
    int a, b;
    cin >> n;

    int res = 0;
    vector<vector<int>> adj(n, vector<int>());
    vector<bool> used(n, false);
    vector<bool> covered(n, false);
    for (int i = 0; i < n - 1; i++) {
        cin >> a >> b;
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    // for (int i = 0; i < n; i++) {
    //     if (adj[i].size() == 1 && !covered[i]) {
    //         mark(adj[i][0], adj, covered, res);
    //     }
    // }


    dfs(0, -1, adj, covered, res);
    if(!covered[0]) mark(0, adj, covered, res);
    cout << res;
}