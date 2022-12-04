#include <iostream>


bool isPalindrome(std::string txt, int first, int last){
    if(first == last) return true;
    while(first < last){
        if(txt[first++] != txt[last--]) return false; 
    }
    return true;
}

int main(){
    using namespace std;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    cin >> s;
    for(int split = 0; split < s.length()-1; split++){
        if(isPalindrome(s, 0, split) && isPalindrome(s, split+1, s.length()-1)){
            cout << s.substr(0, split+1) << ' ' << s.substr(split+1, s.length()-split);
            return 0; 
        }
    }
    cout << "NO";
}
