
#include <sstream>
#include <stdexcept>
#include "lexer.h"
#include "parser.h"

void Parser::consume() {
    lookahead = this->input->nextToken();
}

void Parser::match(int tokenType) {
    if (lookahead.type() == tokenType) {
        consume();
    } else {
        ostringstream os;
        os << "Error, expecting token of type " << tokenType << " but saw " << lookahead.type();
        throw runtime_error(os.str());
    }
}

void ListParser::element() {
    if (lookahead.type() == T_NAME) {
        match(T_NAME);
    } else if (lookahead.type() == T_LBRACK) {
        list();
    } else {
        ostringstream os;
        os << "Expecting name or list, found " << lookahead.str();
        throw runtime_error(os.str());
    }
}

void ListParser::elements() {
    element();
    while (lookahead.type() == T_COMMA) {
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

