#include <stdlib.h>
#include "../lib/TestSuite.h"

void should_set_suite_name(TestSuite* suite){
    test_IsNotNull(__func__,suite,suite->suiteName);
}

void should_add_assertion_result(TestSuite* suite){
    
}

TestSuite* suite_test_TestSuite(){
    TestSuite* suite = test_CreateSuite("test_TestSuite");
    
    should_set_suite_name(suite);

    return suite;
}

