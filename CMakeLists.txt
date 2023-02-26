cmake_minimum_required(VERSION 3.20)

project(CuteOwl)

option(CUTEOWL_UNIT_TESTS "Build unit tests (default OFF)" OFF)
option(CUTEOWL_COVERAGE "Enable coverage reporting (default OFF)" OFF)
option(CUTEOWL_CONAN_QT "Use conan to install Qt (default OFF)" ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CONAN_DISABLE_CHECK_COMPILER ON)

# required so that find_package() can find conan generated files
list(APPEND CMAKE_MODULE_PATH "${CMAKE_BINARY_DIR}")

 if (CUTEOWL_CONAN_QT)
    include(CMake/conan.cmake)
    conan_cmake_configure(
        REQUIRES
            openssl/1.1.1t
            qt/6.4.2
        GENERATORS
            cmake_find_package
            cmake_paths
        OPTIONS
            qt:shared=True
            qt:qtshadertools=True
            qt:qtdeclarative=True
    )

    conan_cmake_autodetect(settings)

    conan_cmake_install(PATH_OR_REFERENCE .
        BUILD
            missing
        REMOTE
            conancenter
        SETTINGS
            ${settings}
    )

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
