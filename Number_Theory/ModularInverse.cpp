int modularInverse(int a, int n)
{
    pii ret = extendedEuclid(a, n);
    return ((ret.x % n) + n) % n;
}
