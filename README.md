# Ultra Test
Ultra tech test.

## Requirements
- libboost-test-dev 1.71

## Build and run
```
mkdir build && cd build && cmake .. && make -j$(nproc)
./tests [-l all]
```
## Running on Docker
Building

```
docker build -t ultra-test .
```

Running
```
docker run \
    -v "$(pwd)"/exercise1:/ultra-test/exercise1 \
    -v "$(pwd)"/exercise2:/ultra-test/exercise2 \
    ultra-test
```
This way `exercise1` and `exercise2` directories are shared between host and container, so `test.txt` files can be changed and read.
