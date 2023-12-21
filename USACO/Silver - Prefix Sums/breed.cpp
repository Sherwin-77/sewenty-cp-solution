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

template <typename T>
void debug(T const &value, std::string valueName)
{
    cout << "DEBUG VALUE " << valueName << ": " << value << '\n';
}
template <typename T>
void debug(T const &value, std::string valueName, int index)
{
    cout << "DEBUG VALUE " << valueName << " INDEX " << index << ": " << value << '\n';
}

template <typename T>
void print(T const &value, bool newLine = true)
{
    cout << value;
    if (newLine)
        cout << '\n';
}

// Alternative
typedef long long ll;

signed main()
{
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    freopen("bcount.in", "r", stdin);
    freopen("bcount.out", "w", stdout);
    int n, q;
    int tmp;
    cin >> n >> q;
    vector<vector<ll>> arr(3, vector<ll>(n+1, 0));
    for (int i = 1; i <= n; i++)
    {
        cin >> tmp;
        tmp--;
        arr[tmp][i]++;
        arr[0][i] += arr[0][i - 1];
        arr[1][i] += arr[1][i - 1];
        arr[2][i] += arr[2][i - 1];
    }
    int a, b;
    for (int i = 0; i < q; i++)
    {
        cin >> a >> b;
        a--;
        cout << arr[0][b] - arr[0][a] << ' ' << arr[1][b] - arr[1][a] << ' ' << arr[2][b] - arr[2][a] << '\n';
    }
}