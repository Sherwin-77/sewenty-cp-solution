#include <iostream>
#include <sstream>
#include <vector>

// Solution failed. refer spiderslow.cpp for solution

int main(){
    using namespace std;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    string input;
    vector<int> arr;
    while(getline(cin, input)){
        // cout << "DEBUG: " << input << '\n';
        int prev = -1, now;
        istringstream ss(input);
        ss >> n;
        // cout << "DEBUG: " << n << '\n';
        if(n == 0){
            break;
        }
        while(getline(cin, input)){
            bool possible = true, isLine = false;
            istringstream ss(input);
            while(ss >> now){
                if(now == 0){
                    isLine = true;
                    break;
                }
                if(prev-now > 1) possible = false;
                prev = now;
            }
            if(isLine) break;
            cout << (possible ? "Yes\n" : "No\n");
        }
        cout << '\n';
    }
}
