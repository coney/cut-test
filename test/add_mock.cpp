
    #include "add_mock.h"

    IMPLEMENT_FUNCTION_MOCK2(
        AddMock, add, int(int, int));




    DECLARE_FUNCTION_MOCK2(AddMock, add, int(int, int))
    {
    }

    IMPLEMENT_FUNCTION_MOCK2(AddMock, add, int(int, int))
    {
    }
