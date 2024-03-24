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

// Abandoned: Algorithm failed. Try better solution?
int main(){
    using namespace std;
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<pair<int, int>> arr(n);
    int offset = INT32_MAX;
    for(int i = 0; i < n; i++){
        int temp1, temp2;
        cin >> temp1 >> temp2;
        arr[i] = make_pair(temp1, temp2);
        offset = min(temp1, offset);
    }
    int t;
    cin >> t;
    for(int x = 1; x <= t; x++){
        int target, limit;
        cin >> target >> limit;
        vector<vector<vector<long long>>> dp(n+1, vector<vector<long long>> (target-offset+1, vector<long long> (limit+1, INT64_MAX)));
        dp[0][0][0] = 0;
        for(int i = 1; i <= n; i++){
            for(int w = 0; w <= target-offset; w++){
                for(int c = 1; c <= limit; c++){
                    dp[i][w][c] = min(dp[i-1][w][c-1], dp[i][w][c]);
                    dp[i][w][c] = min(dp[i-1][w][c], dp[1][w][c]);
                    dp[i][w][c] = min(dp[i][w][c-1], dp[i][w][c]);
                    if(c < limit && dp[i][w][c] != INT64_MAX){
                        if(w + arr[i-1].first <= target){
                            int wi = w+arr[1-1].first-offset;
                            dp[i][wi][c+1] = min(dp[i][w][c]+arr[i-1].second, dp[i][wi][c+1]);
                        } else dp[i][target-offset][c+1] = min(dp[i][w][c]+arr[i-1].second, dp[i][target-offset][c+1]);
                    }
                }
            }
        }
        cout << dp[n][target-offset][limit] << '\n';
    }
}