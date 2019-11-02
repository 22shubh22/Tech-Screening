#include "rsa.h"

RSA::RSA() {
    calculate_e(phi);
    calculate_d(phi, k, e);
}

double RSA::exponent(double base, double power, double n)
{
    long l_base = (long)base;
    long l_power = (long)power;
    long l_n = (long)n;

    long p = 1;
    long i =1;
    while(i <= l_power)
    {
        p = (p % l_n)  * (l_base % l_n);
        i++;
    }
    return (p % l_n);
}

long RSA::gcd(long a, long h)
{
    int temp;
    while (1) 
    {
        temp = a%h;
        if (temp == 0) 
            return h; 
        a = h;
        h = temp;
    } 
}

void RSA::calculate_e(double phi)
{
    double e=2;
	while (e < phi) 
	{ 
		// e must be co-prime to phi and 
		// smaller than phi. 
		if (gcd(e, phi)==1) 
			break; 
		else
			e++; 
    }
    set_e(e);
}

void RSA::set_e(double p)
{
    e = p;
}

double RSA::get_public_key()
{
    return e;
}

double RSA::get_n()
{
    return n;
}

void RSA::calculate_d(double phi, double k, double e)
{
    d = (1 + (k*phi))/e;
}

double RSA::get_private_key()
{
    return d;
}