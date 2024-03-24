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


signed main(){
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        vector<ll> arr(n);
        cin >> arr[0];
        ll initGcd = arr[0];
        for(int i = 1; i < n; i++){
            cin >> arr[i];
            initGcd = __gcd(initGcd, arr[i]);
            // cout << "test";
        } 
        if(initGcd == 1){
            cout << "0\n";
        } else {
            ll cost = 3;
            for(ll i = n-1; i >= n-2; i--){
                ll cur = n-i;
                ll tst = __gcd(arr[i], i+1);
                ll rs = __gcd(initGcd, tst);
                if(rs == 1) cost = min(cost, cur);
            }
            cout << cost << '\n';
        }
    }
}