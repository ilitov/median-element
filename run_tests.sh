cmake --build ./build --config Release --target median_test

if test $? -eq 0
then
    cd ./build && ctest
else
    echo "Build failed"
fi
