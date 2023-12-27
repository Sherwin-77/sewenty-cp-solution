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
    ll t, n;
    cin >> t;
    while(t--){
        cin >> n;
        vector<vector<ll>> dp(n+1, vector<ll>(3+1, -1));
        vector<ll> arr(n+1);
        for(int i = 1; i <= n; i++) cin >> arr[i];
        dp[0][0] = 0;
        for(int i = 1; i <= n; i++){
            for(int k = 0; k <= 3; k++){
                dp[i][k] = max(dp[i][k], dp[i-1][k]);
                if(k == 1){
                    dp[i][k] = max(dp[i][k], dp[i-1][k-1] + arr[i] + i);
                } else if(k == 3){
                    dp[i][k] = max(dp[i][k], dp[i-1][k-1] + arr[i] - i);
                } else if(k > 0){
                    dp[i][k] = max(dp[i][k], dp[i-1][k-1] + arr[i]);
                }
            }
        }
        cout << dp[n][3] << '\n';
    }
}