#include <iostream>

int main(){
    using namespace std;
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
	int n;
	int counter = 0;
	cin >> n;
	for(int i = 0; i < n; i++){
		for(int j = 0; j <= i; j++){
			cout << counter;
			counter = (counter + 1) % 10;
		}
		cout << '\n';
	}
}