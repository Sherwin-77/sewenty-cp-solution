#include <iostream>
int piranha[100000];
int dp[1000001];


int main(){
    using namespace std;
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
	int n;
	for(int i = 0; i < n; i++){
		cin >> piranha[i];
	}
	dp[0] = 0;
	for(int i = 1; i < n + 1; i++){
		dp[i] = dp[i-1];
		
		
	}
}