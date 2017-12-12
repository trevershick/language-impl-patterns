#include <vector>
#include <cstdlib>
#include <sstream>

#include "lexer.h"
#include "multi.h"

LAParser::LAParser(Lexer* lexer, int lookahead) : Parser(lexer), la(lookahead), idx(0) {
    // fill up the deque
    tokens = new Token[lookahead];
    for (int i=0;i < la; i++) tokens[i] = input->nextToken();
}

Token LAParser::LA(int i) {
    return tokens[(idx+i-1) % la];
}

int LAParser::LT(int i) {
    return LA(i).type();
}

void LAParser::consume() {
    tokens[idx] = input->nextToken();
    idx = (idx + 1) % la;
}

LAParser::~LAParser() {
    delete [] tokens;
}

void LAParser::match(int tokenType) {
    if (LT(1) == tokenType) {
        consume();
    } else {
        ostringstream os;
        os << "Error, expecting token of type " << tokenType << " but saw ";;// << LT(1);
        throw runtime_error(os.str());
    }
}




void ListLAParser::element() {
    int l1 = LT(1), l2 = LT(2);

    if (l1 == T_NAME && l2 == T_EQUALS) {
        match(T_NAME);
        match(T_EQUALS);
        match(T_NAME);
    } else if (l1 == T_NAME) {
        match(T_NAME);
    } else if (l1 == T_LBRACK) {
        list();
    } else {
        ostringstream os;
        os << "Expecting name or list, found "; //<< LA(1).str();
        throw runtime_error(os.str());
    }
}

void ListLAParser::elements() {
    element();
    while (LT(1) == T_COMMA) {
        match(T_COMMA);
        element();
    }
}

void ListLAParser::run() {
    list();
}

void ListLAParser::list() {
    match(T_LBRACK);
    elements();
    match(T_RBRACK);
}

