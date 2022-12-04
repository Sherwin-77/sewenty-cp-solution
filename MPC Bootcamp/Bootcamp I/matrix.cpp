#include <iostream>

int main()
{
    using namespace std;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int temp;

    for(int row = 1; row <= 6; row++){
        for(int col = 1; col <= 5; col++){
            cin >> temp;
            if(temp == 1){
                // cout << "Row: " << row << ' ' << "Col: " << col << '\n';
                cout << (abs(row-3) + abs(col-3));
                return 0;
            }
        }
    }
}
