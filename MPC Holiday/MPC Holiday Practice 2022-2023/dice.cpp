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
    int n;
    cin >> n;
    int scoreA = 0, scoreB = 0;
    int a, b;
    for(int i = 0; i < n; i++){
        cin >> a >> b;
        if(a > b) scoreA++;
        else if(a < b) scoreB++;
    }
    if(scoreA > scoreB) cout << "Mishka";
    else if(scoreA < scoreB) cout << "Chris";
    else cout << "Friendship is magic!^^"; 
}