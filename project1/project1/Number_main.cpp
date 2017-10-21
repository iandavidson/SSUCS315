// Assignment : Project 1
// File : Number_main.cpp
// Author : Ian Davidson
// Date  : Spring 2017

#include "Number.hpp"
#include <iostream>
#include <string>


void testRomanToInt(std::string s, bool b, int desiredInt) {
  Number n(s);
  if (n.isALegalRomanNumber() != b) {
    if (b) {
      std::cout << "Legality error: " << s << " should be legal.\n";
    }
    else {
      std::cout << "Legality error: " << s << " should be illegal.\n";
    }
  }
  else if (b && n.intValue() != desiredInt) {
    std::cout << "Conversion error: " << s << " should be "
	      << desiredInt << " but code gives " << n.intValue()
	      << std::endl;
  }
  else {
    std::cout << "Tests passed for " << s << std::endl;
  }
}

void testIntToRoman(int num, bool b, std::string desiredStr) {
  Number n(num);
  if (n.isALegalRomanNumber() != b) {
    if (b) {
      std::cout << "Legality error: " << num << " should be legal.\n";
    }
    else {
      std::cout << "Legality error: " << num << " should be illegal.\n";
    }
  }
  else if (b && n.romanValue() != desiredStr) {
    std::cout << "Conversion error: " << num << " should be "
	      << desiredStr  << " but code gives " << n.romanValue()
	      << std::endl;
  }
  else {
    std::cout << "Tests passed for " << num << std::endl;
  }
}

int main() {
  testRomanToInt("CXII", true, 112);
  testRomanToInt("0", true, 0);
  testRomanToInt("CXIIJ", false, 0);
  testRomanToInt("XCII", true, 92);
  testRomanToInt("MMMCMXCIX", true, 3999);

  testIntToRoman(112, true, "CXII");
  testIntToRoman(0, true, "0");
  testIntToRoman(4000, false, "");
  testIntToRoman(92, true, "XCII");
  testIntToRoman(3999, true, "MMMCMXCIX");

  return 0;
}
