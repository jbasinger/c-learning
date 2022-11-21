typedef struct AssertionResult {
    int passed;
    char* failureMessage;
    char* functionName;
} AssertionResult;