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
    ll n, k;
    fileIO("teamwork");
    cin >> n >> k;
    vector<ll> arr(n);
    vector<ll> dp(n+1, -1);
    dp[0] = 0;
    for(int i = 0; i < n; i++) cin >> arr[i];
    for(int i = 1; i <= n; i++){
        ll cumMax = arr[i-1];
        for(int ik = 0; ik < k && i + ik <= n; ik++){
            cumMax = max(cumMax, arr[i+ik-1]);
            dp[i+ik] = max(dp[i+ik], dp[i-1] + cumMax * (ik+1));
        }
    }
    cout << dp[n];
}