# C Test Framework Design

This is just me goofing around with C and wanting to have a testing framework for it.  
It's kind of a mess. Over all idea is to have a data structure that can manage assertions that are made and the
names of functions/files it's running under. Not sure how to make the test thing testable, but I think I can.  

Things with ? in them are still unsure

## Requirements

* ~~Single executable~~ Static Library w/header
* Inputs C files
    * ~~Compiles/links/etc them?~~ Too hard
    * ~~Have a config file of function names to call~~ Also hard
    * Easy boilerplate function to call in Main? - feels like a good v1

* Outputs return error code if test fails, prints failures
* Outputs return code 0, prints success
* printing toggle-able for CI/CD

## Behind the scenes

Create an instance of our testing context/service and pass it to each test function

```
//WIP
int main(){
    TestService *srv = TestService_factory.new()

    my_test_should(srv);

    bool result = srv.results();
    //clean up srv
    return result;
}
```

### TestService design
* Contains count of assertions.
* Fail test if assertion count is 0
* Fail if failing assertion count is > 0
* Pass otherwise

## API
* A pointer to the service to run assertions is passed into test functions
* Assertions
    * Equals - int, float, double, long, char
    * Not equals
    * Greater Than
        * Greater Than for Strings (Alphabetical)
    * Less Than
        * Less Than for Strings (Alphabetical)
    * Greater Than or EqualTo
        * Greater Than or EqualTo for Strings (Alphabetical)
    * Less Than or EqualTo
        * Less Than or EqualTo for Strings (Alphabetical)



## Useful Links
* https://tldp.org/HOWTO/Program-Library-HOWTO/shared-libraries.html