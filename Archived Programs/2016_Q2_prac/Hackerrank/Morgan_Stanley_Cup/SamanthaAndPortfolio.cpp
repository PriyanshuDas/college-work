#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define ll long long int
#define pb push_back
#define mp make_pair

using namespace std;
class Fraction {
    private:
        // Calculates the greates common divisor with
        // Euclid's algorithm
        // both arguments have to be positive
        long long gcd(long long a, long long b)
        {
            if(b == 0)
                return a;
            return gcd(b, a%b);
        }

    public:
        long long numerator, denominator;

        Fraction() {
            numerator = 0;
            denominator = 1;
        }

        Fraction(long long n, long long d) {
            if (d==0) {
                cerr << "Denominator may not be 0." << endl;
                exit(0);
            } else if (n == 0) {
                numerator = 0;
                denominator = 1;
            } else {
                int sign = 1;
                if (n < 0) {
                    sign *= -1;
                    n *= -1;
                }
                if (d < 0) {
                    sign *= -1;
                    d *= -1;
                }

                long long tmp = gcd(n, d);
                numerator = n/tmp*sign;
                denominator = d/tmp;
            }
        }

        operator int() {return (numerator)/denominator;}
        operator float() {return ((float)numerator)/denominator;}
        operator double() {return ((double)numerator)/denominator;}
        void reduce()
        {
            long long g = gcd(numerator, denominator);
            numerator /= g; denominator /= g;
        }
};

Fraction operator+(const Fraction& lhs, const Fraction& rhs) {
    Fraction tmp(lhs.numerator*rhs.denominator
                +rhs.numerator*lhs.denominator,
                lhs.denominator*rhs.denominator);
    return tmp;
}

Fraction operator+=(Fraction& lhs, const Fraction& rhs) {
    Fraction tmp(lhs.numerator*rhs.denominator
                +rhs.numerator*lhs.denominator,
                lhs.denominator*rhs.denominator);
    lhs = tmp;
    return lhs;
}

Fraction operator-(const Fraction& lhs, const Fraction& rhs) {
    Fraction tmp(lhs.numerator*rhs.denominator
                -rhs.numerator*lhs.denominator,
                lhs.denominator*rhs.denominator);
    return tmp;
}

Fraction operator-=(Fraction& lhs, const Fraction& rhs) {
    Fraction tmp(lhs.numerator*rhs.denominator
                -rhs.numerator*lhs.denominator,
                lhs.denominator*rhs.denominator);
    lhs = tmp;
    return lhs;
}

Fraction operator*(const Fraction& lhs, const Fraction& rhs) {
    Fraction tmp(lhs.numerator*rhs.numerator,
               lhs.denominator*rhs.denominator);
    return tmp;
}

Fraction operator*=(Fraction& lhs, const Fraction& rhs) {
    Fraction tmp(lhs.numerator*rhs.numerator,
               lhs.denominator*rhs.denominator);
    lhs = tmp;
    return lhs;
}

Fraction operator*(int lhs, const Fraction& rhs) {
    Fraction tmp(lhs*rhs.numerator,rhs.denominator);
    return tmp;
}

Fraction operator*(const Fraction& rhs, int lhs) {
    Fraction tmp(lhs*rhs.numerator,rhs.denominator);
    return tmp;
}

Fraction operator/(const Fraction& lhs, const Fraction& rhs) {
    Fraction tmp(lhs.numerator*rhs.denominator,
                 lhs.denominator*rhs.numerator);
    return tmp;
}
Fraction operator/(const Fraction& lhs, int rhs)
{
    Fraction tmp(lhs.numerator, lhs.denominator*rhs);
    return tmp;
}
std::ostream& operator<<(std::ostream &strm, const Fraction &a) {
    if (a.denominator == 1) {
        strm << a.numerator;
    } else {
        strm << a.numerator << "/" << a.denominator;
    }
    return strm;
}

int main()
{
    Fraction E(0, 1), V(0, 1);
    int N; cin >> N;
    vector<int> p;
    vector<Fraction> W;
    for(int i = 0; i < N; i++)
    {
        int tmp;    cin >> tmp;
        p.pb(tmp);
    }
    long long num = 2,  den = N*(N+1);
    Fraction w1(num, den);
    for(int i = 1; i <= N; i++)
    {
        Fraction tmp = w1*i;
        tmp.reduce();
        W.pb(tmp);
    }
    for(int i = 0; i < N; i++)
    {
        Fraction e = W[i]*p[i];
        E = E+e;
        E.reduce();
    }
    V = w1*w1;
    Fraction f2(N*(N+1), 2);
    V = V*f2;
    V.reduce();
    cout << E.numerator << ' ' << E.denominator<<endl;
    cout << V.numerator << ' ' << V.denominator<<endl;
    return 0;
}
