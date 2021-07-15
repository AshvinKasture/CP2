// #define ONLINE_JUDGE

#include <bits/stdc++.h>

#define ll long long int
#define ld long double

using namespace std;

void file_io()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

vector<ll> primes;

class Factor
{
public:
    ll prime, count;

    Factor(ll p, ll c)
    {
        prime = p;
        count = c;
    }
};

bool isPrime(ll n)
{
    for (ll i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

void prime_sieve(ll max_n)
{
    for (ll i = 2; i < max_n; i++)
    {
        if (isPrime(i))
        {
            primes.push_back(i);
        }
    }
}

ll get_powers(ll n, ll p)
{
    ll res = 0;
    for (ll power = p; power <= n; power *= p)
    {
        res += n / power;
    }
    return res;
}

bool divides_factorial(ll n, ll m)
{
    if (m == 0)
    {
        return false;
    }
    else if (n >= m)
    {
        return true;
    }
    else
    {
        ll k = m;
        vector<Factor> factors;
        for (ll i = 0; i < primes.size(); i++)
        {
            if (primes[i] > k)
            {
                break;
            }
            else
            {
                Factor f(primes[i], 0);
                while (k % primes[i] == 0)
                {
                    f.count++;
                    k /= primes[i];
                }
                if (f.count)
                {
                    factors.push_back(f);
                }
            }
        }

        if (k > 1)
        {
            if (n < k)
            {
                return false;
            }
            else
            {
                Factor f1(k, 1);
                factors.push_back(f1);
            }
        }
        for (ll i = 0; i < factors.size(); i++)
        {
            if (factors[i].count - get_powers(n, factors[i].prime) > 0)
            {
                return false;
            }
        }
        return true;
    }
}

int main()
{
    file_io();
    ll n, m;
    prime_sieve(5000);
    do
    {
        cin >> n >> m;
        if (divides_factorial(n, m))
        {
            cout << m << " divides " << n << endl;
        }
        else
        {
            cout << m << " does not divide " << n << endl;
        }
    } while (n != 1000 && m != 1009);
    return 0;
}