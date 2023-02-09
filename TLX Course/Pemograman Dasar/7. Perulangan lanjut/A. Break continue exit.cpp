#include <iostream>

int main(){
    using namespace std;
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++){
		if(i % 10 == 0) continue;
		if(i >= 42){
			cout << "ERROR";
			break;
		}
		cout << i << '\n';
	}
}