#include <iostream>
#include <vector>


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
    int n, m, p, placeholder;
    vector<vector <int>> matod, lawan;
    fastscan(n);
    fastscan(m);
    fastscan(p);
    for(int i=0; i<n; i++){
        vector <int> d;
        for(int j=0; j<m; j++){
            fastscan(placeholder);
            d.push_back(placeholder); 
        }
        matod.push_back(d);
    }

    for(int i=0; i<m; i++){
        vector <int> d;
        for(int j=0; j<p; j++){
            fastscan(placeholder);
            d.push_back(placeholder); 
        }
        lawan.push_back(d);
    }

    int res[m][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < p; k++) {
                res[i][j] += matod[i][k] * lawan[k][j];
    }
  }
}

    

}
