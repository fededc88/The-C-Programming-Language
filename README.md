# The-C-Programming-Language-second-edition-

## Testing
Starting from Chapter 4 I will be running some local test for the exercises using
[Ceedling](http://www.throwtheswitch.org/ceedling). Ceedling is an automated
testing framework for C applications. Unity is the unit test framework provided
with Unity that give us all of the test assertions. Unity is written in 100%
pure C code. It follows ANSI standards while supporting most embedded compiler
quirks. To run them, just install  ceedling and get a C/C++
compiller to have the framework running. 

Ceedling requires Ruby to run and uses GCC to build each test.

* [1] Install Ruby
  * apt (Debian or Ubuntu)

  ```
  sudo apt-get install ruby-full
  ```

* [2] Install Ceedling with the Ruby "gem" tool

  ```
  gem install ceedling
  ```

* [3] Install GCC 
  * apt (Debian or Ubuntu)

  ```
  sudo apt install build-essential
  ```

* And them, to compile source files and execute tests run:

  ```
  ceedling test
  ```

Ceedling will present you the results as console outputs. 
