# CipherCode
Library with functions to encode texts

## Usage

```c++
//library inclusion
#include <CipherCode.h>

//Encode text using the Caesar cipher. The key must be a number between 1 and 25
String ceasarCipher(String txt, int shift, bool encode);

//Encode text using the Vigenere Cipher. The key is a string
String vigenereCipher(String txt, String key, bool encode);

//Encode text using Math Cipher. The key is numeric of type long
String mathCipher(String txt, long key, bool encode);

//Encode text using Mirror Cipher. The key is not used
String mirrorCipher(String txt);

//Converts text to Hacker format
String hackerStr(String txt);

//Returns the text in reverse
String reverseStr(String txt);
```

Author : Fellipe Couto [ http://www.efeitonerd.com.br ]

Date : 2023-06-21
