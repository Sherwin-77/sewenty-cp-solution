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
void debug(T const &value, std::string valueName){
    cout << "DEBUG VALUE " << valueName << ": " << value << '\n';
}
template <typename T>
void debug(T const &value, std::string valueName, int index){
    cout << "DEBUG VALUE " << valueName << " INDEX " << index << ": " << value << '\n';
}

template <typename T>
void print(T const &value, bool newLine=false){
    cout << value;
    if(newLine) cout << '\n';
}


// Alternative
typedef long long ll;

pair<ll, ll> fibMod(ll n, ll m){
    if(n == 0) return {0, 1};
    // since C++17
    auto [a, b] = fibMod(n/2, m);
    // print(a, true);
    ll c = (a * ((b * 2 - a + m) % m)) % m;
    ll d = (((a * a) % m) + ((b * b) % m)) % m;
    if(n % 2 == 0) return {c, d};
    else return {d, (c + d) % m};
}

signed main(){
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    int t;
    cin >> t;
    // O(T* Log(N))
    for(int x = 1; x <= t; x++){
        ll f, m;
        cin >> f >> m;
        auto [res, tmp] = fibMod(f, m);
        if(res < 0) terminate();
        cout << "Case #" << x << ": " << res << '\n';
    }
}