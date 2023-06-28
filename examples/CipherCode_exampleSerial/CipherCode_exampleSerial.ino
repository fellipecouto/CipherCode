/*-----------------------------------------------------------------------------------
  Program  : CipherCode
  Descr    : Library with functions to encode texts
  Author   : Fellipe Couto [ http://www.efeitonerd.com.br ]
  GitHub   : https://github.com/fellipecouto/CipherCode
  Date     : 2023-06-21
  -----------------------------------------------------------------------------------*/
//Example of using functions from the CipherCode library with serial communication

#include <CipherCode.h>  //https://github.com/fellipecouto/CipherCode [ http://www.efeitonerd.com.br ]

int menu = 0;
int typeCipher = 0;
bool code = true;
String txt = "";

void setup() {
  Serial.begin(115200);
  delay(500);
  Serial.println("CIPHER CODE");
  Serial.println("www.efeitonerd.com.br");
}

void loop() {
  String strSerial = "";

  //Get string from serial
  while (Serial.available() > 0) {
    strSerial += Serial.readString();
  }

  if (strSerial.length() > 0) {
    if (menu == 1) {
      txt = strSerial;
      Serial.println("--> " + txt);
      Serial.println("\nSelect the cipher type:");
      Serial.println("1=CeasarCipher 2=VigenereCipher 3=MathCipher 4=MirrorCipher 5=Hacker 6= MSN 7=Reverse");
      menu = 2;
    } else if (menu == 2) {
      typeCipher = strSerial.toInt();
      if (typeCipher > 6) typeCipher = 6;
      Serial.println("--> " + String(typeCipher));
      Serial.println("\nSelect the option:");
      Serial.println("1=Encode 2=Decode");
      menu = 3;
    } else if (menu == 3) {
      if (strSerial == "1") {
        code = true;
        Serial.println("--> Encode");
      } else {
        code = false;
        Serial.println("--> Decode");
      }
      Serial.println("\nKey:");
      Serial.println("(Numerical value for Caesar and Math cipher. For Vigenere a String as key. For others, no key is used and you can enter any value.)");
      menu = 4;
    } else if (menu == 4) {
      Serial.println("--> " + strSerial);
      delay(500);
      Serial.println("\nResult:");
      switch (typeCipher) {
        case 1:
          Serial.println("--> " + ceasarCipher(txt, strSerial.toInt(), code));
          break;
        case 2:
          Serial.println("--> " + vigenereCipher(txt, strSerial, code));
          break;
        case 3:
          Serial.println("--> " + mathCipher(txt, strSerial.toInt(), code));
          break;
        case 4:
          Serial.println("--> " + mirrorCipher(txt));
          break;
        case 5:
          Serial.println("--> " + hackerStr(txt, code));
          break;
        case 6:
          Serial.println("--> " + msnStr(txt, code));
          break;
		case 7:
          Serial.println("--> " + reverseStr(txt));
          break;
        default:
          Serial.println("--> ?");
          break;
      }
      menu = 0;
      delay(3000);
    }
  }

  if (menu == 0) {
    Serial.println("\nEnter text to encode:");
    menu = 1;
  }
}