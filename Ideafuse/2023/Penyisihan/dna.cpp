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

ll dp[199 + 1][500 + 1][20] = {};
ll stringCost[200 + 1][20] = {};
string arr[200+1] = {};

signed main() {
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    fill(&dp[0][0][0], &dp[0][0][0] + sizeof(dp) / sizeof(dp[0][0][0]), -1);
    int n, m, k;
    cin >> n >> m >> k;
    // for (int i = 0; i < 200; i++) {
    //     for (int j = 0; j < 500; j++) {
    //         for (int k = 0; k < 20; k++)
    //             if (dp[i][j][k] != -1) {
    //                 print("BREAK");
    //                 return 0;
    //             }
    //     }
    // }
    for (int i = 0; i < n; i++) cin >> arr[i];
    ll cumCost = 0;
    for (int i = 1; i < n; i++) {
        for(int offset = 0; offset < m; offset++){
            ll ret = 0;
            for (int j = 0; j < m; j++)
                ret += arr[i][(j+offset)%m] == arr[i-1][j];
            ret *= ret;
            stringCost[i][offset] = ret;
            if(offset == 0){
                cumCost += ret;
                dp[i][0][0] = cumCost;
            }
        }
    }

    for (int align = 0; align <= min(k, m-1); align++) dp[0][align][align] = 0; // No string to align
    ll best = cumCost;
    for (int line = 1; line < n; line++) {
        for (int align = 1; align <= k; align++) {
            for (int rt = 0; rt <= min(align, m-1); rt++) {  // Rotation of current line
                for (int cs = 0; cs <= min(align - rt, m-1); cs++) {  // Compare rotation of prev line
                    if (align - rt - cs < 0) terminate();
                    if (dp[line - 1][align - rt][cs] == -1) continue;
                    dp[line][align][rt] = max(dp[line][align][rt], dp[line - 1][align - rt][cs] + stringCost[line][(rt-cs+m)%m]); 
                    // cout << "Line: " << line+1 << " | Align: " << align << " | Rotate: " << rt << " | Compare : " << cs << '\n';
                    // print(dp[line][align][rt]);
                }
                if(line == n-1){
                    best = max(best, dp[line][align][rt]);
                }
            }
        }
    }
    cout << best;
}