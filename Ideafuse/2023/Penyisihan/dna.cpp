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
    cout << "DEBUG VALUE " << valueName << " INDEX " << index << ": " << value << '\n';
}

template <typename T>
void print(T const &value, bool newLine = true) {
    cout << value;
    if (newLine) cout << '\n';
}

// Alternative
typedef long long ll;

ll compareStr(string &str1, string &str2) {
    ll ret = 0;
    for (int i = 0; i < min(str1.length(), str2.length()); i++) ret += str1[i] == str2[i];
    return ret * ret;
}

ll dp[199 + 1][500 + 1][20 + 1] = {};
string resultString[200 + 1][20 + 1] = {};

// FIXME: Still WA
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
    for (int i = 0; i < n; i++) cin >> resultString[i][0];
    ll cur = 0;
    for (int i = 0; i < n; i++) {
        if(i > 0){
            ll lineCost = compareStr(resultString[i - 1][0], resultString[i][0]);
            cur += lineCost;
            dp[i][0][0] = cur;
        }
        string curStr = resultString[i][0];
        for (int rt = 1; rt <= min(k, m); rt++) {
            rotate(curStr.begin(), curStr.begin() + 1, curStr.end());
            resultString[i][rt] += curStr;  // Dat array bug is crazy
            if(i == 0) print(resultString[i][rt]);
        }
    }
    for(int align = 0; align <= k; align++) dp[0][align][align] = 0;
    for (int line = 1; line < n; line++) {
        for (int align = 0; align <= k; align++) {
            for (int rt = 0; rt <= min(align, m); rt++) {           // Rotation of current line
                for (int cs = 0; cs <= min(align - rt, m); cs++) {  // Compare rotation of prev line
                    if (align - rt - cs < 0) terminate();
                    if (dp[line - 1][align - rt][cs] == -1) continue;
                    ll cur = compareStr(resultString[line - 1][cs], resultString[line][rt]);
                    dp[line][align][rt] = max(dp[line][align][rt], dp[line - 1][align - rt][cs] + cur);
                    // cout << "Line: " << line << " | Align: " << align << " | Rotate: " << rt << " | Compare : " << cs << '\n';
                    // print(dp[line][align][rt]);
                }
            }
        }
    }
    ll best = 0;
    for (int i = 0; i <= min(k, m); i++) {
        for (auto x : dp[n - 1][i]) best = max(best, x);
    }
    print(best);
}