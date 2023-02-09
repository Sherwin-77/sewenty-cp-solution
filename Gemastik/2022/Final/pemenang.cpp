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
    vector<string> code(n);
    vector<int> score(n, 0);
    for(int i = 0; i < n; i++){
        cin >> code[i];
    }
    int sa, sb;
    for(int a = 0; a < n-1; a++){
        for(int b = a+1; b < n; b++){
            cin >> sa >> sb;
            if(sa > sb){
                score[a] += 3;
                score[b]--;
            } else if(sa < sb){
                score[a]--;
                score[b] += 3;
            } else {
                score[a]++;
                score[b]++;
            }
        }
    }
    int best = INT32_MIN;
    string winner;
    for(int i = 0; i < n; i++){
        if(score[i] > best){
            best = score[i];
            winner = code[i];
        }  else if(score[i] == best){
            if(code[i] < winner){
                best = score[i];
                winner = code[i];
            }
        }
    }
    cout << winner;
}