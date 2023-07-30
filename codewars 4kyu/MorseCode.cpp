#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
string decodeMorse(string morseCode) {
  unordered_map<string, string> MORSE_CODE = {
    {".-","A"}, {"-...", "B"}, {"-.-.", "C"}, {"-..", "D"}, {".", "E"}, {"..-.", "F"},
    {"--.", "G"}, {"....", "H"}, {"..", "I"}, {".---", "J"}, {"-.-", "K"}, {".-..", "L"},
    {"--", "M"}, {"-.", "N"}, {"---", "O"}, {".--.", "P"}, {"--.-", "Q"}, {".-.", "R"},
    {"...", "S"}, {"-", "T"}, {"..-", "U"}, {"...-", "V"}, {".--", "W"}, {"-..-", "X"},
    {"-.--", "Y"}, {"--..", "Z"},
    {"-----", "0"}, {".----", "1"}, {"..---", "2"}, {"...--", "3"}, {"....-", "4"},
    {".....", "5"}, {"-....", "6"}, {"--...", "7"}, {"---..", "8"}, {"----.", "9"},
    {".-.-.-", "."}, {"--..--", ","}, {"..--..", "?"}, {".----.", "'"}, {"-.-.--", "!"},
    {"-..-.", "/"}, {"-.--.", "("}, {"-.--.-", ")"}, {".-...", "&"}, {"---...", ":"},
    {"-.-.-.", ";"}, {"-...-", "="}, {".-.-.", "+"}, {"-....-", "-"}, {"..--.-", "_"},
    {".-..-.", "'"}, {"...-..-", "$"}, {".--.-.","@"} 
};

  string res, letter;
  while (morseCode[0]== ' ') morseCode.erase(0,1);
  while (morseCode[morseCode.size()-1]== ' ') morseCode.erase(morseCode.size()-1,1);
  int i = 0;
  while (i < (int) morseCode.size()){
    if (morseCode[i] != ' '){
      letter += morseCode[i];
      i++;
    }
    if (morseCode[i] == ' '){
      res += MORSE_CODE[letter];
      letter = "";
      if (morseCode[i+1] == ' '){
        i+=2; res+=" ";
      }
      else i++; 
    }
  }
  return res+MORSE_CODE[letter];
}

int main(){
  string morseCode = ".... . -.--   .--- ..- -.. .";
  cout << decodeMorse(morseCode) << endl;
  return 0;
}