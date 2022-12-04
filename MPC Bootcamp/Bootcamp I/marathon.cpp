#include <iostream>

int main()
{
    using namespace std;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    int a, b, c, d;
    cin >> t;
    for(int i = 0; i < t; i++){
        int total = 0;
        cin >> a >> b >> c >> d;
        if(b > a) total++;
        if(c > a) total++;
        if(d > a) total++;
        cout << total << '\n';
    }
}
