#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
typedef long long ll;
const ll SIZE = 1000000;
bool saved[SIZE+1];


bool isPrime(long long number){
	return saved[number];
}

void preload(){
	for(int i = 2; i * i < SIZE; i++){
		if(isPrime(i)){
			for(int j = i*i; j < SIZE+1; j += i) saved[j] = false;
		}
	}
}

ll root(ll n){
    if(n < 0) terminate;
    ll a = 0;
    ll b = sqrt(n);
    ll res = -1;

    while(a <= b && res == -1){
        ll mid = (a + b)/2;
        if(mid * mid < n) a = mid + 1;
        else if(mid * mid > n) b = mid-1;
        else res = mid;
    }

    return res;
}


int main(){
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    fill(saved, saved+SIZE, true);
	preload();
	ll n, temp;
	cin >> n;
	for(ll i = 0; i < n; i++){
		cin >> temp;
        auto num = root(temp);
        if(temp == 1 || num == -1) cout << "NO\n";
        else cout << (isPrime(num) ? "YES\n" : "NO\n");
	}
}