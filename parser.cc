
#include <sstream>
#include <stdexcept>
#include "lexer.h"
#include "parser.h"


void LA1Parser::consume() {
    lookahead = this->input->nextToken();
}

int LA1Parser::LT() {
    return lookahead.type();
}

Token LA1Parser::LA() {
    return lookahead;
}

void LA1Parser::match(int tokenType) {
    if (lookahead.type() == tokenType) {
        consume();
    } else {
        ostringstream os;
        os << "Error, expecting token of type " << tokenType << " but saw " << lookahead.type();
        throw runtime_error(os.str());
    }
}

void ListParser::element() {
    if (LT() == T_NAME) {
        match(T_NAME);
    } else if (LT() == T_LBRACK) {
        list();
    } else {
        ostringstream os;
        os << "Expecting name or list, found " << LA().str();
        throw runtime_error(os.str());
    }
}

void ListParser::elements() {
    element();
    while (LT() == T_COMMA) {
        match(T_COMMA);
        element();
    }
}

void ListParser::run() {
    list();
}

void ListParser::list() {
    match(T_LBRACK);
    elements();
    match(T_RBRACK);
}

