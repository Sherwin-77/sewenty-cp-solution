#include <iostream>
#include <vector>

typedef long long ll;
const int MODULO = 998244353;

void fastscan(int &number)
{
    bool negative = false;
    register int c;
  
    number = 0;

    c = getchar();
    if (c=='-')
    {
        negative = true;
  
        c = getchar();
    }
  
    for (; (c>47 && c<58); c=getchar())
        number = number *10 + c - 48;
  
    if (negative)
        number *= -1;
}

int main()
{
    using namespace std;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector <int> natal;
    int n, placeholder;   
    fastscan(n);
    // a ^ a = 0
    // n <= Ai <= 2000
    if(n > 2000){
        cout << 0 << '\n';
        return 0;
    }
    bool visited[2000];
    fill(visited, visited+2000, false);
    for(int i=0; i<n; i++){
        fastscan(placeholder);
        if (visited[placeholder-1]){
            cout << 0 << '\n';
            return 0;
        }
        visited[placeholder-1] = true;
        natal.push_back(placeholder);
    }
    ll res = 1;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            ll x = natal[i] ^ natal[j];
            res *= x;
            res %= MODULO;
        }
    }
    cout << res << '\n';

}
