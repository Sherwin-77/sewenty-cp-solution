#include <iostream>
#include <set>
#include <math.h>

int main(){
    using namespace std;
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
	int n, x, temp, range;
	int curRange = INT32_MAX;
	
	cin >> n >> x;
	set<int, less<int>> arr;
	for(int i = 0; i < n; i++){
		cin >> temp;
		range = abs(x - temp);
		
		if(range < curRange){
			curRange = range;
			arr.clear();
			arr.insert(temp);
		}
		if(range == curRange){
			arr.insert(temp);
		}
	}
	for(auto n: arr){
		int digit = log10(n);
		string antiWA(4-digit, '0');
		cout << antiWA << n << '\n';
	}
}