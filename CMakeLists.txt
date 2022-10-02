cmake_minimum_required(VERSION 3.0.0)
project(LosslessAbortReboot VERSION 0.1.0)

include(CTest)
enable_testing()

# MSVC / No console / wWinMain
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /SUBSYSTEM:WINDOWS /ENTRY:wWinMainCRTStartup")

add_executable(LosslessAbortReboot WIN32
    main.cpp
    Src/Core/no_reboot.cpp
    Src/Interface/MainWindow/mainwindow.cpp
)

# Visual Studio make install
install(TARGETS LosslessAbortReboot DESTINATION ${CMAKE_INSTALL_PREFIX})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)