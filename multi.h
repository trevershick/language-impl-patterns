#ifndef __LAPARSER_H
#define __LAPARSER_H

#include <deque>
#include "parser.h"
#include "lexer.h"

class LAParser : public Parser {
    public:
        LAParser(Lexer* lexer, int lookahead);
        ~LAParser();
    protected:
        Token& LA(int i);
        int LT(int i);
        virtual void consume();
        virtual void match(int type);
    private:
        deque<unique_ptr<Token>> tokens;
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
