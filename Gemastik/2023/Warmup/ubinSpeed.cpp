#include <iostream>
#include <vector>
#include <math.h>

template <typename T>
void debug(T const &value, std::string valueName)
{
    std::cout << "DEBUG VALUE " << valueName << ": " << value << '\n';
}

template <typename T>
void debug(T const &value, std::string valueName, long long index)
{
    std::cout << "DEBUG VALUE " << valueName << " INDEX " << index << ": " << value << '\n';
}

//--------------------------------------------------------------------
long long sum(const long long x, const long long y, const long long m)
{
    long long ans = x + y;
    if (ans < x || ans >= m)
        ans -= m;
    return ans;
}
long long dif(const long long x, const long long y, const long long m)
{
    long long ans = x - y;
    if (ans > x)
        ans += m;
    return ans;
}
bool check_ge_rounded_sqrt(const long long m, const long long r)
{
    return ((r >= 1ull << 32) || r * (r + 1) >= m);
}
bool check_le_rounded_sqrt(const long long m, const long long r)
{
    return (r == 0 || ((r <= 1ull << 32) && r * (r - 1) < m));
}
bool check_rounded_sqrt(const long long m, const long long r)
{
    return check_ge_rounded_sqrt(m, r) && check_le_rounded_sqrt(m, r);
}
long long rounded_sqrt(const long long m)
{
    long long r = floorl(.5 + sqrtl(m));
    if (!check_ge_rounded_sqrt(m, r))
        while (!check_ge_rounded_sqrt(m, ++r))
            ;
    else if (!check_le_rounded_sqrt(m, r))
        while (!check_le_rounded_sqrt(m, --r))
            ;
    return r;
}

long long prod_karatsuba_aux(const long long x, const long long N, const long long m0, const long long m)
{
    long long x1 = x / N;
    long long x0N = (x - N * x1) * N;
    if (m0 >= 0)
        return dif(x0N, x1 * (long long)m0, m);
    else
        return sum(x0N, x1 * (long long)-m0, m);
}
long long prod_karatsuba(const long long a, const long long b, const long long m)
{
    long long N = rounded_sqrt(m);
    long long m0 = m - N * N;
    long long x1 = a / N;
    long long x0 = a - N * x1;
    long long y1 = b / N;
    long long y0 = b - N * y1;
    long long x0y0 = sum(x0 * y0, 0, m);
    long long x0y1 = sum(x0 * y1, 0, m);
    long long x1y0 = sum(x1 * y0, 0, m);
    long long x1y1 = sum(x1 * y1, 0, m);
    return sum(prod_karatsuba_aux(sum(prod_karatsuba_aux(x1y1, N, m0, m), sum(x0y1, x1y0, m), m), N, m0, m), x0y0, m);
}
//--------------------------------------------------------------------


// https://stackoverflow.com/a/58205309
// Straight copy from java
void modmul2x2(long long *c, long long *a, long long *b, long long m)
{
    long long t[4];
    t[0] = ((a[0] * b[0]) + (a[1] * b[2])) % m;
    t[1] = ((a[0] * b[1]) + (a[1] * b[3])) % m;
    t[2] = t[1];
    t[3] = ((a[2] * b[1]) + (a[3] * b[3])) % m;
    c[0] = t[0];
    c[1] = t[1];
    c[2] = t[2];
    c[3] = t[3];
}
void modpow2x2(long long *c, long long *a, long long n, long long m)
{
    long long t[4];
    t[0] = a[0];
    c[0] = 1;
    t[1] = a[1];
    c[1] = 0;
    t[2] = a[2];
    c[2] = 0;
    t[3] = a[3];
    c[3] = 1;
    for (;;)
    {
        if ((n & 1) != 0)
            modmul2x2(c, c, t, m);
        n >>= 1;
        if (!n)
            break;
        modmul2x2(t, t, t, m);
    }
}
long long modfib(long long n, long long m)
{
    if (n <= 0)
        return 1;
    long long a[4] = {1, 1, 1, 0};
    modpow2x2(a, a, n, m);
    return a[0];
}

int main()
{
    using namespace std;
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    const long long MODULO = 1000000007;
    long long n;
    cin >> n;
    long long res = modfib(n, MODULO);
    cout << prod_karatsuba(res, res, MODULO);
}