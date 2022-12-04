#include <iostream>


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
    // General solution
    int count = 0;
    bool sieve[1001];
    fill(sieve, sieve+1000, false);
    sieve[1] = true;
    sieve[2] = true;
    sieve[3] = true;

    for(int x=1; x*x <= 1000; x++){
        for(int y=1; y*y <= 1000; y++){
            // Main part
            int n = (4 * x * x) + (y * y);
            if (n <= 1000 && (n % 12 == 1 || n % 12 == 5))
                sieve[n] ^= true;
 
            n = (3 * x * x) + (y * y);
            if (n <= 1000 && n % 12 == 7)
                sieve[n] ^= true;
 
            n = (3 * x * x) - (y * y);
            if (x > y && n <= 1000 && n % 12 == 11)
                sieve[n] ^= true;
        }
    }
    for (int r = 5; r * r <= 1000; r++) {
        if (sieve[r]) {
            for (int i = r * r; i <= 1000; i += r * r)
                sieve[i] = false;
        }
    }
    int a, b;
    fastscan(a);
    fastscan(b);
    int res = 0;
    for (int i=a; i<=b; i++){
        res += (sieve[i]?0:1);
    }
    cout << res << '\n';

}
