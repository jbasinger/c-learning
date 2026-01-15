#!/bin/bash

docker build -t clearning .

docker run --rm -it \
  clearning /bin/bash
