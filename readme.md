# JSON Web Token Library

Library for encoding and decoding JSON web tokens for the MAC OS and Linux platforms.

## Limitations

 - It is not currently possible for windows
 - The header is fixed to be {"alg": "HS256", "typ": "JWT"}

## Compatible Platform

 - MAC OS
 - Linux

## How To Use

- Build Library
  ~~~shell
    # project root path
    make && make install
    # it will build the library
    # and copy to $(projectRootPath)/output path 
  ~~~

- Build Example
  ~~~shell
    # project root path
    # cd to example path and compile
    cd example
    make && make install
    # it will build the jwt-test 
    # and copy to in $(projectRootPath)/output path 
  ~~~

- Test

  ~~~shell
    # when in $(projectRootPath)/output
    ./jwt-test
  ~~~
  it will output like below
  ~~~shell
    start jwt encode:
    username=test-user,PSK=12345678
    get jwt token: eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.dGVzdC11c2VyLDE2OTc1MjQzMDE.9atTOK9Y0WbSG0PmRddspYR6ffY8T7RfHQKenFQMT4Q
    start jwt decode...
    verify jwt token success(username=test-user)
  ~~~  


## License

This code is released under the BSD 3 Clause License.

## Special Thanks

This library uses extracts from the following libraries:
 - Base64 Encoding: https://github.com/Densaugeo/base64_arduino by Densaugeo
 - HMAC-SHA256 Cryptography: https://github.com/Cathedrow/Cryptosuite by Cathedrow
 - ArduinoJWT Cryptography: https://github.com/chrismoorhouse/ArduinoJWT by Chris Moorhouse
