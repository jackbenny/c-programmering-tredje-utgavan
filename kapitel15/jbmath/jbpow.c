long jbpow(int x, int n)
{
    long num = 1;
    int i;
    for(i = 0; i<n; i++)
    {
        num = num * x;
    }
    return num;
}
