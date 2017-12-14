#ifndef __LAPARSER_H
#define __LAPARSER_H

#include "lexer.h"
#include "parser.h"
#include <deque>

class LAParser : public Parser {
public:
  LAParser(Lexer *lexer, int lookahead);
  ~LAParser();

protected:
  shared_ptr<Token> LA(int i);
  int LT(int i);
  virtual void consume();
  virtual void match(int type);

private:
  deque<shared_ptr<Token>> tokens;
};

class ListLAParser : public LAParser {
public:
  ListLAParser(Lexer *lexer, int lookahead) : LAParser(lexer, lookahead){};
  void run();

private:
  void list();
  void elements();
  void element();
};

#endif
