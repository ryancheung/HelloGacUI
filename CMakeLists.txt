cmake_minimum_required(VERSION 3.0.0)
project(HelloGacUI VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 20)

add_definitions(-DUNICODE)
add_definitions(-D_UNICODE)
add_definitions(-DVCZH_DEBUG_NO_REFLECTION)

add_subdirectory(Lib/GacUI)

add_executable(${PROJECT_NAME}
    Main.cpp
    WinMain.cpp
    UI/Source/HelloGacUIPartialClasses.cpp
)
target_include_directories(${PROJECT_NAME} PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/Lib/GacUI
    ${CMAKE_CURRENT_SOURCE_DIR}/UI/Source
)
target_link_libraries(${PROJECT_NAME} gacui)
set_target_properties(${PROJECT_NAME} PROPERTIES
    LINK_FLAGS /SUBSYSTEM:WINDOWS
)
set_property(TARGET ${PROJECT_NAME} PROPERTY
  MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
