//



#include "Token.hpp"

//print is the only value function of Token which requires more than one line of implementation
void Token::print()
{
  //dont do shit if its the end of text bc theres no reason
  if (this->isEndOfText())
    return;
  
  if (elemTokenValue == '\0'){ //string case (quoted and unquoted)
    cout << valueTokenValue << endl;
    return;
  }
  
  cout << elemTokenValue << endl; //single character case

}

