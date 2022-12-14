#include <iostream>
#include <vector>
#include <algorithm>


template <typename T>
void debug(T const &value, std::string valueName){
    std::cout << "DEBUG VALUE " << valueName << ": " << value << '\n';
}

template <typename T>
void debug(T const &value, std::string valueName, int index){
    std::cout << "DEBUG VALUE " << valueName << " INDEX " << index << ": " << value << '\n';
}


int main(){
    using namespace std;
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    string s;
    int total = 0;
    while(cin >> s){
        int first = 0;
        int last = s.size()-1;
        vector<short> what (52, 0);
        while(first < last){
            int a = s[first]-'a';
            if(a < 0) a = 58 - abs(a);
            int b = s[last]-'a';
            if(b < 0) b = 58 - abs(b);
            if(what[a] == 2){
                // debug(s[first], "Letter");
                total += a + 1;
                break;
            }
            what[a] = 1;
            if(what[b] == 1){
                // debug(s[last], "Letter");
                total += b + 1;
                break;
            }
            what[b] = 2;
            first++;
            last--;
        }
    }
    cout << total;
}