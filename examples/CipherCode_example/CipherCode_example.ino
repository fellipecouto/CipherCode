/*-----------------------------------------------------------------------------------
  Program  : CipherCode
  Descr    : Library with functions to encode texts
  Author   : Fellipe Couto [ http://www.efeitonerd.com.br ]
  GitHub   : https://github.com/fellipecouto/CipherCode
  Date     : 2023-06-21
  -----------------------------------------------------------------------------------*/
//Example of using functions from the CipherCode library

#include <CipherCode.h>  //https://github.com/fellipecouto/CipherCode [ http://www.efeitonerd.com.br ]

void setup() {
  Serial.begin(115200);
  delay(500);
  const String txtToEncode = "sample text to code with library";

  //Caesar Cipher (The key must be a number between 1 and 25)
  String txtCaesarENC = ceasarCipher(txtToEncode, 11, true);  //true to encode
  Serial.println("--- Caesar Cipher ---");
  Serial.println("- Plain text: " + txtToEncode);
  Serial.println("* Encode: " + txtCaesarENC);
  String txtCaesarDEC = ceasarCipher(txtCaesarENC, 11, false);  //false to decode
  Serial.println("= Decode: " + txtCaesarDEC);
  Serial.println();

  //Vigenere Cipher (The key is a string)
  String txtVigenereENC = vigenereCipher(txtToEncode, "mypassword", true);  //true to encode
  Serial.println("--- Vigenere Cipher ---");
  Serial.println("- Plain text: " + txtToEncode);
  Serial.println("* Encode: " + txtVigenereENC);
  String txtVigenereDEC = vigenereCipher(txtVigenereENC, "mypassword", false);  //false to decode
  Serial.println("= Decode: " + txtVigenereDEC);
  Serial.println();

  //Math Cipher (The key is numeric of type long)
  String txtMathENC = mathCipher(txtToEncode, 4780, true);  //true to encode
  Serial.println("--- Math Cipher ---");
  Serial.println("- Plain text: " + txtToEncode);
  Serial.println("* Encode: " + txtMathENC);
  String txtMathDEC = mathCipher(txtMathENC, 4780, false);  //false to decode
  Serial.println("= Decode: " + txtMathDEC);
  Serial.println();

  //Mirror Cipher (The key is not used)
  String txtMirrorENC = mirrorCipher(txtToEncode);
  Serial.println("--- Mirror Cipher ---");
  Serial.println("- Plain text: " + txtToEncode);
  Serial.println("* Encode: " + txtMirrorENC);
  String txtMirrorDEC = mirrorCipher(txtMirrorENC);
  Serial.println("= Decode: " + txtMirrorDEC);
  Serial.println();

  //Hacker String (The text in hacker format)
  String txtHackerENC = hackerStr(txtToEncode, true);  //true to encode
  Serial.println("--- Hacker String ---");
  Serial.println("- Plain text: " + txtToEncode);
  Serial.println("* Encode: " + txtHackerENC);
  String txtHackerDEC = hackerStr(txtHackerENC, false);  //false to decode
  Serial.println("= Decode: " + txtHackerDEC);
  Serial.println();

  //Reverse String (Returns the text in reverse)
  String txtReverseENC = reverseStr(txtToEncode);
  Serial.println("--- Hacker String ---");
  Serial.println("- Plain text: " + txtToEncode);
  Serial.println("* Encode: " + txtReverseENC);
  String txtReverseDEC = reverseStr(txtReverseENC);
  Serial.println("= Decode: " + txtReverseDEC);
  Serial.println();
}

void loop() {
}