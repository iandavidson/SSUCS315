// Assignment : Project 1
// File : Number.cpp
// Author : Ian Davidson
// Date  : Spring 2017

#include "Number.hpp"
#include <iostream>


// is the Roman number that is stored in "strNumber" a legal Roman number?
// should also store intNumber in the object after the process of syntax checking
bool Number::isALegalRomanNumber()
{

  // cout << "intNumber " << intNumber << endl;
   
  if (intNumber < -1 || intNumber > 3999)//restraints on intNumbers
    return false;
  // cout << "chance 1";

  
  if (intNumber > -1 && intNumber < 4000)
    return true;
  // cout << "chance 2" << endl;
  
  if (strNumber == "0"){
    intNumber = 0;
    return true;
  }
  
  //  cout << "made it past basecases" << endl;
  
  int strNumLength = strNumber.length(); //avoids warnings
  // cout << strNumLength << endl;
  
  //make sure only correct roman numbers are inputted
  int size = 0;
  
  for (int i = 0; i < strNumLength; i++){

    //gross nasty bullshit that works kinda
    if (strNumber[i] == 'I'||strNumber[i] == 'V' || strNumber[i] == 'X' || strNumber[i] == 'L' || strNumber[i] == 'C' || strNumber[i] == 'D' || strNumber[i] == 'M')
      size++;
    
  }

  if (size != strNumLength)
    return false; //unknown Roman symbols used  

  //go through and tokenize the chunks in string[]
  string romanChunk[size+2];


  cout << "size: " << size << endl;
  // throw all of romanValue in here, as a pre
  int k = 0;//current index of the character in strNumber
  int r = 0;//current index in romanChunk to be assigned to
  while (k < size){    //if k+1 < k then just place k in elem "r"

    if (strNumber[k] == 'V' || strNumber[k] == 'L' || strNumber[k] == 'D'){ //add && conditional k != size-1;
      if (strNumber[k] == strNumber[k+1])
	return false;

    }

      //case for checking if syntax for issues with CCC or IIII, etc
      if (strNumber[k] == 'I' || strNumber[k] == 'X' || strNumber[k] == 'C' || strNumber[k] == 'M'){
          //checks for ie: "II || XX"
          if(strNumber[k] == strNumber[k+1] && strNumber[k] != strNumber[k+2]){
	    romanChunk[r] = strNumber.substr(k, 2);
	    //romanChunk[r] = strNumber[k] + strNumber[k+1];
              k+=2;
              r++;

              //if 3 in a row
          }else if(strNumber[k] == strNumber[k+1] && strNumber[k] == strNumber[k+2] && strNumber[k] != strNumber[k+3]){
	    romanChunk[r] = strNumber.substr(k, 3);
	      // romanChunk[r] = strNumber[k] + strNumber[k+1] + strNumber[k+2];
	    cout << romanChunk[r] << endl;
	    k+=3;
	    r++;
	    cout << "#1 " << endl;
	      
	    //if 4 in a row, return false
          }else if(strNumber[k] == strNumber[k+1] && strNumber[k] == strNumber[k+2] && strNumber[k] == strNumber[k+3]){
              return false;
          }

      }

    //get ready for brute force
    if (strNumber[k] == 'M'){
       if(strNumber[k+1] != 'M'){
            romanChunk[r] = strNumber[k];
            k++;
            r++;
          }
      }


      if (strNumber[k] == 'D'){
          if (strNumber[k+1] == 'M'){
              return false;
          }else{
              romanChunk[r] = strNumber[k];
              k++;
              r++;
          }
      }
      
      if (strNumber[k] == 'C'){
	//cout << "k is C" << endl;
	if (strNumber[k+1] == 'D' || strNumber[k+1] == 'M'){
	  romanChunk[r] = strNumber.substr(k, 2);
	  // romanChunk[r] = strNumber[k] + strNumber[k+1];
	  k += 2;
	  r++;
	  cout << "#2 " << endl;
	}else {
	  romanChunk[r] = strNumber[k];
	  k++;
	  r++;
	}
	
      }
      
      
      if (strNumber[k] == 'L'){
          if (strNumber[k+1] == 'C' || strNumber[k+1] == 'D' || strNumber[k+1] == 'M'){
              return false;
          }else {
              romanChunk[r] = strNumber[k];
              k++;
              r++;
          }
      }

      if (strNumber[k] == 'X')
	{
	//	cout << "[k] is X" << endl;
          //bad syntax for neg capacity. return false
	  if (strNumber[k+1] == 'D' || strNumber[k+1] == 'M')
	    return false;
	  
          if (strNumber[k+1] == 'L' || strNumber[k+1] == 'C'){
	    romanChunk[r] = strNumber.substr(k, 2);
	    // romanChunk[r] = strNumber[k] + strNumber[k+1];
	    k += 2;
	    r++;
	    cout << "#3" << endl;
          }else{
	    romanChunk[r] = strNumber[k];
	    k++;
	    r++;
	    
          }
      }

      if (strNumber[k] == 'V'){
          if (strNumber[k+1] == 'X' || strNumber[k+1] == 'L' || strNumber[k+1] == 'C' || strNumber[k+1] == 'D' || strNumber[k+1] == 'M'){
              return false;
          } else{

              romanChunk[r] = strNumber[k];
              k++;
              r++;
          }
      }


      if ( strNumber[k] == 'I')
      {
	//cout << "k is at 1" << endl;
	//bad syntax for neg capacity, return false
	if (strNumber[k+1] == 'L' || strNumber[k+1] == 'C' || strNumber[k+1] == 'D' || strNumber[k+1] == 'M')
	  return false;
	
	//
	if (strNumber[k+1] == 'V' || strNumber[k+1] == 'X'){
	  romanChunk[r] = strNumber.substr(k, 2);
	  //  romanChunk[r] = strNumber[k] + strNumber[k+1];
	  k += 2;
	  r++;
	  cout << "#last" << endl;
	}else{
	  romanChunk[r] = strNumber[k];
	  k++;
	  r++;
	}
      }
      
      

      //    cout << "k: " << k <<  "r: "  << r << endl;
    
  }
  int sum = 0;


  //cout << "k: " << k <<  "r: "  << r << endl;
  //  cout << "made it to 2" << endl;
  for(int j = 0; j < r; j++){
    sum += evaluateRomanNumber( romanChunk[j]);
    //cout << romanChunk[j] << endl;
  }
  cout << "Sum :" << sum << endl;
  intNumber = sum;
  return true;
//assign newly found int value to intNumber

}

