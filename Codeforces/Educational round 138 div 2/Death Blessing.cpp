#include <iostream>

int main()
{
    using namespace std;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t, n;
    long long tmp;
    cin >> t;
    for(int i = 0; i < t; i++){
        long long total = 0;
        long long reducer = 0;
        cin >> n;
        for(int j = 0; j < n; j++){
            cin >> tmp;
            total += tmp;
        }
        for(int j = 0; j < n; j++){
            cin >> tmp;
            reducer = max(reducer, tmp);
            total += tmp;
        }
        cout << total-reducer << '\n';
    }
}
