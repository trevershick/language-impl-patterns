#include <vector>
#include <cstdlib>
#if DEBUG
#include <iostream>
#endif
#include <sstream>

#include "lexer.h"
#include "multi.h"

#if DEBUG
void showTokens(deque<Token>& t) {
    for(deque<Token>::iterator it = t.begin(); it != t.end(); ++it) {
        cout << it->str();
    }

    cout << endl;
}
#endif
LAParser::LAParser(Lexer* lexer, int lookahead) : Parser(lexer) {
    // fill up the deque
    for (int i=0;i < lookahead; i++) tokens.push_back(input->nextToken());
}

Token LAParser::LA(int i) {
    return tokens.at(i-1);
}

int LAParser::LT(int i) {
    return LA(i).type();
}

void LAParser::consume() {
    tokens.pop_front();
    tokens.push_back(input->nextToken());
#if DEBUG
    cout << "Look Ahead -> " ;
    showTokens(tokens);
#endif
}

LAParser::~LAParser() {
}

void LAParser::match(int tokenType) {
#if DEBUG
    cout << "Match:" << tokenType << endl;
#endif
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