int Number::evaluateRomanNumber(string chunk)
{

  //hard coded all the possible chunks
  if (chunk == "I"){
    return 1;

  }else  if (chunk == "II"){
    return 2;

  }else if (chunk == "III"){
    return 3;

  }else if (chunk == "IV"){
    return 4;

  }else if (chunk == "V"){
    return 5;

  }else if (chunk == "IX"){
      return 9;

  }else if (chunk == "X"){
    return 10;

  }else if (chunk == "XX"){
    return 20;

  }else if (chunk == "XXX"){
    return 30;

  }else if (chunk == "XL"){
    return 40;

  }else if (chunk == "L"){
    return 50;
    
  }else if (chunk == "XC"){
    return 90;

  }else if (chunk == "C"){
    return 100;

  }else if (chunk == "CC"){
    return 200;

  }else if (chunk == "CCC"){
    return 300;

  }else if (chunk == "CD"){
    return 400;

  }else if (chunk == "D"){
    return 500;

  }else if (chunk == "CM"){
    return 900;

  }else if (chunk == "M"){
    return 1000;

  }else if (chunk == "MM"){
    return 2000;

  }else if (chunk == "MMM"){
    return 3000;

  }else
    return 0;

}



int Number::intValue()
//assuming romanNumeral in strNumber is a legitimate romanNumeral
// Return the int value of this Roman number.  If the instance was
// created by having used a decimal number, just return it.
// Otherwise, convert "strNumber" to its decimal counterpart and
// return it.  Note that you may already have converted it when the
// user called "isALegalRomanNumber". 
// reference:: http://codereview.stackexchange.com/questions/22876/converting-roman-numerals-to-decimal
{

  if (strNumber == "0"){
    intNumber = 0;
    return intNumber;
  }
      
//blindly calls isLegalRoman
  isALegalRomanNumber();
//returns number (assigned though member var: intNumber)
  return intNumber;
//if str is invalid, check by calling isalegal


}

