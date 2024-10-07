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

bool isFree(int i, int j, int maxH, int maxW, vector<string> &arr) {
    return i >= 0 && j >= 0 && i < maxH && j < maxW && arr[i][j] != '#';
}

int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void bfs(int i, int j, vector<string> &grid, vector<vector<int>> &maxMove) {
    queue<pair<int, int>> q;
    vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
    q.push({i, j});
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        if (visited[x][y]) continue;
        visited[x][y] = true;
        for (int i = 0; i < 4; i++) {
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];
            if (isFree(nx, ny, grid.size(), grid[0].size(), grid) && !visited[nx][ny]) {
                maxMove[nx][ny] = maxMove[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    int h, w;
    pair<int, int> startCoordinate;
    pair<int, int> finishCoordinate;
    cin >> h >> w;
    vector<string> grid(h);
    vector<vector<int>> medicineSetter(h, vector<int>(w, -1));
    vector<vector<int>> maxMove(h, vector<int>(w, 0));
    for (int i = 0; i < h; i++) cin >> grid[i];
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (grid[i][j] == 'S') {
                startCoordinate = {i, j};
            }
            if (grid[i][j] == 'T') {
                finishCoordinate = {i, j};
            }
        }
    }
    int n;
    int r, c, e;
    cin >> n;
    vector<pair<int, int>> medicineCoordinate;
    vector<bool> checked(n, false);
    bool possible = false;
    for (int i = 0; i < n; i++) {
        cin >> r >> c >> e;
        medicineSetter[r - 1][c - 1] = e;
        if (r-1 == startCoordinate.first && c-1 == startCoordinate.second) checked[i] = true;
        medicineCoordinate.push_back({r - 1, c - 1});
    }
    maxMove[startCoordinate.first][startCoordinate.second] = 0;
    bfs(startCoordinate.first, startCoordinate.second, grid, maxMove);
    if (maxMove[finishCoordinate.first][finishCoordinate.second] <= medicineSetter[startCoordinate.first][startCoordinate.second]) {
        possible = true;
    } else {
        queue<pair<int, int>> toCheck;
        for (int i = 0; i < n; i++) {
            if (maxMove[medicineCoordinate[i].first][medicineCoordinate[i].second] <= medicineSetter[startCoordinate.first][startCoordinate.second] && !checked[i]) {
                toCheck.push(medicineCoordinate[i]);
                checked[i] = true;
            }
        }
        while (!toCheck.empty()) {
            auto [i, j] = toCheck.front();
            toCheck.pop();
            maxMove[i][j] = 0;
            bfs(i, j, grid, maxMove);
            if (maxMove[finishCoordinate.first][finishCoordinate.second] <= medicineSetter[i][j]) {
                possible = true;
                break;
            }
            // for (int i = 0; i < h; i++) {
            //     for (int j = 0; j < w; j++) {
            //         cout << maxMove[i][j] << " ";
            //     }
            //     cout << "\n";
            // }
            // cout << "\n";
            for (int i = 0; i < n; i++) {
                if (maxMove[medicineCoordinate[i].first][medicineCoordinate[i].second] <= medicineSetter[i][j] && !checked[i]) {
                    toCheck.push(medicineCoordinate[i]);
                    checked[i] = true;
                }
            }
        }
    }
    print(possible ? "Yes" : "No");
}