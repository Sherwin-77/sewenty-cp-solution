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

    int t;
    cin >> t;
    while (t--) {
        int n;
        bool tmp;
        cin >> n;
        vector<bool> hasEnemyPawn(n, false);
        vector<bool> hasAlliesPawn(n, false);
        string s;
        cin >> s;
        for (int i = 0; i < n; i++) hasEnemyPawn[i] = s[i] == '1';
        cin >> s;
        for (int i = 0; i < n; i++) hasAlliesPawn[i] = s[i] == '1';
        int ans = 0;
        vector<bool> taken(n, false);
        for (int i = 0; i < n; i++) {
            if (!hasAlliesPawn[i]) continue;
            // debug(hasAlliesPawn[i], "hasAlliesPawn", i);
            if (!hasEnemyPawn[i]) {
                taken[i] = true;
                ans++;
            } else {
                if (i > 0 && !taken[i - 1] && hasEnemyPawn[i - 1]) {
                    taken[i - 1] = true;
                    ans++;
                } else if (i < n - 1 && !taken[i + 1] && hasEnemyPawn[i + 1]) {
                    taken[i + 1] = true;
                    ans++;
                }
            }
        }
        print(ans);
    }
}