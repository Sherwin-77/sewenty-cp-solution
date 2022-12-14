#include <iostream>
const int MODULO =  1000000;

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
    int dp[1000];
    fill(dp, dp+1000, 0);
    
    /*
    base case: 
    3 x 1: 1
    3 x 2: 1
    3 x 3: 2
    Extend to:
    3 x 4: 3 (1+2)
    3 x 5: 4 (1+3)
    */
   dp[0] = 1;
   dp[1] = 1;
   dp[2] = 2;
   for(int i=3; i<1000; i++){
       dp[i] = (dp[i-1] + dp[i-3]) % MODULO;
   }
   int n;
   fastscan(n);
   cout << dp[n-1] << '\n';

}
