#include <iostream>
#include <cmath>

int main(){
    using namespace std;
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
	int n;
	cin >> n;
	while(n % 2 == 0){
		n /= 2;
	}
	cout << ((n == 1) ? "ya" : "bukan");
	
	// Log approach
	/*
	double n;
	cin >> n;
	double res = log2(n);
	if(res == (int)res) cout << "ya";
	else cout << "bukan";
	*/
}