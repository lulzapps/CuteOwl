find_package(Qt6 
    COMPONENTS 
    Core Gui Widgets QuickWidgets REQUIRED)

set(SOURCE_FILES
    main.cpp
    MainWindow.cpp
    OwlApplication.cpp
    ServerPanel.cpp
    SplashScreen.cpp
)

set(MOC_HEADERS
    MainWindow.h
    OwlApplication.h
    ServerPanel.h
    SplashScreen.h
)

set(HEADER_FILES
    ${MOC_HEADERS}
    Core.h
)

set(UI_SOURCES
    MainWindow.ui
)

set(QRC_FILES
    res/Owl.qrc
)

if (APPLE)
    list(APPEND SOURCE_FILES
        TitleBarSetupMac.mm
    )
endif(APPLE)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_EXPORT_COMPILE_COMMANDS 1)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_VERBOSE_MAKEFILE ON)

add_executable(CuteOwl MACOSX_BUNDLE WIN32
    ${SOURCE_FILES}
    ${HEADER_FILES}
    ${UI_SOURCES}
    ${QRC_FILES}
)

target_link_libraries(CuteOwl
    PRIVATE
        MyLib
        Qt6::Core 
        Qt6::Gui 
        Qt6::Widgets
        Qt6::QuickWidgets
)

if (WIN32)
    target_link_options(CuteOwl PRIVATE "/entry:mainCRTStartup")
endif()

if (APPLE)
    # Since there appear to exist problems with NOT setting the RPATH when building
    # by enabling CMAKE_KEEP_RPATH and others, we just set the libs absolute paths
    # to the conan lib dir.

    function(ChangeRPath target file new)
        add_custom_command(TARGET ${PROJECT_NAME}
                POST_BUILD COMMAND
                ${CMAKE_INSTALL_NAME_TOOL} -change @rpath/${file} ${new}/${file}
                $<TARGET_FILE:${PROJECT_NAME}>)
    endfunction()

    foreach(qt_lib IN LISTS CONAN_LIBS_QT)
        ChangeRPath(${PROJECT_NAME} lib${qt_lib}.dylib ${CONAN_LIB_DIRS_QT})
    endforeach()
endif ()
