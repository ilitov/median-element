cmake --build ./build --config Release --target median

if test $? -eq 0
then
    echo "Running main executable..."
    ./build/median
else
    echo "Build failed"
fi
