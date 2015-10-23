precalculation:
for(int i=1;i<=N;i++)
{
    for(int j=1;j<=N;j++)
    {
        Mat[i][j]=Mat[i-1][j]+Mat[i][j-1]-Mat[i-1][j-1]+A[i][j];
    }
}
Query:
Sum=Mat[x2][y2]-Mat[x1-1][y2]-Mat[x2][y1-1]+Mat[x1-1][y1-1]
