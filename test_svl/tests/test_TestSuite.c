#include <stdlib.h>
#include "../lib/TestSuite.h"

void should_set_suite_name(TestSuite* suite){
    test_IsNotNull(__func__,suite,"suiteName",suite->suiteName);
}

void should_add_assertion_result(TestSuite* suite){
    TestSuite* test = test_CreateSuite("fake");
    
    test_IsFalse("fake_test",test,1);
    test_IsNotNull(__func__,suite,"failure message",test->failedAssertionListHead->failureMessage);
    free(test);
}

TestSuite* suite_test_TestSuite(){
    TestSuite* suite = test_CreateSuite("test_TestSuite");
    
    should_set_suite_name(suite);
    should_add_assertion_result(suite);

    return suite;
}

