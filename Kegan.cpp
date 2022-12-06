#include <cmath>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <random>

using namespace std;

long gcd(long a, long h)
{
    long temp;
    while (1) {
        temp = a % h;
        if (temp == 0)
            return h;
        a = h;
        h = temp;
    }
}

long double encryptPow(long double base, long double exp, long double mod) {
    if (mod == 1)
        return 0;
    long double c = 1;
    for (int e = 0; e < exp; e++) {
        c = fmod((c * base), mod);
    }
    return c;
}

long double decryptPow(long double base, long double exp, long double mod) {
    if (mod == 1)
        return 0;
    long double m = 1;
    for (int e = 0; e < exp; e++) {
        m = fmod((m * base), mod);
    }
    return m;
}

long double encrypt(int msg, long e, long n)
{
    long double c = encryptPow(msg, e, n);
    return c;
}

long double decrypt(long double c, long double d, long double n)
{
    long double m = decryptPow(c, d, n);
    return m;
}

long p;
long q;

long getRandomPrimes()
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> QR(100, 1000);

    uniform_int_distribution<> PR(1001, 10000);

    srand((unsigned)time(0));

    p = PR(gen);
    bool is_prime = true;

    if (p == 0 || p == 1) {
        is_prime = false;
    }

    for (long i = 2; i <= p / 2; ++i)
    {
        if (p % i == 0) {
            is_prime = false;
            break;
        }
    }

    while (is_prime == false)
    {
        is_prime = true;
        p = PR(gen);

        if (p == 0 || p == 1)
        {
            is_prime = false;
        }
        for (long i = 2; i <= p / 2; ++i)
        {
            if (p % i == 0)
            {
                is_prime = false;
                break;
            }
        }
    }

    q = QR(gen);

    if (q == 0 || q == 1) {
        is_prime = false;
    }

    for (long i = 2; i <= q / 2; ++i)
    {
        if (q % i == 0) {
            is_prime = false;
            break;
        }
    }

    while (is_prime == false and q != p)
    {
        is_prime = true;
        q = QR(gen);

        if (q == 0 || q == 1)
        {
            is_prime = false;
        }
        for (long i = 2; i <= q / 2; ++i)
        {
            if (q % i == 0)
            {
                is_prime = false;
                break;
            }
        }
    }
    return (p, q);
}
int main()
{
    int msg;

    getRandomPrimes();

    long n = p * q;

    long e = 2;
    long phi = (p - 1) * (q - 1);

    while (e < phi)
    {
        if (gcd(e, phi) == 1)
            break;
        else
            e++;
    }

    long k = 2;
    long d = 3;

    while (fmod(d * e, phi) != 1)
    {
        d++;
    }

    long double c = encrypt(msg, e, n);

    cout << "Encrypted Msg (c): " << c << endl;

    long double m = decrypt(c, d, n);

    cout << "Decrypted Msg (M): " << m << endl;

    return 0;
}