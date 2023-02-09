#include <iostream>

int main(){
    using namespace std;
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
	int n;
	int price[1000001];
	int profit = 0;
	int totalProfit = 0;
	int takenPrice = 0;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> price[i];
		if(takenPrice == 0){
			takenPrice = price[i];
			continue;
		}
		int curProfit = price[i] - takenPrice;
		if(curProfit > profit) profit = curProfit;
		else {
			totalProfit += profit;
			takenPrice = price[i];
			profit = 0;
		}
	}
	if(profit > 0) totalProfit += profit;
	cout << totalProfit;
}