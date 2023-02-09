#include <iostream>
#include <string>

int main(){
    using namespace std;
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
	int n;
	cin >> n;
	string space, star;
	for(int i = 1; i <= n; i++){
		space = string(n-i, ' ');
		star = string(i, '*');
		cout << space << star << '\n';
	}
}