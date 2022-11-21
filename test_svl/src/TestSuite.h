
#ifndef _TEST_SUITE
#define _TEST_SUITE
    
typedef struct TestSuite {
    int assertions;
    int failedAssertions;
    char* suiteName;
} TestSuite;

TestSuite* test_CreateSuite(const char* suiteName);
int test_GetResults(TestSuite*);

void test_IsEqual(const char*,TestSuite*,int,int); // <= 0 == false,  > 0 == true
void test_IsNotNull(const char*,TestSuite*,char*);

#endif
