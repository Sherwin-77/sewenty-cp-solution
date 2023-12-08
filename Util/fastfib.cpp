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

// Source code: https://www.nayuki.io/page/fast-fibonacci-algorithms
// Returns the tuple (F(n), F(n+1))
pair<ll, ll> fib(ll n){
    if(n == 0) return {0, 1};
    // since C++17
    auto [a, b] = fib(n/2);
    ll c = a * (b * 2 - a);
    ll d = a * a + b * b;
    if(n % 2 == 0) return {c, d};
    else return {d, c + d};
}


signed main(){
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
}