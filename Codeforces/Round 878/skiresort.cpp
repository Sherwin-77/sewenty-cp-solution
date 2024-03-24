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
    ll t;
    cin >> t;
    while (t--) {
        ll n, k, q;
        ll res = 0;
        cin >> n >> k >> q;
        vector<ll> arr(n);
        for (ll i = 0; i < n; i++) cin >> arr[i];
        ll cur = 0;
        for (auto x : arr) {
            if (x <= q) {
                cur++;
            } else {
                if (cur >= k) {
                    for (ll i = k;  i <= cur; i++) {
                        res += cur - i + 1;
                    }
                }
                cur = 0;
            }
        }
        if (cur >= k) {
            for (ll i = k; i <= cur; i++) {
                res += cur - i + 1;
            }
        }
        print(res);
    }
}