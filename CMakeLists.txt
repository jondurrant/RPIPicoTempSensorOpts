cmake_minimum_required(VERSION 3.12)

# Change your executable name to something creative!
set(NAME RP2040Temp) # <-- Name your project/executable here!

include(pico_sdk_import.cmake)

# Gooey boilerplate
project(${NAME} C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# Initialize the SDK
pico_sdk_init()

set(DS3231_LIB_PATH "${CMAKE_CURRENT_LIST_DIR}/lib/RP2040DS3231RTC" CACHE PATH "Path to the SimpleDS3231 library")
include(lib/RP2040DS3231RTC/ds3231_lib_import.cmake)

include(ahtxx_import.cmake)
include(lib/RP2040PIO-DS18B20/DS18B20pio.cmake)

add_subdirectory(src)
add_subdirectory(test EXCLUDE_FROM_ALL)

#Set up files for the release packages
install(CODE "execute_process(COMMAND $ENV{HOME}/bin/picoDeploy.sh ${CMAKE_CURRENT_BINARY_DIR}/src/${NAME}.elf)")

# Set up files for the release packages
install(FILES
    ${CMAKE_CURRENT_BINARY_DIR}/src/${NAME}.uf2
    DESTINATION ${CMAKE_CURRENT_BINARY_DIR}
)

set(CPACK_INCLUDE_TOPLEVEL_DIRECTORY OFF)
set(CPACK_GENERATOR "ZIP" "TGZ")
include(CPack)
