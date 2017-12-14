#include "multi.h"
#include "gtest/gtest.h"
#include <stdexcept>

TEST(ParserTest, Assignments) {
  ListLexer ll("[a,[a, [b=c]]]");
  ListLAParser lp(&ll, 2);
  lp.run();
}

TEST(ParserTest, NestedLists) {
  ListLexer ll("[a,[a, [b]]]");
  ListLAParser lp(&ll, 2);
  lp.run();
}

TEST(ParserTest, FailureThrowsException) {
  ListLexer ll("[a, ]");
  ListLAParser lp(&ll, 2);

  ASSERT_THROW(lp.run(), runtime_error);
}
