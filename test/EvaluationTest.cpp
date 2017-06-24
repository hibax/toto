#include <limits.h>
#include "gtest/gtest.h"
#include "Evaluation.h"

class EvaluationTest : public ::testing::Test {
 protected:
  virtual void SetUp() {
  }

  virtual void TearDown() {
  }
};

TEST_F(EvaluationTest,firstTest){
    Board board;
    EXPECT_EQ(2,Evaluation::score(board));
}

