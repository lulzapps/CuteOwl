cmake_minimum_required(VERSION 3.20)

project(CuteOwl)

option(CUTEOWL_UNIT_TESTS "Build unit tests (default OFF)" OFF)
option(CUTEOWL_COVERAGE "Enable coverage reporting (default OFF)" OFF)
option(CUTEOWL_CONAN_QT "Use conan to install Qt (default OFF)" ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

 if (CUTEOWL_CONAN_QT)
    include(CMake/conan.cmake)
    conan_cmake_run(REQUIRES
        qt/6.2.2
        libffi/3.4.2
        BASIC_SETUP CMAKE_TARGETS
        GENERATORS cmake_find_package cmake_paths
        BUILD missing
        OPTIONS qt:shared=True)
        include(${CMAKE_BINARY_DIR}/conan_paths.cmake)
 endif(CUTEOWL_CONAN_QT)

add_library(coverage_config INTERFACE)

if(CUTEOWL_COVERAGE AND CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    # Add required flags (GCC & LLVM/Clang)
    target_compile_options(coverage_config INTERFACE
        -O0        # no optimization
        -g         # generate debug info
        --coverage # sets all required flags
    )

    target_link_options(coverage_config INTERFACE --coverage)
endif(CUTEOWL_COVERAGE AND CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")

add_subdirectory(src)

if (CUTEOWL_UNIT_TESTS)
    enable_testing()
    add_subdirectory(test)
endif()
