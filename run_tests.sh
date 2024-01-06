cmake --build ./build --target median_test

if test $? -eq 0
then
    echo "Running tests..."
    ./build/test/median_test
else
    echo "Failed to compile the tests"
fi
