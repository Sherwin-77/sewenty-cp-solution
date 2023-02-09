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


long long bruteForce(std::vector<long long> arr, std::vector<long long> sorted){
	int n = arr.size();
	std::vector<std::vector<long long>> dp(n+1, std::vector<long long> (n+1, 0));
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			dp[i][j] = dp[i-1][j] + abs(sorted[j-1]-arr[i-1]);
			if(j > 1) dp[i][j] = std::min(dp[i][j-1], dp[i][j]);
			// std::cout << i << ' ' << j << '\n';
			// debug(dp[i][j], "DP value");
		}
	}
	return dp[n][n];
}


int main(){
    using namespace std;
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
	int t, n;
	cin >> t;
	for(int i = 1; i <= t; i++){
		cin >> n;
		vector<long long> arr(n);
		vector<long long> sorted(n);

		for(int j = 0; j < n; j++){
			cin >> arr[j];
			sorted[j] = arr[j];
		}
		sort(sorted.begin(), sorted.end());
		long long ans = bruteForce(arr, sorted);
		// debug(ans, "answer 1");
		for(int j = 0; j + j < n; j++) swap(sorted[j], sorted[n-j-1]);
		cout << "Case #" << i << ": " << min(ans, bruteForce(arr, sorted)) << '\n';
	}
}