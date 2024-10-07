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
        int k;
        string s;
        cin >> k;
        cin >> s;
        int res = 1;
        for (int currentMove = k; currentMove > 0; currentMove--) {
            bool complete = true;
            int parityCount = 0;
            queue<int> lastParityIndex;
            for (int i = 0; i < s.size(); i++) {
                if(parityCount > 0 && !lastParityIndex.empty()){
                    int lastParity = lastParityIndex.front();
                    if(i - lastParity >= currentMove){
                        parityCount--;
                        lastParityIndex.pop();
                    }
                }
                bool changed = parityCount % 2 == 1;
                char current = s[i];
                if (changed) current = (current == '0') ? '1' : '0';
                if (current == '0') {
                    // Check if its possible to swap again with length currentMove
                    if (i + currentMove <= s.size()) {
                        parityCount++;
                        lastParityIndex.push(i);
                    } else {
                        complete = false;
                        break;
                    }
                }
            }
            if(complete){
                res = currentMove;
                break;
            }
        }
        print(res);
    }
}