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

int hungarian(std::vector<std::vector<int>> arr){
    // Return the minimum cost
    int n = arr.size();
    int m = arr[0].size();
    std::vector<int> u (n+1, 0), v (m+1, 0), p (m+1, 0), way (m+1, 0);
    for(int i = 1; i <= n; i++){
        p[0] = i;
        int j0 = 0;
        std::vector<int> minv(m+1, INT32_MAX);
        std::vector<bool> used(m+1, false);
        do {
            used[j0] = true;
            int i0 = p[j0];
            int delta = INT32_MAX;
            int j1;
            for(int j = 1; j <= m; ++j){
                if(!used[j]){
                    int cur = arr[i0-1][j-1] - u[i0] - v[j];
                    if(cur < minv[j]){
                        minv[j] = cur;
                        way[j] = j0;
                    }
                    if(minv[j] < delta){
                        delta = minv[j];
                        j1 = j;
                    }
                }
            }
            for(int j = 0; j <=m; ++j){
                if(used[j]){
                    u[p[j]] += delta;
                    v[j] -= delta;
                } else minv[j] -= delta;
            }
            j0 = j1;
        } while(p[j0] != 0);
        do {
            int j1 = way[j0];
            p[j0] = p[j1];
            j0 = j1;
        } while(j0);
    }
    int c = -v[0];
    return c;
    // std::vector<int> ans(n+1);
    // for(int i = 1; i <= m; ++i) ans[p[i]] = i;
    // return ans;
}

int main(){
    using namespace std;
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
}