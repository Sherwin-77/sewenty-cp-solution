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
    int counter = 0;
    vector<vector<bool>> what;
    while(cin >> s){
        int first = 0;
        int last = s.size()-1;
        if(counter == 0) what = vector<vector<bool>> (2, vector<bool> (52, false));
        for(char c: s){
            int i = c-'a';
            if(i < 0) i = 58 - abs(i);
            if(counter < 2) what[counter][i] = true;
            if(counter == 2 && what[0][i] && what[1][i]){
                total += i+1;
                break;
            }
        }
        counter = (counter + 1) % 3;
    }
    cout << total;
}