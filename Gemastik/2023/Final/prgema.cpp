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
const ll MOD = 1000000007;

ll modPow(ll a, ll b){
    if(b == 0) return 1;
    ll res = modPow(a, b / 2);
    res = (res * res) % MOD;
    if(b % 2) res = (res * a) % MOD;
    return res;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    // a > 1 = (a * (1 - a^k) / (1 - a)^2) - (k * a^(k+1) / (1 - a))
    // a = 1 = (k * (k+1))/2
    // Rev 1 
    // res = (a * (1 - modPow(a, k)) / modPow(1-a, 2)) - (k * modPow(a, k+1) / (1 - a));
    ll a, k;
    cin >> a >> k;
    a %= MOD;
    ll res = 0;
    if(a == 1) res = (((k % MOD) * ((k+1) % MOD)) % MOD) / 2;
    else res = (a * (1 - modPow(a, k)) / modPow(1-a, 2)) - ((k % MOD == 0 ? MOD : k) * modPow(a, k+1) / (1 - a));
    if(res < 0) terminate();
    print(res % MOD);
}