string Number::romanValue()
//converts intNumber into its Roman counterpart and return it as a string
{
  //short circuit if instance already has a RomanNumber assigned.
  if (strNumber != "")
    return strNumber;
  
  //check if intNumber actually exists, if not return empty string. intNumber will be -1 if only the string constructor is called.
  if ( intNumber < 0 || intNumber > 3999)
    return "";

  if (intNumber == 0)
    return "0";

  int numCopy = intNumber;// will be destroyed to find how many digits are in intNumber

  int numLength = 0;
  while (numCopy != 0)
    {
      numCopy = numCopy / 10;
      numLength++;
    }

  numCopy = intNumber;// variable re used to break down in order to find each digits' value
  
  string romanChunks[5]; //4 represents the largest amount of digits able to translate to RNs

  int val;

  //  cout << "intNumber: " << intNumber << endl;

  //go from smallest to largest
  for (int i = 0; i < numLength; i++){ 
    // i represents the number of digits over from the right, i = 0 refers to 1s place
    // i = 2 refers to 10s place, etc.

    val = numCopy % 10;

    //    cout << "i: " << i << " val: " << val << endl;
    //    cout << 
    //cases for 1s, 10s, 100s, 1000s and their calls
    if ( i == 0){// 1s place
      romanChunks[i] = assignRomanPart(val, "I", "V", "X");
      // cout << "Ons place: " << romanChunks[i] <<  endl;
      
    }else if ( i == 1){//tens
      romanChunks[i] = assignRomanPart(val, "X", "L", "C");
      // cout << "Tens Place: " <<romanChunks[i] << endl;
      
    }else if (i == 2){ //hundres
      romanChunks[i] = assignRomanPart(val, "C", "D", "M");
      //  cout << "Hun place : " << romanChunks[i] << endl;
      
    }else if (i == 3){ //thousands 
      romanChunks[i] = assignRomanPart(val, "M", "\0", "\0");//in these cases val is always <4
      //      cout << "thou place : " << romanChunks[i] << endl;
      
    }  
    //divide numCopy by 10 for next iteration to work properly
    
    numCopy = numCopy/10;

    //
  }

  string final = "";
  for (int j = numLength; j >= 0; j--){
    final += romanChunks[j];

  }

  //assignment of  strNumber
  strNumber = final;
  
  return final;
}
//https://www.daniweb.com/programming/software-development/threads/283305/converting-integer-to-roman
//http://www.cplusplus.com/forum/beginner/50617/

string Number::assignRomanPart(int n, string one, string five, string ten)
//function: take a number between 0-9 and returns the roman numeral corrisponding to the number passed
//params: n = number between 0-9, one = ones value digit place of n in intNumbers, five = five value digit place of n, ten = ten value for digit place of n
{
  if (n == 1){
    return one;
    
  }else if (n == 2) {
    return one + one;

  }else if (n == 3) {
    return one + one + one;

  }else if (n == 4){
    return one + five;
    
  }else if (n == 5){
    return five;

  }else if (n == 6){
    return five + one;

  }else if (n == 7){
    return five + one + one;

  }else if (n == 8){
    return five + one + one + one;

  }else if (n == 9){
    return one + ten;

  }else //if n == 0 return empty string
    return "";


}


