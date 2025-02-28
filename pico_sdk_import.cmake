
set(PICO_SDK_PATH $ENV{PICO_SDK_PATH})

if (NOT EXISTS ${PICO_SDK_PATH})
	message(FATAL_ERROR "PICO-SDK not Exported")
endif ()

set(PICO_SDK_INIT_CMAKE_FILE ${PICO_SDK_PATH}/pico_sdk_init.cmake)

include(${PICO_SDK_INIT_CMAKE_FILE})
