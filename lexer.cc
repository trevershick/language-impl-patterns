#include "lexer.h"
#include <stdexcept>
#include <sstream>



string Token::str() {
    ostringstream os;
    os << "<'" << _text << "', " << name() << ">";
    return os.str();
}

string Token::name() {
    switch (_type) {
        case T_EOF:
            return "<EOF>";
        case T_NAME:
            return "NAME";
        case T_COMMA:
            return "COMMA";
        case T_LBRACK:
            return "LBRACK";
        case T_RBRACK:
            return "RBRACK";
        default:
            return "n/a";
    }
}

Lexer::Lexer(string in) {
    input = in;
    p = 0;
    c = input.at(p);
}

void Lexer::consume() {
    // move the p index up one and update the 'c' value
    this->p++;
    if (p > input.length() - 1) {
        c = T_EOF;
    } else {
        c = input.at(p);
    }
}

void Lexer::match(char expected) {
    if (c == expected) {
        consume();
    } else {
        ostringstream message;
        message << "Expected " << expected << " but found " << c;
        throw runtime_error("what1");
    }
}

char Lexer::la() {
    return c;
}

ListLexer::ListLexer(string in) : Lexer(in) {};

bool ListLexer::isLETTER() {
    char c = la();
    return (c >='a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

Token ListLexer::NAME() {
    ostringstream buffer;
    do {
        buffer << la();
        consume();
    } while (isLETTER());
    return Token(T_NAME, buffer.str());
}

Token ListLexer::nextToken() {
    char c;
    while ((c=la()) != T_EOF) {
        switch (c) {
            case ' ':
            case '\t':
            case '\n':
            case '\r':
                consume();
                continue;
            case '[':
                consume();
                return Token(T_LBRACK, string(1,c));
            case ']':
                consume();
                return Token(T_RBRACK, string(1,c));
            case ',':
                consume();
                return Token(T_COMMA, string(1,c));
            default:
                if (isLETTER()) {
                    return NAME();
                } else {
                    ostringstream os;
                    os << "Invalid Character '" << c << "'";
                    throw runtime_error("what2");
                }
        }
    }
    return Token(T_EOF, "<EOF>");
}
