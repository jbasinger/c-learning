
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "TestSuite.h"

void failAssertion(TestSuite* suite);

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

void test_IsEqual(const char* functionName, TestSuite* suite, int lhs, int rhs){
    
    suite->assertions++;
    
    if(lhs == rhs)
        return;

    failAssertion(suite);    
}

void test_IsNotNull(const char* functionName, TestSuite* suite, char* str){
    suite->assertions++;
    
    if(strlen(str) > 0)
        return;

    failAssertion(suite);
}

void failAssertion(TestSuite* suite){
    suite->failedAssertions++;
}