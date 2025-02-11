cmake_minimum_required(VERSION 3.20)

#User define
# 删除或注释掉 GCC 相关设置
# set(CMAKE_C_COMPILER "/usr/local/bin/gcc-14")
# set(CMAKE_CXX_COMPILER "/usr/local/bin/gcc-14")
set(SPARSEHASH_INCLUDE_DIR "/usr/local/include")
set(Boost_INCLUDE_DIR "/usr/local/include")

project(FSQM)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 基础编译标志
set(BASE_CXX_FLAGS "-O3 -fpermissive -DNDEBUG -DIL_STD -Wno-ctor-dtor-privacy")

# OpenMP 支持检查
find_package(OpenMP)
if(OpenMP_CXX_FOUND)
    set(CMAKE_CXX_FLAGS "${BASE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
else()
    set(CMAKE_CXX_FLAGS "${BASE_CXX_FLAGS}")
endif()

set(TOOL
        src/qasm-tools/QASMtoken.cpp
        src/qasm-tools/QASMparser.cpp
        src/qasm-tools/QASMscanner.cpp)
set(SRC
        src/parser.cpp
        src/couplinggraph.cpp
        src/graph.cpp
        src/graphFunction.cpp
        src/mapping.cpp
        src/mappingPreparation.cpp
        src/mappingFunction.cpp
        src/initial_mapping.cpp
        src/outputwriter.cpp
        src/mymeasure.cpp
        src/print.cpp)

add_executable(FSQM src/main.cpp ${SRC} ${TOOL})

if(APPLE)
    target_link_libraries(FSQM PRIVATE stdc++ c++)
endif()

target_include_directories(FSQM 
    PRIVATE 
        ${CMAKE_SOURCE_DIR}/include 
        ${Boost_INCLUDE_DIR} 
        ${SPARSEHASH_INCLUDE_DIR}
        /usr/local/include
)

set_target_properties(FSQM PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/tool")

# 添加 Boost 查找
find_package(Boost REQUIRED)


