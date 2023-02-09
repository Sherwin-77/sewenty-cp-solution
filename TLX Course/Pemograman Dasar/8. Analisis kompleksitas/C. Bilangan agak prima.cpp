#include <iostream>

const int SIZE = 1000000;
int saved[SIZE+1];


bool isPrime(int number){
	return saved[number] < 4;
}

void preload(){
	for(int i = 2; i * i < SIZE; i++){
		if(isPrime(i)){
			for(int j = i*i; j < SIZE+1; j += i) saved[j]++;
		}
	}
}


int main(){
    using namespace std;
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
	fill(saved, saved+SIZE, 2);
	preload();
	int n, temp;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> temp;
		cout << (isPrime(temp) ? "YA\n" : "BUKAN\n");
	}
}