create_driver i2c_driver
set_sw_property hw_class_name i2c
set_sw_property version 1
set_sw_property min_compatible_hw_version 1.0
add_sw_property bsp_subdirectory drivers
add_sw_property c_source HAL/src/i2c.c
add_sw_property include_source HAL/inc/i2c.h
add_sw_property supported_bsp_type HAL