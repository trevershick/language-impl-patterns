#include "lexer.h"
#include "gtest/gtest.h"
#include <stdexcept>
#include <iostream>


TEST(LexerTest, Basic) {
    ListLexer ll("[ a, ]");
    Token* lbrack = ll.nextTokenp();
    ASSERT_STREQ(lbrack->name().c_str(), "LBRACK");

    Token* name = ll.nextTokenp();
    ASSERT_STREQ(name->name().c_str(), "NAME");
    ASSERT_STREQ(name->text().c_str(), "a");

    Token* comma = ll.nextTokenp();
    ASSERT_STREQ(comma->name().c_str(), "COMMA");

    Token* rbrack = ll.nextTokenp();
    ASSERT_STREQ(rbrack->name().c_str(), "RBRACK");
}
