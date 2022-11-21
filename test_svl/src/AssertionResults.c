#include <stdlib.h>
#include "AssertionResult.h"

AssertionResult* test_CreateAssertionResult(const char* functionName,char* msg){
    AssertionResult* result = malloc(sizeof(AssertionResult));
    result->functionName=functionName;
    result->failureMessage=msg;
    return result;
};