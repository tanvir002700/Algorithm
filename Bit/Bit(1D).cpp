#define MaxVal 100000
int Bit[MaxVal];
/**find sum from 1 to idx**/
int read(int idx)
{
    int sum = 0;
    while (idx > 0)
    {
        sum += Bit[idx];
        idx -= (idx & -idx);
    }
    return sum;
}
/**update value ind to MaxVal**/
void update(int idx ,int val)
{
    while (idx <= MaxVal)
    {
        Bit[idx] += val;
        idx += (idx & -idx);
    }
}

/**Find the value of idx**/
int readSingle(int idx)
{
    int sum = Bit[idx]; /// sum will be decreased
    if (idx > 0)  /// special case
    {
        int z = idx - (idx & -idx); /// make z first
        idx--; /// idx is no important any more, so instead y, you can use idx
        while (idx != z)  /// at some iteration idx (y) will become z
        {
            sum -= Bit[idx];/// substruct Bit frequency which is between y and "the same path"
            idx -= (idx & -idx);
        }
    }
    return sum;
}
