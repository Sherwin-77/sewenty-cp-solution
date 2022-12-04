#include <iostream>
int main()
{
    using namespace std;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t, boardSize, n;
    int x, y;
    // bool checkedX[8], checkedY[8];
    cin >> t;
    for(int i = 0; i < t; i++){
        cin >> boardSize >> n;
        for(int j = 0; j < n; j++){
            cin >> x >> y;
        }
        cout << (boardSize > n ? "YES\n":"NO\n");
    }
}
