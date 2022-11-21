#ifndef _AssertionResult
#define _AssertionResult

typedef struct S_AssertionResult AssertionResult;
struct S_AssertionResult {
    char* failureMessage;
    const char* functionName;
    AssertionResult* next;
};

AssertionResult* test_CreateAssertionResult(const char* functionName,char* msg);

#endif