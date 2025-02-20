cmake_minimum_required(VERSION 3.10)

project(Gielda)
set(CMAKE_CXX_STANDARD 17)

find_package(SFML 2.5 REQUIRED COMPONENTS graphics window system)

if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    link_directories(${SFML_LIBRARY_DIR})

    add_executable(GieldaApp
        Gielda/Main.cpp
        Gielda/Display.cpp
        Gielda/Display.h
        Gielda/Exchange.cpp
        Gielda/Exchange.h
        Gielda/Figure.cpp
        Gielda/Figure.h
        Gielda/Offer.cpp
        Gielda/Offer.h
        Gielda/Point.cpp
        Gielda/Point.h
        Gielda/Rectangle.cpp
        Gielda/Rectangle.h
        Gielda/User.cpp
        Gielda/User.h
    )

    target_link_libraries(GieldaApp
        sfml-graphics
        sfml-window
        sfml-system
    )
else()
    message(FATAL_ERROR "SFML library not found. Please make sure SFML is installed and CMake can find it.\n"
                        "You may need to set the SFML_DIR variable to the directory containing SFMLConfig.cmake file.\n"
                        "Example command for CMake generation:\n"
                        "cmake .. -G \"MinGW Makefiles\" -DSFML_DIR=\"C:/ścieżka/do/SFML/lib/cmake/SFML\"")
endif()