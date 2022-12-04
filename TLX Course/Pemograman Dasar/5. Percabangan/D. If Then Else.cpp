#include <iostream>

int main(){
    using namespace std;
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    int number;
    cin >> number;
    if (number > 0){
        cout << "positif";
    } else if (number < 0){
        cout << "negatif";
    } else {
        cout << "nol";
    }
    
}