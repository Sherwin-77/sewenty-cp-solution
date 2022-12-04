#include <iostream>


int main(){
    using namespace std;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    for(int x = 0; x < t; x++){
        int n, temp;
        int count = 1, cur;
        int opCount = 0;
        int opIndex = -1;
        cin >> n;
        cin >> cur;
        for(int i = 1; i < n; i++){
            cin >> temp;
            if(temp != cur){
                if(opIndex == -1) opIndex = i;
                opCount++;
            } else count++;
            if((count > 1 || opCount > 1) && (count > 0 && opCount > 0)){
                cout << ((count < opCount) ? 1 : opIndex+1) << '\n';
                for(int j = i+1; j < n; j++) cin >> temp;
                break;
            }
        }
    }
}
