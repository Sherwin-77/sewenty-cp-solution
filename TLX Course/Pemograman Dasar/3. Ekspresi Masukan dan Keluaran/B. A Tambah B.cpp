#include <iostream>

int main(){
    using namespace std;
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    int a, b;
    cin >> a >> b;
    cout << a + b;
}