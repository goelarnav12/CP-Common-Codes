const int MAXN = 1e7+2;
 
// stores smallest prime factor for every number
int spf[MAXN];
 
// Calculating SPF (Smallest Prime Factor) for every
// number till MAXN.
// Time Complexity : O(nloglogn)
void sieve()
{
    spf[1] = 1;
    for (int i=2; i<MAXN; i++)
 
        // marking smallest prime factor for every
        // number to be itself.
        spf[i] = i;
 
    // separately marking spf for every even
    // number as 2
    for (int i=4; i<MAXN; i+=2)
        spf[i] = 2;
 
    for (int i=3; i*i<MAXN; i++)
    {
        // checking if i is prime
        if (spf[i] == i)
        {
            // marking SPF for all numbers divisible by i
            for (int j=i*i; j<MAXN; j+=i)
 
                // marking spf[j] if it is not
                // previously marked
                if (spf[j]==j)
                    spf[j] = i;
        }
    }
}
 
// A O(log n) function returning primefactorization
// by dividing by smallest prime factor at every step
map<int,int> getFactorization(int x)
{
    map<int,int> power;
    while (x != 1)
    {
        power[spf[x]]+=1;
        x = x / spf[x];
    }
    return power;
}

int totalFactors(int x)
{
    int ans = 1;
    map<int,int> m = getFactorization(int x);
    map<int,int> :: iterator = it;
    for(it=m.begin();it!=m.end();it++){
        ans*=((*it).ss+1);
    }
    return ans;
}
    
