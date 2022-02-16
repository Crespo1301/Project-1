#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include "passwords.h"

void test_10k(char* password)
{
    for(int i =0; i<10000; i++)
    {
        if(strcmp(password, passwords[i]) == 0)
        {
            printf("Match\n");
        }
    }
}
void leet(char* password)
{
    for(int i = 0; i<10000; i++)
    {
        char* currentPass = passwords[i];
        for(int k = 0; k<strlen(password); k++)
        {
            if(currentPass[k]=='0')
            {
                currentPass[k] = 'o';
            }
            if(currentPass[k]=='3')
            {
                currentPass[k] = 'e';
            }
            if(currentPass[k]=='!')
            {
                currentPass[k] = 'i';
            }
            if(currentPass[k]=='@')
            {
                currentPass[k] = 'a';
            }
            if(currentPass[k]=='#')
            {
                currentPass[k] = 'h';
            }
            if(currentPass[k]=='$')
            {
                currentPass[k] = 's';
            }
            if(currentPass[k]=='+')
            {
               currentPass[k] = 't';
            }
        }
        if(strcmp(password, passwords[i]) == 0)
        {
            printf("Match\n"); 
        }
    }
}

void plus1(char* password)
{
    strcat(password,"1");
    for(int i =0; i<10000; i++)
    {
        if(strcmp(password, passwords[i]) == 0)
        {
            printf("Match\n");
            return; 
        }
    }

}

void entropy(char* password)
{
    int len = strlen(password);
    bool lowercase = 0, uppercase = 0, digit = 0, print = 0; 
    int num = 0; 
    for(int i = 0; i<len; i++)
    {
        if(isupper(password[i]))
        {
            if(!uppercase)
            {
                uppercase = 1; 
            }
        }
        if(islower(password[i]))
        {
            if(!lowercase)
            {
                lowercase = 1; 
            }
        }
        if(isdigit(password[i]))
        {
            if(!digit)
            {
                digit = 1; 
            }
        }
        if(isprint(password[i]))
        {
            if(!print)
            {
                print = 1; 
            }
        }
    }

    if(uppercase == 1 )
    {
        num += 26; 
    }
    if(lowercase == 1 )
    {
        num += 26; 
    }
    if(digit == 1 )
    {
        num += 10; 
    }
    if(print == 1 )
    {
        num += 32; 
    }
    printf("values: %d, %x",num,len);
    printf("\n");
    double total = pow(num, len);
    int ent  = log(total) / log(2);
    printf("%d", ent);
}


int main(int argc, char *argv[])
{
    char *test = argv[1];
    char *password = argv[2];

    if(strcmp(test,"entropy") == 0)
    {
        entropy(password);
    }
    if(strcmp(test,"leet") == 0)
    {
        leet(password);
    }
    if(strcmp(test,"10k") == 0)
    {
        test_10k(password);
    }
    return 0;    
}