# cpp_battleground
Contains:
* async_thread_app
* lambda_functor_app
* loopers_and_dispatchers_app
* optional_expected_app
* ranges_app

### Pre-requisites for ```optional_expected_app``` and ```ranges_app```
Build and install these libraries

```
$ https://github.com/TartanLlama/expected.git
$ https://github.com/ericniebler/range-v3.git
```

### Build an application
```
$ cd "app_name"
$ cmake . -Bbuild
$ cmake --build build -- -j8
$ ./build/bin/"app_name"
```
