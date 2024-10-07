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
typedef unsigned long long ull;


int mostSignificantBit(int n) {
    return n == 0 ? 0 : 1 << (31 - __builtin_clz(n));
}

class FenwickTree {
   private:
    vector<ll> tree;

   public:
    FenwickTree(int size) : tree(size, 0) {}

    ~FenwickTree() {}

    void add(int index, ll value) {
        index++;
        while (index <= tree.size()) {
            tree[index - 1] += value;
            index += index & -index;
        }
    }

    void set(int index, ll value) {
        add(index, value - sum(index, index));
    }

    ll sum(int index) {
        index++;
        ll s = 0;
        while (index >= 1) {
            s += tree[index - 1];
            index -= index & -index;
        }

        return s;
    }

    ll sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    // Return the 0 indexed index of largest prefix sum that is less than or equal to value
    int prefixSearch(int value) {
        int index = 0;
        int curSum = 0;
        int curBit = mostSignificantBit(tree.size());

        while (curBit > 0) {
            if (curBit + index <= tree.size() && curSum + tree[curBit + index - 1] <= value) {
                curSum += tree[curBit + index - 1];
                index += curBit;
            }

            curBit >>= 1;
        }

        return index - 1;
    }
};

signed main() {
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    /**
     * Problem description
     * N times slice
     * L initial size
     * Every item in N times slice, slice at index i by half
     */

    int n;
    ll l;

    cin >> n >> l;
    vector<ll> arr(n);
    vector<ll> res(n+1);

    for (int i = 0; i < n; i++) cin >> arr[i];

    FenwickTree ft (n+1);

    for (int i = 0; i <= n; i++) {
        ft.add(i, 1);
    }

    vector<int> locations(n+1);
    vector<vector<int>> dp(n+1, vector<int>());

    for (int i = n - 1; i >= 0; i--) {
        int index1 = ft.prefixSearch(arr[i] - 1) + 1;
        int index2 = ft.prefixSearch(arr[i]) + 1;

        ft.add(index2, -1);

        locations[i] = index1;
        dp[index1].push_back(index2);
    }
    res[0] = l;
    for (int i = 0; i < n; i++) {
        int toSplit = locations[i];
        int dest = dp[toSplit].back();
        dp[toSplit].pop_back();
        res[toSplit] /= 2;
        res[dest] = res[toSplit];
    }

    for (int i = 0; i <= n; i++) {
        cout << res[i] << ' ';
    }
}