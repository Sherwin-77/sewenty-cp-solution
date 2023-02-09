#include <iostream>
#include <sstream>
#include <vector>
#include <stack>

// From "MPC Bootcamp/Bootcamp II/spiderslow.cpp"

int main(){
    using namespace std;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    string input;
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
            vector<int> arr;
            stack<int> train;
            bool possible = true, isLine = false;
            istringstream ss(input);
            while(ss >> now){
                if(now == 0){
                    isLine = true;
                    break;
                }
                arr.push_back(now);
            }
            if(isLine) break;
            int i = 0;
            // cout << "BEGIN CHECK\n";
            for(int j = 1; j <= n; j++) {
                train.push(j);
                while(!train.empty() && train.top() == arr[i]) {
                    train.pop();
                    i++;
                }
            }
            if(train.empty()){
                cout << "Yes\n";
            } else {
                cout << "No\n";
            }
        }
        cout << '\n';
    }
}
