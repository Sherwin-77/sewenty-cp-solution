#include <iostream>
#include <vector>

int main(){
    using namespace std;
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
	int n, m, temp;
	long long dp[1000001];
	vector<long long> arr;
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		cin >> temp;
		arr.push_back(temp);
		dp[i] = 0;
	}
	dp[n] = 0;
	long long high = -100;
	for(int i = 0; i < n; i++){
		high = max(high, arr[i]);
		int j = min(n, i+m);
		dp[j] = max(dp[j], arr[i] + dp[i]);
		dp[j] = max(dp[j-1], dp[j]);
	}
	cout << (high < 0 ? high:dp[n]);
}