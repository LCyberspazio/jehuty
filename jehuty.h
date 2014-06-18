/* Jehuty, a simple text encryption program
 * by Giovanni Santostefano
 * http://twocentssecurity.wordpress.com
 *
 * Jehuty integrates the official C code
 * implementation of Anubis cipher
 */
 
 
#ifndef __JEHUTY__
#define __JEHUTY__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "nessie.h"

#define KEYSIZE 16

/* Encryption routine */
void JehutyEncrypt();

/* Decryption routine */
void JehutyDecrypt();

#endif
