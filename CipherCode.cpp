/*-----------------------------------------------------------------------------------
  Program  : CipherCode
  Descr    : Library with functions to encode texts
  Author   : Fellipe Couto [ http://www.efeitonerd.com.br ]
  GitHub   : https://github.com/fellipecouto/CipherCode
  Date     : 2023-06-21
  -----------------------------------------------------------------------------------*/
#include "CipherCode.h"

String ceasarCipher(String txt, int shift, bool encode) {
  if (shift < 1 || shift > 25) return "Invalid key. Must be between 1 and 25.";
  String alphabet = "abcdefghijklmnopqrstuvwxyz";
  if (encode == false) alphabet = "zyxwvutsrqponmlkjihgfedcba";
  String txtCode = "";
  for (int i = 0; i < txt.length(); i++) {
    bool inAlphabet = false;
    for (int a = 0; a < alphabet.length(); a++) {
      if (txt.substring(i, i + 1) == alphabet.substring(a, a + 1)) {
        inAlphabet = true;
        if (a + shift >= alphabet.length()) {
          txtCode += alphabet.substring(a + shift - alphabet.length(), a + shift - alphabet.length() + 1);
        } else {
          txtCode += alphabet.substring(a + shift, a + shift + 1);
        }
      }
    }
    if (inAlphabet == false) txtCode += txt.substring(i, i + 1);
  }
  return txtCode;
}

String vigenereCipher(String txt, String key, bool encode, bool withNumbers) {
  key.replace(" ", "");
  key.toLowerCase();
  txt.toLowerCase();
  String alphabet = "abcdefghijklmnopqrstuvwxyz";
  if (withNumbers) alphabet += "0123456789";
  String txtCode = "";
  int idx = 0;
  int keyidx = 0;
  for (int i = 0; i < txt.length(); i++) {
    int idx = alphabet.indexOf(txt.substring(i, i + 1));
    if (idx >= 0) {
      if (encode) {
        idx += alphabet.indexOf(key.substring(keyidx % key.length(), keyidx % key.length() + 1));
      } else {
        idx -= alphabet.indexOf(key.substring(keyidx % key.length(), keyidx % key.length() + 1));
        if (idx < 0) idx = alphabet.length() + idx;
      }
      txtCode += alphabet.substring(idx % alphabet.length(), idx % alphabet.length() + 1);
      keyidx++;
    } else {
      txtCode += txt.substring(i, i + 1);
    }
  }
  return txtCode;
}

String mathCipher(String txt, long key, bool encode) {
  txt.toLowerCase();
  const String limiter1 = "^";
  const String limiter2 = "*";
  const String alphabet = "hw4mty0iaocbux2r6vgdk5p1e3qz9fj8ls7n.,:;?!@#$%&()-+=/" + limiter1 + limiter2;
  String txtCode = "";
  if (key < 0) key *= -1;
  for (int i = 0; i < txt.length(); i++) {
    if (encode) {
      int idx = alphabet.indexOf(txt.substring(i, i + 1)) + 10;
      if (idx >= 10) {
        txtCode += (((idx + key) % 2 == 0) ? limiter1 : limiter2) + String((idx + key) * (((idx + key) % 2 == 0) ? 2 : 5));
      } else {
        txtCode += txt.substring(i, i + 1);
      }
    } else {
      if (i < txt.length() - 1) {
        if (txt.substring(i, i + limiter1.length()) == limiter1 || txt.substring(i, i + limiter2.length()) == limiter2) {
          long idx = txt.substring(i + limiter1.length(), txt.indexOf((txt.substring(i, i + limiter1.length()) == limiter1) ? limiter1 : limiter2, i + limiter1.length())).toInt();
          int idxAux = (idx / ((txt.substring(i, i + limiter1.length()) == limiter1) ? 2 : 5)) - key - 10;
          txtCode += alphabet.substring(idxAux, idxAux + 1);
        } else if (txt.substring(i, i + 1) == " ") {
          txtCode += txt.substring(i, i + 1);
        }
      }
    }
  }
  return txtCode;
}

String mirrorCipher(String txt) {
  txt.toLowerCase();
  String alphabetA = "abcdefghijklm01234";
  String alphabetB = "nopqrstuvwxyz56789";
  String txtCode = "";
  for (int i = 0; i < txt.length(); i++) {
    if (alphabetA.indexOf(txt.substring(i, i + 1)) >= 0) {
      txtCode += alphabetB.substring(alphabetA.indexOf(txt.substring(i, i + 1)), alphabetA.indexOf(txt.substring(i, i + 1)) + 1);
    } else if (alphabetB.indexOf(txt.substring(i, i + 1)) >= 0) {
      txtCode += alphabetA.substring(alphabetB.indexOf(txt.substring(i, i + 1)), alphabetB.indexOf(txt.substring(i, i + 1)) + 1);
    } else {
      txtCode += txt.substring(i, i + 1);
    }
  }
  return txtCode;
}

String hackerStr(String txt, bool encode) {
  txt.toLowerCase();
  if (encode) {
    txt.replace("a", "4"); txt.replace("e", "3"); txt.replace("i", "1");
    txt.replace("o", "0"); txt.replace("t", "7"); txt.replace("s", "$");
  } else {
    txt.replace("4", "a"); txt.replace("3", "e"); txt.replace("1", "i");
    txt.replace("0", "o"); txt.replace("7", "t"); txt.replace("$", "s");
  }
  return txt;
}

String msnStr(String txt, bool encode) {
  String txtCode = "";
  for (int i = 0; i < txt.length(); i++) {
    String t = txt.substring(i, i + 1);
    randomSeed(millis());
    int r = random(2);
    if (r == 0 || encode == false) {
      t.toLowerCase();
    } else {
      t.toUpperCase();
    }
    txtCode += t;
  }
  return txtCode;
}

String reverseStr(String txt) {
  String txtReverse = "";
  for (int i = txt.length() - 1; i >= 0; i--) txtReverse += txt.substring(i, i + 1);
  return txtReverse;
}