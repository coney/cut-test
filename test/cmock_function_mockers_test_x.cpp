#ifndef __GNUC__

    #include <cmock/cmock.h>
    #include "add_mock.h"

    using namespace ::testing;
    TEST(FunctionMock, CMockIsAbleToMockCFunction) {
        {
            AddMock mock;
            EXPECT_FUNCTION_CALL(mock, (1, 2)).WillOnce(Return(0));
            EXPECT_FUNCTION_CALL(mock, (2, 3)).WillRepeatedly(Return(0));
            ASSERT_EQ(0, add(1, 2));
        }
        ASSERT_EQ(3, add(1, 2));
    }

/**
* real static mock class field holds pointer to real function.
*/
TEST(FunctionMockersTest, FunctionMockExportsRealFunctionPointer) {
    EXPECT_EQ(3, AddMock::real(1, 2));
}

#endif // __GNUC__
