
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "TestSuite.h"

void failAssertion(const char* functionName, TestSuite* suite, char* str);

TestSuite* test_CreateSuite(const char* suiteName){
    
    TestSuite* suite = malloc(sizeof(TestSuite));
    
    suite->assertions=0;
    suite->failedAssertions=0;
    suite->suiteName=strdup(suiteName);

    return suite;
}

int test_GetResults(TestSuite* suite){
    // Ideas: Pass in a logger/printer service
    if(suite->assertions == 0){
        printf("No assertions made.\n");
        return 0;
    }
    if(suite->failedAssertions > 0){
        printf("Tests have failed\n");
        return 0;
    }
    printf("All tests passed successfully!\n");
    return 1;
}

void test_Pass(const char* functionName, TestSuite* suite){
    suite->assertions++;
}

void test_Fail(const char* functionName, TestSuite* suite, char* msg){
    suite->assertions++;
    failAssertion(functionName,suite,"failed");
}

void test_IsTrue(const char* functionName, TestSuite* suite, int item){
    suite->assertions++;
    
    if(item > 0)
        return;

    failAssertion(functionName, suite, "is false");
}

void test_IsFalse(const char* functionName, TestSuite* suite, int item){
    suite->assertions++;
    
    if(item <= 0)
        return;

    failAssertion(functionName, suite, "is true");
}

void test_IsEqual(const char* functionName, TestSuite* suite, int lhs, int rhs){
    
    suite->assertions++;
    
    if(lhs == rhs)
        return;

    failAssertion(functionName, suite, "not equal");
}

void test_IsNotNull(const char* functionName, TestSuite* suite, const char* variableName, char* str){
    suite->assertions++;
    
    if(strlen(str) > 0)
        return;

    const char* isNotNull=" is not null.";
    int msgLen = strlen(variableName) + strlen(isNotNull) + 1;
    char msg[msgLen];
    sprintf(msg,"%s%s",variableName,isNotNull);
    failAssertion(functionName, suite, msg);
}

void failAssertion(const char* functionName, TestSuite* suite, char* message){
    suite->failedAssertions++;

    AssertionResult* result = test_CreateAssertionResult(functionName,message);

    if(suite->failedAssertionListTail != NULL){
        suite->failedAssertionListTail->next = result;
    }

    suite->failedAssertionListTail = result;

    if(suite->failedAssertionListHead == NULL){
        suite->failedAssertionListHead = suite->failedAssertionListTail;
    }


}