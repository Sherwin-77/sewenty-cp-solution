#include <iostream>

int main(){
    using namespace std;
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    int number;
    cin >> number;
    if(number > 0 && number % 2 == 0){
        cout << number;
    }
}