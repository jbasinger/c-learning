FROM gcc AS build
WORKDIR /build
COPY . .
WORKDIR /code
ENTRYPOINT [ "/bin/bash" ]