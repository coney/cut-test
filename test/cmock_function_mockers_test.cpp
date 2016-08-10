#include <cmock/cmock.h>
#include "add_mock.h"

using namespace ::testing;

/**
 * Function foo is mocked as long as FooFunctionMock instance exists.
 * Once mock function is destroyed, call directs to real function.
 */
TEST(FunctionMockersTest, FunctionIsMockedAsLongAsMockInstanceExists) {

    {
        Sequence seq;
        AddMock mock;
        EXPECT_FUNCTION_CALL(mock, (1, 1)).InSequence(seq).WillOnce(Return(3));
        EXPECT_FUNCTION_CALL(mock, (1, 2)).InSequence(seq).WillOnce(Return(3));
        EXPECT_FUNCTION_CALL(mock, (1, 3)).Times(2).InSequence(seq).WillRepeatedly(Return(3));
        ASSERT_EQ(3, add(1, 1));
        ASSERT_EQ(3, add(1, 2));
        ASSERT_EQ(3, add(1, 3));
        ASSERT_EQ(3, add(1, 3));
    }

    ASSERT_EQ(3, add(1, 2));
}

    using namespace ::testing;
    TEST(FunctionMock, CMockIsAbleToMockCFunction) {
        {
            AddMock mock;
            EXPECT_FUNCTION_CALL(mock, (1, 2)).WillOnce(Return(0));
            EXPECT_FUNCTION_CALL(mock, (2, _)).WillRepeatedly(Return(2));
            ASSERT_EQ(0, add(1, 2));
            ASSERT_EQ(2, add(2, 3));
        }
        ASSERT_EQ(3, add(1, 2));
    }


/**
 * real static mock class field holds pointer to real function.
 */
TEST(FunctionMockersTest, FunctionMockExportsRealFunctionPointer) {
    EXPECT_EQ(3, AddMock::real(1, 2));
}
