#include <iostream>
#include <unordered_map>
#include <string>

std::string customFormat(long long number){
    std::string res = "";
    if(number >= 100){
        res += std::to_string(number/100);
    } else res += '0';
    res += '.';
    short decimal = number % 100;
    if(decimal < 10) res += '0';
    res += std::to_string(number % 100) + "$\n";
    return res;
}



int main()
{
    using namespace std;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t, n, line;
    long long cost;
    int temp;
    char tempc;
    string words;
    cin >> t;
    // for(int i = 0; i < t; i++){
    //     cin >> n;
    //     cout << customFormat(n);
    // }
    // return 0;
    for(int i = 0; i < t; i++){
        unordered_map<char, int> hashmap;
        cost = 0;
        cin >> n;
        for(int j = 0; j < n; j++){
            cin >> tempc >> temp;
            hashmap.insert(make_pair(tempc, temp));
        }
        cin >> line;
        getline(cin, words);
        for(int j = 0; j < line; j++){
            // cout << "Line " << j << ' ';
            getline(cin, words);
            // cout << words << '\n';
            for(auto c: words){
                auto itr = hashmap.find(c);
                if(itr != hashmap.end()) cost += itr->second;
            }
        }
        cout << customFormat(cost);
    }
}
