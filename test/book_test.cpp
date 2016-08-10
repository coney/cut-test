#include <gmock/gmock.h>

class Book {
public:
    virtual void setPrice(int price) = 0;
    virtual void setName(const char *name) = 0;
};

class BookMock {
public:
    MOCK_METHOD1(setPrice, void(int price));
    MOCK_METHOD1(setName, void(const char *name));
};

using namespace ::testing;

TEST(BookMock, ShouldAbleToSetMatcherOnArguments) {
    BookMock bookMock;

    EXPECT_CALL(bookMock, setPrice(10));
    EXPECT_CALL(bookMock, setPrice(_));
    EXPECT_CALL(bookMock, setPrice(Gt(10)));

    EXPECT_CALL(bookMock, setName(StartsWith("C++")));
    EXPECT_CALL(bookMock, setName(MatchesRegex("C..")));

    EXPECT_CALL(bookMock, setPrice(AllOf(Gt(10), Lt(20))));
}