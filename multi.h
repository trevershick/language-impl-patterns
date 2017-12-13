#ifndef __LAPARSER_H
#define __LAPARSER_H

#include <deque>
#include "parser.h"
#include "lexer.h"

class LAParser : public Parser {
    public:
        LAParser(Lexer* lexer, int lookahead);
        ~LAParser();
        Token LA(int i);
        int LT(int i);
    private:
        deque<Token> tokens;
    protected:
        virtual void consume();
        virtual void match(int type);
        virtual int LT() { return LT(1); }
        virtual Token LA() { return LA(1); }
};

class ListLAParser : public LAParser {
    public:
        ListLAParser(Lexer* lexer, int lookahead) : LAParser(lexer, lookahead) {};
        void run();
    private:
        void list();
        void elements();
        void element();

};

#endif
