#include <cmock/cmock.h>
#include "add_mock.h"

TEST(SpecBuildersTest, ExpectFunctionCallCompiles) {
    AddMock mock;
  EXPECT_FUNCTION_CALL(mock, (1, 2)).Times(0);
}

TEST(SpecBuildersTest, OnFunctionCallCompiles) {
    AddMock mock;
  ON_FUNCTION_CALL(mock, (1, 2));
}
