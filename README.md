# C Learning
This is just a little repo I'm making to play with and learn C for fun.  
It is probably all inefficient, disorganized and sloppy, but I'm going to try and share some code and static libraries.  

## test_svl

This is a small testing framework I'm building as I go along. It'll use itself to run tests.  

### Running things in 
`make build` will build the testing framework.
`make test` will run the testing framework's tests in which it uses itself to test itself.  
`make clean` will clean everything up.  

To run these things in a docker container interactively, run `docker-compose run cli`  
