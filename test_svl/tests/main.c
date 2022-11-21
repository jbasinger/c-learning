#include "includes.h"

int main(){

    TestSuite* testSuites[]={
        suite_test_ints(),
        suite_test_TestSuite()
    };

    int count=1;
    int failed=0;

    for(int i=0;i<count;i++){
        failed = failed || test_GetResults(testSuites[i]);
    }

    return !failed;
}



