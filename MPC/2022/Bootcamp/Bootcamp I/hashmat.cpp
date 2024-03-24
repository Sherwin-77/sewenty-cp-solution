#include <iostream>


int main()
{
    using namespace std;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long a, b;
    while(cin >> a){
        cin >> b;
        cout << b-a << '\n';
    }
}
