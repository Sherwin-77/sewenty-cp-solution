#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

template <typename T>
void debug(T const &value, std::string valueName){
    std::cout << "DEBUG VALUE " << valueName << ": " << value << '\n';
}
template <typename T>
void debug(T const &value, std::string valueName, int index){
    std::cout << "DEBUG VALUE " << valueName << " INDEX " << index << ": " << value << '\n';
}

// This is why i hate vjudge
// Compiler error while running locally just fine

int main(){
    using namespace std;
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    string s;
    int a, b, c;
    while(cin >> a >> b >> c){
        vector<vector<string>> arr(a, vector<string>(b, ""));
        vector<vector<vector<bool>>> visited(a, vector<vector<bool>> (b, vector<bool> (c, false)));
        if(a == 0 && b == 0 && c == 0) break;
        queue<pair<int, pair<int, pair<int, int>>>> q;
        bool found = false;
        int res = 2147483647;
        for(int i = 0; i < a; i++){
            for(int j = 0; j < b; j++){
                cin >> arr[i][j];
                if(!found){
                    string s = arr[i][j];
                    for(int k = 0; k < s.length(); k++){
                        if(s[k] == 'S'){
                            q.push(make_pair(0, make_pair(i, make_pair(j, k))));
                            visited[i][j][k] = true;
                            found = true;
                            break;
                        }
                    }
                }
            }
        }
        while(!q.empty()){
            pair<int, pair<int, pair<int, int>>> element = q.front();
            q.pop();
            int dist = element.first;
            pair<int, pair<int, int>> selement = element.second;
            int level = selement.first;
            pair<int, int> telement = selement.second;
            int x = telement.first;
            int y = telement.second;
            if(level < a-1 && !visited[level+1][x][y] && arr[level+1][x][y] != '#'){
                if(arr[level+1][x][y] == 'E') res = min(res, dist+1);
                else {
                    q.push(make_pair(dist+1, make_pair(level+1, make_pair(x, y))));
                    visited[level+1][x][y] = true;
                }
            }
            if(x < b-1 && !visited[level][x+1][y] && arr[level][x+1][y] != '#'){
                if(arr[level][x+1][y] == 'E') res = min(res, dist+1);
                else {
                    q.push(make_pair(dist+1, make_pair(level, make_pair(x+1, y))));
                    visited[level][x+1][y] = true;
                }
            }
            if(y < c-1 && !visited[level][x][y+1] && arr[level][x][y+1] != '#'){
                if(arr[level][x][y+1] == 'E') res = min(res, dist+1);
                else {
                    q.push(make_pair(dist+1, make_pair(level, make_pair(x, y+1))));
                    visited[level][x][y+1] = true;
                }
            }
            if(level > 0 && !visited[level-1][x][y] && arr[level-1][x][y] != '#'){
                if(arr[level-1][x][y] == 'E') res = min(res, dist+1);
                else {
                    q.push(make_pair(dist+1, make_pair(level-1, make_pair(x, y))));
                    visited[level-1][x][y] = true;
                }
            }
            if(x > 0 && !visited[level][x-1][y] && arr[level][x-1][y] != '#'){
                if(arr[level][x-1][y] == 'E') res = min(res, dist+1);
                else {
                    q.push(make_pair(dist+1, make_pair(level, make_pair(x-1, y))));
                    visited[level][x-1][y] = true;
                }
            }
            if(y > 0 && !visited[level][x][y-1]&& arr[level][x][y-1] != '#'){
                if(arr[level][x][y-1] == 'E') res = min(res, dist+1);
                else {
                    q.push(make_pair(dist+1, make_pair(level, make_pair(x, y-1))));
                    visited[level][x][y-1] = true;
                }
            }
        }
        if(res == 2147483647) cout << "Trapped!\n";
        else cout << "Escaped in " << res << " minute(s).\n";
    }
}
