#include <iostream>
#include <vector>

int main(){
    using namespace std;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<bool> login (1001, false);
    int totalSus = 0;
    int n, tmp;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> tmp;
        int who = abs(tmp);
        if(!login[who] != !(tmp < 0)) totalSus++;
        login[who] = tmp > 0; 
    }
    cout << totalSus;
}
