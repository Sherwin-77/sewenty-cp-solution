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


bool isPalindrome(std::string s){
    int i = 0;
    int j = s.size()-1;
    while(i < j){
        if(s[i++] != s[j--]){
            return false;
        }
    }
    return true;
}

int main(){
    using namespace std;
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    string s;
    cin >> s;
    int j = s.size()-1;
    bool res = isPalindrome(s);
    if(!res){
        while(s[j] == '0') j--;
        // debug(s.substr(0, j+1), "Sub");
        if(j < s.size()-1) res = isPalindrome(s.substr(0, j+1));
    }
    cout << (res ? "Yes":"No");
}