#include<iostream>
#include<string>

#ifndef TOKEN_HPP
#define TOKEN_HPP

/*

 This class represent the notion of a token; the building blocks of
 Roman expressions. In this context, a token either represents an
 operator (the addition, subtraction, multiplication, division, or
 modulo arithmetic operators), open or close parentheses, or a Roman
 number.

 CHOP OFF "i =" part before saving to tokens


 Currently, it doesn't support variables (single lower-case letters.)
 You will have to add code for that purpose.

 To create a token, you can do the following:

 Token *tok = new Token('+'); // create a token to represent the addition op.

 or

 Token tok('+');

 On the other hand, for certain tokens, you will have to create a token 
 first and set it later.

 Token *tok = new Token();  // an uninitialize token
 tok->eof(true);            // make it represent EOF token.

*/


class Token {

public:
    Token() { init(); }
    Token(char c) { init(); _symbol = c; }
  Token(int i) { init(); _digitNumber = i; }
    Token(const std::string s) { init(); _romanNumber = s; }

    std::string romanNumber() const     { return _romanNumber; }
    void romanNumber( std::string str ) { _romanNumber = str; }

    int getDigitNumber() { return _digitNumber;}
    void setDigitNumber(int v) { _digitNumber = v;} 

    bool eof() const { return _eof; }
    void eof(bool v) { _eof = v;    }

    bool eol() const { return _eol; }
    void eol(bool v) { _eol = v;    }

    bool isOpenParen() const  { return _symbol == '('; }
    bool isCloseParen() const { return _symbol == ')'; }

    bool isEqualSign() const              { return _symbol == '='; }
    bool isMultiplicationOperator() const { return _symbol == '*'; } 
    bool isAdditionOperator() const       { return _symbol == '+'; } 
    bool isSubtractionOperator() const    { return _symbol == '-'; } 
    bool isModuloOperator() const         { return _symbol == '%'; } 
    bool isDivisionOperator() const       { return _symbol == '/'; } 
    bool isAVariable() const              { return _symbol >= 'a' && _symbol <= 'z'; } 
    char getVariable() const              { return _symbol; }

    bool isRomanNumber() const { return _romanNumber.length() > 0; } 

    void print() const;

private:
    void init() {

        _digitNumber = 0;
        _romanNumber = "";
        _eof = _eol = false; 
        _symbol = '\0';
    }

    int _digitNumber ;
    std::string _romanNumber;
    bool _eof, _eol;
    char _symbol;
};

#endif
