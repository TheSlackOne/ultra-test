FROM alpine:3.14

# Install dependencies
RUN apk add --no-cache bash
RUN apk add --no-cache g++
RUN apk add --no-cache cmake
RUN apk add --no-cache make
RUN apk add --no-cache boost-dev

# Copying files.
ADD . /ultra-test

WORKDIR /ultra-test

# Building
RUN mkdir -p build && cd build && pwd && cmake .. && make -j$(nproc)

ENTRYPOINT ["build/tests", "-l", "all"]
