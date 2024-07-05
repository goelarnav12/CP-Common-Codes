// number of 1's in binary representation
ll popcnt (ll x) { return __builtin_popcountll(x); }

// number of leading zeroes ... helpful for getting msb
void getZeroes(int n) {
    int k=__builtin_clz(n);
    // for msb do 1<<(63-k)
}

// gcd of numbers a and b
ll gcd (ll a, ll b) { return b ? gcd (b, a % b) : a; }


 int power( int x, int y, int p)
{
     int res = 1; // Initialize result

    x = x % p; // Update x if it is more than or
    // equal to p

    while (y > 0)
    {

        // If y is odd, multiply x with result
        if (y & 1)
            res = (res * x) % p;

        // y must be even now
        y = y >> 1; // y = y/2
        x = (x * x) % p;
    }
    return res;
}
 int modInverse( int n, int p)
{
    return power(n, p - 2, p);
}
 int mul( int x, int y, int p)
{
    return x * 1ull * y % p;
}
 int divide( int x, int y, int p)
{
    return mul(x, modInverse(y, p), p);
}
 int nCrModPFermat( int n,int r, int p)
{
    // If n<r, then nCr should return 0
    if (n < r)
        return 0;
    // Base case
    if (r == 0)
        return 1;
    // if n-r is less calculate nCn-r
    if (n - r < r)
        return nCrModPFermat(n, n - r, p);

    // Fill factorial array so that we
    // can find all factorial of r, n
    // and n-r
     int res = 1;
    // keep multiplying numerator terms and deviding denominator terms in res
    for (int i = r; i >= 1; i--)
        res = divide(mul(res, n - i + 1, p), i, p);
    return res;
}
