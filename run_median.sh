cmake --build ./build --target median

if test $? -eq 0
then
    echo "Running executable..."
    ./build/median
else
    echo "Failed to compile"
fi
