#include <iostream>
#include <vector>
#include <algorithm>


template <typename T>
void debug(T const &value, std::string valueName){
    std::cout << "DEBUG VALUE " << valueName << ": " << value << '\n';
}

template <typename T>
void debug(T const &value, std::string valueName, int index){
    std::cout << "DEBUG VALUE " << valueName << " INDEX " << index << ": " << value << '\n';
}


int main(){
    using namespace std;
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    int t;
    int n;
    int g;
    cin >> t;
    for(int x = 0; x < t; x++){
        cin >> n;
        vector<int> w(n);
        vector<int> p(n);
        for(int i = 0; i < n; i++) cin >> p[i] >> w[i];
        cin >> g;
        vector<int> mw(g);
        for(int i = 0; i < g; i++) cin >> mw[i];
        int res = 0;
        // TLDR: Spam knapsack for every person
        for(int cur: mw){
            vector<vector<int>> dp(n+1, vector<int> (cur+1, 0));
            for(int i = 1; i <= n; i++){
                for(int cw = 1; cw <= cur; cw++){
                    if(w[i-1] <= cw) dp[i][cw] = max(dp[i-1][cw-w[i-1]] + p[i-1], dp[i-1][cw]);
                    else dp[i][cw] = dp[i-1][cw];
                    // debug(dp[i][cw], "Current dp", i);
                }
            }
            res += dp[n][cur];
        }
        cout << res << '\n';
    }
}