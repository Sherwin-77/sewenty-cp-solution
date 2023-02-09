#include <iostream>
#include <vector>

int main(){
    using namespace std;
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
	short n;
	short q;
	unsigned long long k, l;
	string stringL;
	short a, b;
	string tempS;
	size_t sz;
	vector<string> magic;
	cin >> n;
	for(short i = 0; i < n; i++){
		cin >> tempS;
		magic.push_back(tempS);
	}
	cin >> q;
	for(short i = 0; i < q; i++){
		cin >> k >> stringL;
		l = stoull(stringL, &sz)
		for(int j = 0; j < k; j++){
			cin >> a >> skip >> b;
			cout << "A value: " << a << '\n';
			cout << "B value: " << b << '\n';
		}
	}
}