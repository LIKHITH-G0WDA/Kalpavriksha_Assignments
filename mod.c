#include <stdio.h>
#include <stdlib.h>

int main()
{
    unsigned long long b,n,m,ans=1;
    printf("Enter base(positive integer): ");
    scanf("%llu",&b);
    printf("Enter exponent(positive integer): ");
    scanf("%llu",&n);
    printf("Enter modulus(positive integer): ");
    scanf("%llu",&m);

    if(m<=1)
    {
        printf("modulus(m) should greater than 1");
        return 1;
    }
    //reduce the size of base, using the property (a mod m)^b mod m=a^b mod m
    //for eg 10 mod 7 = 3, 10^exp mod 7 == 3^exp mod 7 
    b=b%m;

    //implementing modular exponentation, exponentation by squaring
    while(n>0)
    {
        if(n%2==1) //if exponent is odd
        {
            ans=(ans*b)%m;
        }
        n=n/2; 
        b=(b*b)%m;
    }
    printf("Answer: ");
    printf("%llu",ans);

}
