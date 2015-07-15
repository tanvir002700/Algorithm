/// for a natural number n>1 is a prime if  ((n-1)!) mod n = n-1 that states by Wilson.

#include<stdio.h>
int main()
{
      int long long n,m,i,p,fact;


      while(scanf("%lld",&n)==1){
            fact=1;
            m=n;
                  for(i=1;i<=n-1;i++){
                   fact=(((fact*i) %m)%m)%m;
                  }

                  if (fact==n-1)
                  printf("%lld is prime\n",n);
                  else
                  printf("%lld is not prime\n",n);
      }
      return 0;
}
