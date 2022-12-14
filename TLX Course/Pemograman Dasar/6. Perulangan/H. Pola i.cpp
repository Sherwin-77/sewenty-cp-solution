#include <iostream>

int main(){
    using namespace std;
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
	int end, stop;
	cin >> end >> stop;
	for(int i=1; i<=end; i++){
		if(i % stop == 0) cout << '*';
		else cout << i;
		if(i<end) cout << ' ';
	}
}