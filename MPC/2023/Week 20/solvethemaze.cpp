#include <iostream>
#include <algorithm>
#include <bitset>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <deque>
#include <queue>
#include <stack>
#include <string>

using namespace std;
// #define int long long

void fileIO(string fileName, string inExt=".in", string outExt=".out"){
    string fIn = fileName + inExt;
    string fOut = fileName + outExt; 
    freopen(fIn.c_str(), "r", stdin);
    freopen(fOut.c_str(), "w", stdout);
}

template <typename T>
void debug(T const &value, std::string valueName){
    cout << "DEBUG VALUE " << valueName << ": " << value << '\n';
}
template <typename T>
void debug(T const &value, std::string valueName, int index){
    cout << "DEBUG VALUE " << valueName << " INDEX " << index << ": " << value << '\n';
}

template <typename T>
void print(T const &value, bool newLine=true){
    cout << value;
    if(newLine) cout << '\n';
}


// Alternative
typedef long long ll;
typedef unsigned long long ull;

const ll DEFAULTMOD = 1000000007;

signed main(){
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<string> arr(n);
        queue<pair<int, int>> bads;
        int goods = 0;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            for (int j = 0; j < m; j++) {
                if (arr[i][j] == 'B') {
                    bads.push({i, j});
                } else if (arr[i][j] == 'G') {
                    goods++;
                }
            }
        }

        bool possible = true;
        while (!bads.empty()) {
            auto [i, j] = bads.front();
            bads.pop();
            // If there is a bad cell, then th cells around it must be empty
            if (i > 0) {
                if (arr[i - 1][j] == 'G') {
                    possible = false;
                    break;
                }
                if (arr[i - 1][j] == '.') {
                    arr[i - 1][j] = '#';
                }
            }
            if (i < n - 1) {
                if (arr[i + 1][j] == 'G') {
                    possible = false;
                    break;
                }
                if (arr[i + 1][j] == '.') {
                    arr[i + 1][j] = '#';
                }
            }
            if (j > 0) {
                if (arr[i][j - 1] == 'G') {
                    possible = false;
                    break;
                }
                if (arr[i][j - 1] == '.') {
                    arr[i][j - 1] = '#';
                }
            }
            if (j < m - 1) {
                if (arr[i][j + 1] == 'G') {
                    possible = false;
                    break;
                }
                if (arr[i][j + 1] == '.') {
                    arr[i][j + 1] = '#';
                }
            }
        }

        if (goods == 0) {
            print("Yes");
            continue;
        }

        if (!possible) {
            print("No");
            continue;
        }

        // If all the bad cells are removed, then the good cells must be reachable to end (n, m)
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        queue<pair<int, int>> q;

        // Blocked exit. No need to check
        if (arr[n-1][m-1] == '#') {
            print("No");
            continue;
        }

        q.push({n - 1, m - 1});
        visited[n - 1][m - 1] = true;
        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();
            if (arr[i][j] == 'G') {
                goods--;
            }
            if (i > 0 && arr[i - 1][j] != '#' && !visited[i - 1][j]) {
                visited[i - 1][j] = true;
                q.push({i - 1, j});
            }
            if (i < n - 1 && arr[i + 1][j] != '#' && !visited[i + 1][j]) {
                visited[i + 1][j] = true;
                q.push({i + 1, j});
            }
            if (j > 0 && arr[i][j - 1] != '#' && !visited[i][j - 1]) {
                visited[i][j - 1] = true;
                q.push({i, j - 1});
            }
            if (j < m - 1 && arr[i][j + 1] != '#' && !visited[i][j + 1]) {
                visited[i][j + 1] = true;
                q.push({i, j + 1});
            }
        }

        cout << (goods == 0 ? "Yes" : "No") << '\n';
    }

}