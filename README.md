# median-element
This is an implementation of a data structure that supports adding new elements and calculating the median of the current set of elements
## Code structure
* The implementation of the data structure is located in `/include` and `/src`
* `/test` implements unit tests with the GoogleTest testing framework
* `main.cpp` implements a simple program that demonstrates the usage of the data structure. It reads N integers from the console and prints the current median after each new integer
* The *Median* data structure is implemented as a static library, which is linked to the tests executable **or** the main executable, depending on the build target type
## Median methods
* add(int) - adds a new element to the set
> Time complexity: O(lgN) where N is the number of elements that have already been added
* median() - returns the current median element. It is the arithmetic average of the two medians if the total number of elements is even
> Time complexity: O(1)/constant
## How to build and run
#### Build steps:
```
$ cmake -E make_directory ./build
$ cmake -S . -B ./build -DCMAKE_BUILD_TYPE={Debug/Release}
$ cmake --build ./build --config {Debug/Release}
```
#### Run the main executable:
```
$ ./build/median
```
#### Run the unit tests:
```
$ cd ./build && ctest
```
### You can also use the shell scripts instead of building the project manually:
- Use `setup_build.sh` to create the build directory and generate the build files
- Use `run_tests.sh` to build and run the unit tests
- Use `run_median.sh` to build and run the sample executable
> Note that you need Git Bash or WSL to run the scripts on Windows
