#include <iostream>

int main(){
    using namespace std;
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
	int n, temp;
	int res = 0;
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> temp;
		res += temp;
	}
	cout << res;
}