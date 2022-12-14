#include <iostream>
#include <cmath>

const int MODULO = 1e9+7;
unsigned long long dp[1001][2];


long long modularExponentiation(unsigned long long x, int y, int p){
	long long res = 1;
	x %= p;
	if (x==0) return 0;
	while(y > 0){
		if(y & 1) res = (res * x) % p;
		y /= 2;
		x = (x*x) % p;
	}
	return res;
}


int main(){
    using namespace std;
    ios_base::sync_with_stdio(false);

    cout.tie(NULL);
    cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	dp[0][0] = 1;
	dp[0][1] = 0;
	for(int i = 1; i <= n; i++){
		dp[i][0] = ((m-1) * (dp[i-1][0] + dp[i-1][1])) % MODULO;
		dp[i][1] = dp[i-1][0];
	}
	long long total = (dp[n][0] + dp[n][1] - (modularExponentiation((m-1), n, MODULO)) + MODULO) % MODULO;
	// Debug
	/*
	cout << dp[n][0] << '\n';
	cout << dp[n][1] << '\n';
	cout << dp[n][0] << '\n';
	*/
	cout << total % MODULO << '\n';
}