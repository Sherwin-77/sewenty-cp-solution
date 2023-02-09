#include <iostream>
#include <vector>

int main(){
    using namespace std;
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
	int n;
	vector<int> big;
	cin >> n;
	for(int i = 1; i * i <= n; i++){
		if(n % i == 0){
			cout << n/i << '\n';
			if (i != n/i) big.push_back(i);
		}
	}
	for(auto it = big.rbegin(); it != big.rend(); it++){
		cout << *it << '\n';
	}
}