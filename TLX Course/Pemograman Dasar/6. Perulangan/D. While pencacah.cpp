#include <iostream>

int main(){
    using namespace std;
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
	int temp;
	int res = 0;
	while(cin >> temp){
		res += temp;
	}
	cout << res;
}