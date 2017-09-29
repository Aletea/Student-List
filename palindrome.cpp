#include <iostream>
#include <string.h>

using namespace std;

int main() {
  //create 3 different char arrays: 1 for input, one for punctuation removal, and one for the backwards sentance
  char sentance[80];
  char nextSentance[80];
  char copySentance[80];
  cout << "Enter your palindrome." << endl;
  //read in a sentance                       
  cin.get(sentance, 80);
  cin.get();
  //count keeps track of input length (without punctuation), and keeps track of current index of nextSentance
  int count = 0;
  for(int i = 0; i < 80; i++) {
    //if it's a letter, then add it to nextSentance
    if (isalpha(sentance[i])) {
      int number = sentance[i];
      if (number > 64 && number < 91) {
	sentance[i] = sentance[i] + 32;
      }
	nextSentance[count] = sentance[i];
	//go to next index
	count++;
    }
    //if it's a null value, tack it on and exit
    else if(sentance[i] == '\0') {
      nextSentance[count] = '\0';
      break;
    }
  }
  cout << nextSentance << endl;
  //secondCount keeps track of copySentance current index
  int secondCount = 0;
  //using the length of nextSentance
    for (int i = count-1; i >= 0; i--) {
      //if it's not null, add it
      if (nextSentance[i] != '\0') {
	copySentance[secondCount] = nextSentance[i];
	secondCount++;
      }
    }
    //null value insurance
    copySentance[secondCount] = '\0';
    //if same backwards and forwards, it's a palindrome!
    if (strcmp(copySentance, nextSentance) == 0) {
      cout << "Palindrome." << endl;
    }
    else {
      cout << "NOT a Palindrome." << endl;
    }
    //exit


  return 0;
}
