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

// Abandoned: Will be continued later
int main(){
    using namespace std;
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    string s;
    while(cin >> s){
        vector<char> highest;
        for(char c: s){
            bool found = false;
            if(!found) highest.push_back(c);
            for(auto itr = highest.rbegin(); itr < highest.rend(); itr++){
                
            }
        }
    }
}