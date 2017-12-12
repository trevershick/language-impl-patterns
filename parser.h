#include "lexer.h"

#ifndef __PARSER_H
#define __PARSER_H


class Parser {
    public:
        Parser(Lexer* lexer) : input(lexer) {};
        virtual ~Parser() {};
    protected:
        Lexer* input;
        virtual void match(int type) = 0;
        virtual void consume() = 0;
        virtual int LT() = 0;
        virtual Token LA() = 0;
};

class LA1Parser : public Parser {
    public:
        LA1Parser(Lexer* lexer) : Parser(lexer), lookahead(lexer->nextToken()) {};
        virtual ~LA1Parser() {};
    protected:
        Token lookahead;
        virtual void consume();
        virtual void match(int type);
        virtual int LT();
        virtual Token LA();
};

class ListParser : public LA1Parser {
    public:
        ListParser(ListLexer* ll) : LA1Parser(ll) {};
        virtual ~ListParser() {};
        void run();
    private:
        void list();
        void elements();
        void element();
};

#endif
