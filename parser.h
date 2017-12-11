#include "lexer.h"

#ifndef __PARSER_H
#define __PARSER_H


class Parser {
    public:
        Parser(Lexer* lexer) : input(lexer), lookahead(lexer->nextToken()) {};
        virtual ~Parser() {};
    private:
        Lexer* input;
    protected:
        Token lookahead;
        void match(int type);
        void consume();
};

class ListParser : public Parser {
    public:
        ListParser(ListLexer* ll) : Parser(ll) {};
        virtual ~ListParser() {};
        void run();
    private:
        void list();
        void elements();
        void element();
};

#endif
