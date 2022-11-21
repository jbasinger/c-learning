#include "includes.h"
#include <stdio.h>
int main(){

    TestSuite* testSuites[]={
        suite_test_ints(),
        suite_test_TestSuite()
    };

    int count=1;
    int failed=0;

    for(int i=0;i<count;i++){
        TestSuite* suite=testSuites[i];
        failed = failed || test_GetResults(suite);
        AssertionResult* node=suite->failedAssertionListHead;
        if(node){
            printf("%s\n", suite->suiteName);
        }
        while(node){
            printf("\t%s: %s\n",node->functionName, node->failureMessage);
            node=node->next;
        }
        
    }

    return !failed;
}