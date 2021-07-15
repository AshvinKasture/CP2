/* Vaclav Bohac (c) 2012 - Problem No. 10139 in C++ */

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include <queue>

using namespace std;
using std::queue;
using std::vector;

vector<int> primes;

struct factor
{
    int prime, count;
};

/* Returns true if n is prime. */
static bool isPrime(int n);

/* Tests if n!|m is true. */
static bool divides_factorial(const int n, const int m);

/* Prepares table of primes. */
static void prime_sieve(int max_n);

/* Returns power of factor in n!. */
static int get_powers(const unsigned long int n, const int p);

int main(void)
{
    int n, m;
    prime_sieve(50000);
    cin >> n >> m;
    if (divides_factorial(n, m))
    {
        printf("%d divides %d!\n", m, n);
    }
    else
    {
        printf("%d does not divide %d!\n", m, n);
    }
    return EXIT_SUCCESS;
}

static bool divides_factorial(const int n, const int m)
{
    cout << "Check division for " << n << " " << m << endl;

    if (m == 0)
    {
        cout << "m=0" << endl;
        return false;
    }
    else if (n >= m)
    {
        cout << "n>=m" << endl;
        return true;
    }
    else
    {
        int k = m;
        cout << "value of k is " << k << endl;
        vector<factor> factors;
        for (int i = 0; i < primes.size(); i++)
        {
            cout << "current prime considering is " << primes[i] << endl;
            if (primes[i] > k)
            {
                cout << "prime " << primes[i] << " is greater than k as " << k << endl;
                break;
            }
            else
            {
                factor f = {primes[i], 0};
                cout << "factor object is " << f.prime << " " << f.count << endl;
                while (k % primes[i] == 0)
                {
                    cout << " inside mod while loop" << endl;
                    cout << "k was " << k << " and f.count was " << f.count;
                    f.count += 1;
                    k = k / primes[i];
                    cout << " now k is " << k << " and f.count is " << f.count << endl;
                }

                if (f.count)
                {
                    cout << "f.count holds true for " << f.count << endl;
                    factors.push_back(f);
                    cout << "now factors size is " << factors.size() << endl;
                }
                else
                {
                    cout << "f.count fails for " << f.count << endl;
                }
            }
        }

        cout << "out of for loop considering all primes. k is " << k << endl;

        if (k > 1)
        { // k is a prime
            cout << " finally k is " << k << endl;
            if (n < k)
            {
                cout << "here n<k as n=" << n << " and k=" << k << endl;
                return false;
            }
            else
            {
                cout << "adding k,1 to factors" << endl;
                factors.push_back((factor){k, 1});
            }
        }
        cout << "factors size is " << factors.size() << endl;
        cout << "they are" << endl;
        for (int i = 0; i < factors.size(); i++)
        {
            cout << factors[i].prime << " " << factors[i].count << endl;
        }
        cout << endl;
        for (int i = 0; i < factors.size(); i++)
        {
            cout << "checking all factors. current factor is " << factors[i].prime << " " << factors[i].count << endl;
            cout << "get powers(" << n << ", " << factors[i].prime << ") gives the value " << get_powers(n, factors[i].prime) << endl;
            if (factors[i].count - get_powers(n, factors[i].prime) > 0)
            {
                return false;
            }
        }
        cout << "finally returning true" << endl;
        return true;
    }
}

static bool isPrime(int n)
{
    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

static void prime_sieve(int max_n)
{
    for (int i = 2; i < max_n; i++)
    {
        if (isPrime(i))
        {
            primes.push_back(i);
        }
    }
}

static int get_powers(const unsigned long int n, const int p)
{
    int res = 0;
    for (unsigned long int power = p; power <= n; power *= p)
    {
        res += n / power;
    }
    return res;
}