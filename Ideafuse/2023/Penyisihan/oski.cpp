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
void print(T const &value, bool newLine = false) {
    cout << value;
    if (newLine) cout << '\n';
}

// Alternative
typedef long long ll;

int point[4][4];
const int vertigo[8] = {-2, -2, -1, 1, 2, 2, 1, -1};
const int horizon[8] = {1, -1, 2, 2, 1, -1, -2, -2};
bool visited[4][4] = {};

vector<vector<vector<pair<int, int>>>> adj(
    4, vector<vector<pair<int, int>>>(4, vector<pair<int, int>>()));
bool isValid(int iPos, int jPos) {
    return iPos >= 0 && iPos < 4 && jPos >= 0 && jPos < 4;
}
vector<pair<int, int>> pathing;
int normalize(pair<int, int> pos) { return (pos.first * 4) + pos.second + 1; }
pair<int, vector<pair<int, int>>> _dfs(int row, int col, vector<pair<int, int>> &path, int cost) {
    if (visited[row][col]) return {cost, path};
    path.push_back({row, col});
    visited[row][col] = true;
    // for (auto x : path) cout << x.first << ',' << x.second << ' ';
    // cout << endl;
    int ret = cost;
    auto retPath = path;
    for (auto x : adj[row][col]) {
        if (visited[x.first][x.second]) continue;
        auto [test, testPath] = _dfs(x.first, x.second, path, cost + point[row][col] * point[x.first][x.second]);
        if(test > ret){
            ret = test;
            retPath = testPath;
        } else if(test == ret) {
            retPath = min(testPath, retPath);
        }
    }
    path.pop_back();
    visited[row][col] = false;
    // print(ret, true);
    return {ret, retPath};
}
signed main() {
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 8; k++) {
                int v = vertigo[k];
                int h = horizon[k];
                if (isValid(i + v, j + h)) {
                    adj[i][j].push_back({i + v, j + h});
                }
            }
        }
    }
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++) cin >> point[i][j];
    vector<pair<int, int>> initi(16, {20, 20});
    pair<int, vector<pair<int, int>>> res = make_pair(0, initi);
    vector<pair<int, int>> used;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            auto cur = _dfs(i, j, used, 0);
            cur.first = -cur.first;
            res = min(res, cur);
        }
    }
    // for (int i = 0; i < 4; i++) {
    //     for (int j = 0; j < 4; j++) {
    //         cout << visited[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    print(-res.first, true);
    for(auto x: res.second) cout << normalize(x) << ' ';
}