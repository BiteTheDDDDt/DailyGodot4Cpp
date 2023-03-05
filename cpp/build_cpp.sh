root_path=$(
    cd $(dirname $0)
    pwd
)
echo "root_path: ${root_path}"

mkdir ./build

cd build
touch ./.gdignore

cmake -G Ninja .. -DCMAKE_CXX_COMPILER_LAUNCHER=ccache
ninja -C .

cp src/DailyGodot4Cpp.dll ../../resources/extension