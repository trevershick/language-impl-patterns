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
        virtual const Token* LA() = 0;
};

#endif
