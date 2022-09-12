#include <iostream>
using namespace std;

int main() {
  
  // declaring string
  string sentence;
  getline(cin, sentence);
  int words = 0;
  int lenOfSentence = sentence.size();

  for(int i = 0; i < lenOfSentence; i++)
  {
    // check if current character is a space
    if(sentence[i] == ' ')
    {
      words++;
    }

  }
  
  words = words + 1;

  cout << words << endl;

}