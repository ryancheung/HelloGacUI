set(GACUI_HDRS
    Vlpp.h
    VlppOS.h
    VlppRegex.h
    VlppReflection.h
)

set(GACUI_SRCS
    Vlpp.cpp
    VlppOS.cpp
    VlppRegex.cpp
    VlppReflection.cpp
)

if (WIN32)
    list(APPEND GACUI_SRCS Vlpp.Windows.cpp VlppOS.Windows.cpp)
else()
    list(APPEND GACUI_SRCS Vlpp.Linux.cpp VlppOS.Linux.cpp)
endif()

list(APPEND GACUI_HDRS VlppWorkflowLibrary.h)
list(APPEND GACUI_SRCS VlppWorkflowLibrary.cpp)


list(APPEND GACUI_HDRS GacUI.h Skins/DarkSkin/DarkSkin.h)
if (WIN32)
    list(APPEND GACUI_HDRS GacUI.Windows.h)
endif()

list(APPEND GACUI_SRCS GacUI.cpp Skins/DarkSkin/DarkSkin.cpp)
if (WIN32)
    list(APPEND GACUI_SRCS GacUI.Windows.cpp)
endif()

list(APPEND GACUI_HDRS VlppParser.h)
list(APPEND GACUI_SRCS VlppParser.cpp)

list(APPEND GACUI_HDRS VlppGlrParser.h)
list(APPEND GACUI_SRCS VlppGlrParser.cpp)

add_library(gacui STATIC ${GACUI_HDRS} ${GACUI_SRCS})
target_include_directories(gacui PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

if(MSVC)
    target_compile_options(gacui PRIVATE /bigobj)
endif()
