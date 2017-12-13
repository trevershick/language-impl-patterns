#include "lexer.h"
#include "gtest/gtest.h"
#include <iostream>
#include <stdexcept>

TEST(LexerTest, Basic) {
  ListLexer ll("[ a, ]");
  Token lbrack = *ll.nextToken();
  ASSERT_STREQ(lbrack.name().c_str(), "LBRACK");

  Token name = *ll.nextToken();
  ASSERT_STREQ(name.name().c_str(), "NAME");
  ASSERT_STREQ(name.text().c_str(), "a");

  Token comma = *ll.nextToken();
  ASSERT_STREQ(comma.name().c_str(), "COMMA");

  Token rbrack = *ll.nextToken();
  ASSERT_STREQ(rbrack.name().c_str(), "RBRACK");
}
