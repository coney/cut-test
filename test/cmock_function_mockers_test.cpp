#include <cmock/cmock.h>
#include "add_mock.h"

using namespace ::testing;

/**
 * Function foo is mocked as long as FooFunctionMock instance exists.
 * Once mock function is destroyed, call directs to real function.
 */
TEST(FunctionMockersTest, FunctionIsMockedAsLongAsMockInstanceExists) {

    {
        AddMock mock;
        EXPECT_FUNCTION_CALL(mock, (1, 2))
            .WillOnce(Return(3))
            .WillOnce(Return(0));
        ASSERT_EQ(3, add(1, 2));
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
