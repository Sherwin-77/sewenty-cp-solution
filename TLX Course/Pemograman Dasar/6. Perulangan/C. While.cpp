#include <iostream>
#include <string>

int main(){
    using namespace std;
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
	string line;
	while(getline(cin, line)){
		cout << line << '\n';
	}
}