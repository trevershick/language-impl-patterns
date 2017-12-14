#ifndef __LEXER_H
#define __LEXER_H

#include <memory>
#include <string>

#define DEBUG 0
#define T_EOF -1
#define T_NAME 2
#define T_COMMA 3
#define T_LBRACK 4
#define T_RBRACK 5
#define T_EQUALS 6

using namespace std;

class Token {
public:
  Token() : _type(0), _text("INVALID"){};
  Token(int type, string text) : _type(type), _text(text){};
  Token(const Token &p);
  virtual ~Token();

  int type() { return _type; }
  string name();
  string str();
  string text() { return _text; }

private:
  int _type;
  string _text;
};

class Lexer {
public:
  Lexer(string input);

  void consume();
  char la();

  // verify the next char is 'c' and consume it.
  void match(char c);

  virtual std::shared_ptr<Token> nextToken() = 0;

private:
  string input;
  int p; // index to current char
  char c;
};

class ListLexer : public Lexer {
public:
  ListLexer(string in);
  virtual shared_ptr<Token> nextToken();

private:
  bool isLETTER();
  shared_ptr<Token> NAME();
};

#endif
