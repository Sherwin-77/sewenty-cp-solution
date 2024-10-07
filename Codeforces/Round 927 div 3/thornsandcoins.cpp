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
        string s;
        cin >> n;
        cin >> s;
        // Start at 0. Guranteed to be empty
        vector<ll> dp(n, -1);
        ll ans = 0;
        dp[0] = 0;
        for(int i = 0; i < n; i++){
            if(s[i] != '*' && dp[i] != -1){
                if(i+ 1 < n && s[i+1] != '*') dp[i+1] = max(dp[i+1], dp[i] + (s[i+1] == '@'));
                if(i + 2 < n && s[i+2] != '*') dp[i+2] = max(dp[i+2], dp[i] + (s[i+2] == '@'));
            }
            ans = max(ans, dp[i]);
        }
        print(ans);
    }
}