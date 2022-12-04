#include <iostream>


int main(){
    using namespace std;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    if(n == 1 || n == 2){
        cout << "NO";
        return 0;
    }
    cout << (n % 2 == 0? "YES":"NO");
}
