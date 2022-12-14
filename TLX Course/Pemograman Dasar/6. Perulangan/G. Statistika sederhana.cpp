#include <iostream>

int main(){
    using namespace std;
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
	int small = INT32_MAX, big = INT32_MIN, n, temp;
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> temp;
		small = min(small, temp);
		big = max(big, temp);
	}
	cout << big << ' ' << small;
}