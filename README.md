# protonng
RPC implementation for Protocol Buffers using NNG.

# Dependencies
* cmake
  * Ubuntu install:
    * `sudo apt-get install cmake`
* Google Protocol Buffers
  * https://developers.google.com/protocol-buffers/
  * Ubuntu install:
    * `sudo apt-get install libprotobuf-dev libprotoc-dev protobuf-compiler`
* nng
  * https://github.com/nanomsg/nng
  * Follow nng README to install
* nngpp
  * https://github.com/cwzx/nngpp
  * Header-only library, C++ wrapper around nng
  * Copy include/nngpp/ to /usr/local/include
