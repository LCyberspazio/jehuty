jehuty
======

Jehuty, simple small text encryption program written in C (cross platform) using Anubis Cipher (NESSIE candidate)

Jehuty is developed by
Giovanni Santostefano that integrates the 
Anubis cipher to encrypt/decrypt simple text.

 The Anubis algorithm was developed by
 pbarreto@scopus.com.br             Paulo S. L. M. Barreto 
 vincent.rijmen@esat.kuleuven.ac.be Vincent Rijmen.

It was specifically designed one sleepless night for fun 
and for sharing encrypted messages with simplicity
between peoples on facebook who are not familiar
with gnupg or other RSA (or AES/Serpent/Two Fish in this case) 
implementations.

This small program is designed on GNU/Linux but
it's posix compilant so you can compile it in
all POSIX platforms, including Windows, BSD
and many others.

Under *nix systems compile it with
$ make

or
$ gcc -o jehuty anubis.c jehuty.c main.c

or simply
$ gcc -o jehuty *.c

_________________________________________________
USAGE:

Meet your friend, by person or by phone (less secure
but if you are interested in real security probably you 
are well aware of RSA public key encryption :D 
or OTR and TOR for instant messaging).
Choose with your friend a secret passphrase that only
both of you will know.

Open two terminals and run on each of them
$ ./jehuty

On one window terminal choose 1 to encrypt your text
on the other window choose 2 to decrypt the text of your
friends.
Enter in both windows the passphrase decided with your friend.

Then Start to write your message in the encryption terminal,
hit enter and the text will be encrypted in a sequence like this

%'#!%/),--'.)&#+"./"+/-+&-#)"%)'$%%0$++(!%!)!/,-$(,(#(*)-0)0*&/#&.$'/')-,,,--%.''0+/(,0$#-"")(#.

This is a typical text encrypted with Jehuty. It's not a normal
Anubis output because it's translated in a human readable text
ready to be cut and paste on the facebook page of your friend
that will decrypt the message with jehuty and the same key
shared with you.

The key must be a char sequence of max 32 characters.

Have fun!
