#include <iostream>
#include <string>

int main(){
    using namespace std;
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
	int t;
	cin >> t;
	for(int i = 1; i <= t; i++){
		int dp[51];
		int coorX[51], coorY[51];
		int n, x, y;
		string command;
		cin >> n;
		cin >> command;
		cin >> x >> y;
		coorX[0] = coorY[0] = 0;
		int distance = abs(x - coorX[0]) + abs(y - coorY[0]);
		dp[0] = distance;
		for(int j = 0; j < n; j++){
			dp[j+1] = dp[j];
			coorX[j+1] = coorX[j];
			coorY[j+1] = coorY[j];
			char current = command[j];
			switch(current)
			{
				case 'E':
					coorX[j+1]++;
					break;
				case 'N':
					coorY[j+1]++;
					break;
				case 'S':
					coorY[j+1]--;
					break;
				case 'W':
					coorX[j+1]--;
			}
			int distance = abs(x - coorX[j+1]) + abs(y - coorY[j+1]);
			dp[j+1] = min(dp[j+1], distance);
		}
		cout << "Case #" << i << ": " << dp[n] << '\n';
	}
}