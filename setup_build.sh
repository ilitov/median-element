if test -z $1
then
    # Setting default build type to release
    BUILD_TYPE="Release"
else
    BUILD_TYPE=$1
fi

echo "Using build type = $BUILD_TYPE"

cmake -E make_directory ./build
cmake -S . -B ./build -DCMAKE_BUILD_TYPE=$BUILD_TYPE
