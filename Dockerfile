FROM ubuntu

RUN apt-get update && apt-get install -yqq \
  build-essential vim tree curl

WORKDIR /build

COPY ppm/ ppm/
COPY test_svl/ test_svl/ 

RUN cd /build/ppm && ./build.sh
RUN cd /build/test_svl && make all



