#include "AssertionResult.h"

#ifndef _TestSuite
#define _TestSuite

typedef struct S_TestSuite TestSuite;
struct S_TestSuite {
    int assertions;
    int failedAssertions;
    char* suiteName;
    AssertionResult *failedAssertionListHead;
    AssertionResult *failedAssertionListTail;
};

TestSuite* test_CreateSuite(const char* suiteName);
int test_GetResults(TestSuite*);

void test_Pass(const char* functionName, TestSuite* suite);
void test_Fail(const char* functionName, TestSuite* suite, char* msg);
void test_IsTrue(const char* functionName, TestSuite* suite, int value);
void test_IsFalse(const char* functionName, TestSuite* suite, int value);
void test_IsEqual(const char* functionName, TestSuite* suite, int lhs, int rhs); // <= 0 == false,  > 0 == true
void test_IsNotNull(const char* functionName, TestSuite* suite, const char* variableName, char* str);

#endif
