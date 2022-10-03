#include <stdio.h>

int gcd(int a, int b){
	if (b==0)	return a; //escape
	else		return gcd(b, a%b);
}

int main()
{
	int m, n, temp;
	scanf("%d%d",&m,&n);
	if (m<n) { //if m is less that n, switch m, n
		temp=m;
		m=n;
		n=temp;
	}
	printf("M = %d, N = %d\n", m, n);
	printf("GCD = %d", gcd(m, n));
}
