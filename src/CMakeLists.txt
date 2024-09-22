cmake_minimum_required(VERSION 3.13)

add_executable(5vpwm)

target_sources(5vpwm PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/main.c
)

# In addition to pico_stdlib required for common PicoSDK functionality
target_link_libraries(5vpwm PUBLIC
	pico_stdlib
	hardware_pwm
)

pico_add_extra_outputs(5vpwm)
