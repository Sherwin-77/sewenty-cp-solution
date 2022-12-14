#include <iostream>
#include <vector>


const int SIZE = 200000;
bool isPrime[SIZE + 1];
unsigned long long dp[SIZE + 1];
vector<int> modWindows;
dp[1] = 1;
fill(isPrime, isPrime+SIZE, true);


void preLoad(){
	for(int i = 2; i * i < SIZE; i++){
		if isPrime(i){
			for(int j = i*i; j < SIZE+1; j += i) isPrime[j] = false;
			
		}
	}
}

void preCount(unsigned long long MODULO){
	for(int i = 2; i < SIZE+1; i++){
		
	} 
}

int main(){
    using namespace std;
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
	preLoad();
	int t, temp;
	unsigned long long MODULO;
	cin >> t >> MODULO;
	preCount(MODULO);
	for(int i = 0; i < t; i++){
		cin >> temp;
		cout << dp[temp] << '\n';
	}
}