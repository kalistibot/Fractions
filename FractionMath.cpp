int GCD(int a, int b)
{
    while(true)
    {
        a = a % b;
	if (a==0)
        return b;
	b = b % a;
	if (b == 0)
        return a;
    }
}

int LCM(int a,int b)
{
    return (a*b)/GCD(a,b);
}
