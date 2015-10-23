int more_bit[10];
int get_bit(int mask , int pos)
{
    return (mask / more_bit[pos]) % 3;
}
int set_bit(int mask, int pos , int bit)
{
    int tmp = (mask / more_bit[pos]) % 3;
    mask -= tmp * more_bit[pos];
    mask += bit * more_bit[pos];
    return mask;
}
void init(void)
{
    more_bit[0] = 3;
    for(int i = 1; i < 10; i++) more_bit[i] = 3 * more_bit[i - 1];
}
