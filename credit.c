#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main (void)
{
    long n;
    do
    {
        n = get_long("Enter your credit card number: ");
    }
    while(n<1);
    int counter=0;
    long ex = n;
    while( ex!=0){
        counter++;  // Calculate the length of user input
        ex=ex/10;
    }
    ex=n;   // don't disturb the initial input value.
    long sum=0,mul=0;
    int result=0; // this is used to check the checksum of the card.
    for(int i=0; i<counter;i++)
    {
        if(i%2==0) //selects last digit and it's alternate digits of the card.
        {
         sum=sum+ex%10;
         ex=ex/10;
        }
        else{   // selects second last digit and it's alternatives of the card.
            long x=(ex%10)*2;   // Multiply the 2nd last digits and alternatives with 2.
            if(x>9){    // if number is bigger than 9, add the digits individually.
                mul+=x%10;
                x=x/10;
                mul+=x%10;
            }
            else    // if value doesn't exceed 9, we can safely add it to the result.
            {
                mul+=x;
            }
            ex=ex/10;
        }
        result = sum + mul;
    }
    //printf("result is: %i\n", result);
    ex=n;
    if (result%10 ==0)  // Checksum is Valid. Calculate the name of the card now.
    {
        //printf("VALID\n");
        if(counter==16) //length of card is 16
        {
            int cc = ex/pow(10,15);
            if (cc==4) // Check for VISA
            {
                printf("VISA\n");
                return 0;
            }
            else
            {
                cc = ex/pow(10,14);
                if(cc == 51||cc ==52||cc==53||cc==54||cc==55) // Check for Master Card
                {
                    printf("MASTERCARD\n");
                    return 0;
                }
                else
                {
                    printf("INVALID\n");
                    return 0;
                }
            }
        }
        else if (counter ==13 )//Check for VISA
        {
            int cc = ex/pow(10,12);
            if(cc==4)
            {
                printf("VISA\n");
                return 0;
            }
            else
            {
                printf("INVALID\n");
                return 0;
            }
        }
        else if(counter ==15)//Check for American Express
        {
            int cc = ex/pow(10,13);
            if(cc == 34 || cc==37)
            {
                printf("AMEX\n");
                return 0;
            }
            else
            {
                printf("INVALID\n");
                return 0;
            }
        }
        else    //card number length is not valid.
        {
            printf("INVALID\n");
            return 0;
        }

    }
    else
    {
        printf("INVALID\n");
        return 0;
    }
}

