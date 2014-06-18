/* Jehuty, a simple text encryption program
 * by Giovanni Santostefano
 * http://twocentssecurity.wordpress.com
 *
 * Jehuty integrates the official C code
 * implementation of Anubis cipher
 */
 
#include "jehuty.h"

int main()
{
    int i =0;
    
    printf("\n");
    printf("**********************************************\n");
    printf("*       Jehuty text encryption program       *\n");
    printf("*         by Giovanni Santostefano           *\n");
    printf("*                                            *\n");
    printf("*                                            *\n");
    printf("*    Encryption provided by Anubis cipher    *\n");
    printf("**********************************************\n");
    printf("\n");
    printf("1. Encrypt text\n");
    printf("2. Decrypt text\n");
    printf("3. Exit\n");
    printf(">>> ");
    scanf("%d",&i);
    getchar(); /* this is to intercept the newline after the scanf :( */
    fflush(stdin);
    
    if(i==1)
    {
        JehutyEncrypt();
    }
    else if(i==2)
    {
        JehutyDecrypt();
    }
    
    return 0;
}
