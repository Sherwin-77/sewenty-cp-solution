#include <iostream>
#include <unordered_map>
#include <string>

// WA
int main()
{
    using namespace std;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int number;
    string n;
    cin >> n;
    // the idk approach
    unordered_map<char, int> shortcut = {
        {'6', 5},
        {'8', 6},
        {'9', 6}
    };
    int complexity =  0;
    char previous;
    for(auto c: n){
        if(c == '0'){
            complexity += 7;
            if(previous == '1') --complexity;
            continue;
        }
        auto it = shortcut.find(c);
        if(it != shortcut.end()) complexity += it->second;
        else complexity += (int) c - '0';
        previous = c;
    }
    cout << complexity << '\n';
}
