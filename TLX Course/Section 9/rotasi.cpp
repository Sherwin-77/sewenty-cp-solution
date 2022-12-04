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
    int n, m, placeholder;
    fastscan(n);
    fastscan(m);
    vector <vector<int>> arr;
    
    for(int i=0; i<n; i++){
        vector <int> d;
        for(int j=0; j<m; j++){
            fastscan(placeholder);
            d.push_back(placeholder);
        }
        arr.push_back(d);
    }

    for(int i=0; i<m; i++){
        for(int j=n-1; j>=0; j--){
            cout << arr[j][i] << ' ';
        }
        cout << '\n';
    }


}
