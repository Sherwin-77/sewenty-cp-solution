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
    cout << "DEBUG VALUE " << valueName << " INDEX " << index << ": " << value << '\n';
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

    /**
     * n - Number of room
     * s - Start room
     * f - Finish room
     */
    ll n, s, f;
    cin >> n >> s >> f;
    vector<int> golds(n);
    vector<bool> hasSkipMonsterCoin(n, false);
    /**
     * int -> index to Room
     * bool -> monster or not
     */
    vector<vector<pair<int, bool>>> adj(n);
    vector<int> adjCount(n, 0);
    for (ll i = 0; i < n; i++) {
        cin >> golds[i];
    }
    int k;
    int a, b;
    bool m;
    cin >> k;
    for (int i = 0; i < k; i++) {
        cin >> a >> b >> m;
        adj[a - 1].push_back({b - 1, m});
        adjCount[b - 1]++;
    }
    int c;
    int tmp;
    cin >> c;
    for (int i = 0; i < c; i++) {
        cin >> tmp;
        hasSkipMonsterCoin[tmp - 1] = true;
    }

    queue<int> tmpq;
    for(int i = 0; i < n; i++) {
        if(adjCount[i] == 0) {
            tmpq.push(i);
        }
    }
    queue<int> q;
    while(!tmpq.empty()) {
        int node = tmpq.front();
        tmpq.pop();
        q.push(node);
        for(auto x : adj[node]) {
            adjCount[x.first]--;
            if(adjCount[x.first] == 0) {
                tmpq.push(x.first);
            }
        }
    }
    /**
     * Note from Haiboko
     * the coins is when you enter the room
     * push on neighbor
    */
    vector<vector<int>> dp(n, vector<int>(c+1, -1));
    dp[s - 1][0] = golds[s - 1];
    while(!q.empty()) {
        int node = q.front();
        q.pop(); 

        for(auto x : adj[node]) {
            for(int curCoin = 0; curCoin <= c; curCoin++) {
                int actualCoin = curCoin + hasSkipMonsterCoin[node];
                if(actualCoin > c || dp[node][curCoin] == -1) continue;
                if(x.second){
                    if(actualCoin == 0) continue;
                    dp[x.first][actualCoin - 1] = max(dp[x.first][actualCoin - 1], dp[node][curCoin] + golds[x.first]);
                } else {
                    dp[x.first][actualCoin] = max(dp[x.first][actualCoin], dp[node][curCoin] + golds[x.first]);
                }
            }
        }
    }
    int best = -1;
    for(int i = 0; i <= c; i++) {
        best = max(best, dp[f - 1][i]);
    }
    print(best);
}