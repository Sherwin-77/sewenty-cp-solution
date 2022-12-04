#include <iostream>
#include <sstream>
#include <vector>
#include <stack>

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
            for(int j = 1; j <= n; j++){
                if(j != arr[i]){
                    if(!train.empty() && train.top() == arr[i]){
                        // cout << "Get element " << train.top() << '\n';
                        train.pop();
                        i++;
                    } else {
                        // cout << "Push element " << j << '\n';
                        train.push(j);
                    }
                } else i++;
            }
            while(!train.empty()){
                // cout << "Get element " << train.top() << '\n';
                int v = train.top();
                train.pop();
                if(v == arr[i++]) continue;
                cout << "No\n";
                break;
            }
            if(train.empty()) cout << "Yes\n";
            // cout << "END CHECK\n";
        }
        cout << '\n';
    }
}
