#include <stdlib.h>
#include "../lib/TestSuite.h"

void should_be_equal(TestSuite* suite){
    test_IsEqual(__func__,suite,1,1);
}

TestSuite* suite_test_ints(){
    TestSuite* suite = test_CreateSuite("test_ints");
    
    should_be_equal(suite);

    return suite;
}

