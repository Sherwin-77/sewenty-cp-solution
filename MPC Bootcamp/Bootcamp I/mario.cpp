#include <iostream>


int main()
{
    using namespace std;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t, n;
    int temp;
    cin >> t;
    for(int i = 1; i <= t; i++){
        cin >> n;
        int current = 0;
        int high = 0, low = 0;
        for(int j = 0; j < n; j++){
            cin >> temp;
            if(j == 0){
                current = temp;
                continue;
            } 
            if(current < temp) high++;
            if(current > temp) low++;
            current = temp;
        }
        cout << "Case " << i << ": " << high << ' ' << low << '\n';
    }
}
