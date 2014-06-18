/* Jehuty, a simple text encryption program
 * by Giovanni Santostefano
 * http://twocentssecurity.wordpress.com
 *
 * Jehuty integrates the official C code
 * implementation of Anubis cipher
 */
 
#include "jehuty.h"

void GetText(char *txt, unsigned int len)
{
    unsigned int i=0;
    char c=0;
    
    while(c=getchar())
    {
        if(c=='\n'|| i>len-1) return;
        txt[i++]=c;
    }
}


/* Encryption routine */
void JehutyEncrypt()
{
    struct NESSIEstruct sp;
    char key[KEYSIZE];
    char plaintext[1024];
    
    /*blocks are 16byte long. But with 16 bytes
     *there's a problem in encryption so I have
     *to use 1024byte... can't say why*/
    unsigned char plainblock[1024];
    unsigned char cipherblock[1024];
    
    char *p;
    int i=0, j=0, k=0;
    int c=0;
    
    printf("Jehuty Short Message Encryption\nby Giovanni Santostefano\n\n");
    
    /* Enter the key of max 16 chars*/
    printf("Insert passphrase(max 16 chars)> ");
    GetText(key, KEYSIZE);
    
    /* print on screen to make entered passphrase unvisible */
    for(i=0;i<6000; i++)printf("\n%d\n",6000-i);
    
    /* Create Anubis key based on the passphrase */
    NESSIEkeysetup(key, &sp);
    
    
    printf("\n\n\n\n\n\n\nJehuty Encrypt text\nby Giovanni Santostefano\n\n");
    while(1)
    {
        memset(plaintext,0,1024);
        printf("\n\nInsert text to encrypt (max 1023 characters)\n> ");
        GetText(plaintext, 1023);
        
        p=plaintext;
        j=0;
        memset(plainblock,0,1024);
        memset(cipherblock,0,1024);
        printf("\n\n<Encrypted! Cut and paste>\n");
        while(*p!='\0')
        {
            plainblock[j++]=*p++;
            
            /* 128bit block filled, encrypt */
            if(j>=16 || *p=='\0')
            {
                j=0;
                NESSIEencrypt(&sp, plainblock, cipherblock);
                
                /* print the encrypted 128bit block in human readable chars */
                for(k=0; k<16; k++)
                {
                    c=cipherblock[k];
                    char g=(char)('!'+(c & 0x0f));
                    printf("%c",g);
                    g=(char)('!'+((c & 0xf0)>>4));
                    printf("%c",g);
                }
                
                memset(plainblock,0,1024);
                memset(cipherblock,0,1024);
            }
            
        }
        
    }
    
    return;
}



/* Decryption routine */
void JehutyDecrypt()
{
    struct NESSIEstruct sp;
    char key[KEYSIZE];
    char plaintext[4096];
    unsigned char plainblock[16];
    unsigned char cipherblock[16];
    unsigned char plainwrite[18];
    char ciphertext[4096];
    char ciphertextb64[14096];
    char *p, *l;
    int i=0, j=0, k=0, iterations=0;
    char c=0;
    
    printf("Jehuty Decrypt text\nby Giovanni Santostefano\n\n");
    
    /* Enter the key of max 16 chars*/
    printf("Insert passphrase(max 16 chars)> ");
    GetText(key, KEYSIZE);
    
    /* print on screen to make entered passphrase unvisible */
    for(i=0;i<6000; i++)printf("\n%d\n",6000-i);
    
    /* Create Anubis key based on the passphrase */
    NESSIEkeysetup(key, &sp);
    
    
    printf("\n\n\n\n\n\n\nJehuty Decrypt text\nby Giovanni Santostefano\n\n");
    while(1)
    {
        memset(plaintext,0,4096);
        memset(ciphertextb64,0,14096);
        memset(ciphertext,0,4096);
        printf("\n\nInsert text to decrypt\n> ");
        GetText(ciphertextb64, 14095);
        
        
        /* reconstructing the binary encrypted message
         * starting from the human readable version
         */
        p=ciphertextb64;
        l=ciphertext;
        iterations=0;
        while(*p!='\0')
        {
            c=(char)(((*(p+1)-'!')<<4)) + ((*p-'!'));
            p=p+2;
            *l=c;
            l++;
            iterations++;
        }
        
        /*printf("ITERATIONS: %d\n\n",iterations);*/
        
        /* Decrypting the message splitting it into 128bit blocks */
        p=ciphertext;
        j=0;
        memset(plainblock,0,16);
        memset(cipherblock,0,16);
        printf("\n\n<Decrypted! Cut and paste>\n");
        
        for(k=0; k<iterations; k++)
        {
            cipherblock[j]=*p++;
            
            /* 128bit block filled, decrypt it */
            if(j>=15)
            {
                j=0;
                NESSIEdecrypt(&sp, cipherblock, plainblock);
                strncpy(plainwrite, plainblock, 16);
                plainwrite[17]='\0';
                printf("%s", plainwrite);
                
                memset(plainwrite,0,18);
                memset(plainblock,0,16);
                memset(cipherblock,0,16);
            }
            else j++;
        }
        
    }
    
    return;
}



