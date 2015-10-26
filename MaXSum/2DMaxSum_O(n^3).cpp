int arr[SZ][SZ];
int input(void);
int max_sum(int n);
int main()
{
    int test, n;
    scanf("%d", &test);
    while(test--)
    {
        n = input();
        printf("%d\n", max_sum(n));
        if(test)
            printf("\n");
    }
    return 0;
}

int input(void)
{
    int i, len, r = 1, n;
    char str[26];
    scanf(" %s", &str);
    len = strlen(str);
    for(i = 1; i <= len; i++)
    {
        n = str[i - 1] - '0';
        if(n)
            arr[r][i] = n;
        else
            arr[r][i] = -700;
    }
    r++;
    while(r <= len)
    {
        scanf("%s", &str);
        for(i = 1; i <= len; i++)
    {
        n = str[i - 1] - '0';
        if(n)
            arr[r][i]= n;
        else
            arr[r][i] = -700;
    }
        r++;
    }
    return len;
}

int max_sum(int n)
{
    int i, j, c1, c2, r, sum = 0,m = 0;
    for(i = 0; i <= n; i++)
        arr[i][0] = arr[0][i] = 0;
    for(i = 1; i <= n; i++)
        for(j = 1; j <= n; j++)
            arr[i][j] += arr[i][j - 1];
    for(c1 = 1; c1 <= n; c1++)
        for(c2 = c1; c2 <= n; c2++)
        {
            sum = 0;
            for(r = 1; r <= n; r++)
            {
                sum += arr[r][c2] - arr[r][c1 - 1];
                if(sum < 0)
                    sum = 0;
                else if(sum > m)
                    m = sum;
            }
        }
    return m;
}
