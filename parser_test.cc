#include "parser.h"
#include "gtest/gtest.h"
#include <stdexcept>

TEST(ParserTest, FailureThrowsException) {
   ListLexer ll("[a, ]");
   ListParser lp(&ll);

   ASSERT_THROW(lp.run(), runtime_error);
}

TEST(ParserTest, NestedLists) {
   ListLexer ll("[a,[a, [b]]]");
   ListParser lp(&ll);
}
