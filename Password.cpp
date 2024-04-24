#include "Password.h"
#include <string>
#include <cctype>

using std::string;

/*
  The function receives a string counts how many times the same character 
  occurs at the beginning of the string, before any other characters (or the
  end of the string). The function is case-sensitive so 'Z' is different than
  'z' and any ASCII characters are allowed.
*/
int Password::count_leading_characters(string phrase){
  int repetition = 1;
  int index = 0;
  while( index < phrase.length()-1 && phrase[index] == phrase[index+1] ){
    repetition++;
    index++;
  }
  return repetition;
}

/*
  receives a string and returns whether it has both at least one upper-case
  letter and at least one lower-case letter
*/
bool Password::has_mixed_case(string str)
{
  bool upper_check = false;
  bool lower_check = false;
  for (int i = 0; i < str.length(); i++){
    if (isupper(str[i])){
      upper_check = true;
    }
    else if (islower(str[i])){
      lower_check = true;
    }
  }
  return upper_check && lower_check;
}

/*
  constructor sets the default password to "ChicoCA-95929"
  */
  Password::Password()
  {
    pass_history.push_back("ChicoCA-95929");
  }


 /*
  receives a password and sets the latest in pass_history to it if and only
  if it meets all criteria:
    1. The password is at least 8 letters long, but no longer than 20
    2. It has no more than 3 of the same leading characters
    3. It has mixed case (at least one upper case and at least one lower case)
    4. It was not a previous password in the history
  */
  void Password::set(string str)
  {
    int i;
    int count;
    char letter;

    if (str.length() >= 8 && str.length() <= 20 && has_mixed_case(str)){
      for (i = 0; i < pass_history.capacity(); i++){
        if (str == pass_history[i]){
          exit;
        }
      }
      
      letter = str[0];
      count = 1;
      for (i = 1; i < str.length(); i++){
        if (letter == str[i]){
          count++;
          if (count > 3){
            exit;
          }
        } else {
          count = 1;
          letter = str[i];
        }
      }

      pass_history.push_back(str);
    }
  }

  /*
  receives a string and authenticates it against the latest password in the
  pass_history, returning true for an exact match or false when it does not match
  or if a password has not been set.
  */
  bool Password::authenticate(string str)
  {
    if (str == pass_history.back()){
      return true;
    }
    return false;
  }