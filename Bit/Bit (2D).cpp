void updatey(int x , int y , int val)
{
    while (y <= max_y)
    {
        tree[x][y] += val;
        y += (y & -y);
    }
}
void update(int x , int y , int val)
{
    while (x <= max_x)
    {
        updatey(x , y , val);// this function should update array tree[x]
        x += (x & -x);
    }
}
