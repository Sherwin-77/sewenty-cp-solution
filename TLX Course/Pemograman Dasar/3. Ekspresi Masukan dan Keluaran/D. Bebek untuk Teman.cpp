#include <iostream>

int main(){
    using namespace std;
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    int ducks, number;
    cin >> ducks >> number;
    cout << "masing-masing " << ducks / number << '\n';
    cout << "bersisa " << ducks % number;
}