# v3.21 implemented semantic changes regarding $<TARGET_OBJECTS:...>
# See https://cmake.org/cmake/help/v3.21/command/target_link_libraries.html#linking-object-libraries-via-target-objects
cmake_minimum_required(VERSION 3.21)

add_library(variant INTERFACE)
add_library(variant_usage INTERFACE)

target_include_directories(variant_usage INTERFACE
  .
)


target_link_libraries(variant_usage INTERFACE
  base_config
)

target_link_libraries(variant INTERFACE variant_usage)



add_library(variant_bin STATIC EXCLUDE_FROM_ALL
  generic_clock.c
  PeripheralPins.c
  PeripheralPins_ELV_BM_TRX1.c
  PeripheralPins_LORA_E5_MINI.c
  variant_ELV_BM_TRX1.cpp
  variant_generic.cpp
  variant_LORA_E5_MINI.cpp
  variant_NUCLEO_WL55JC1.cpp
)
target_link_libraries(variant_bin PUBLIC variant_usage)

target_link_libraries(variant INTERFACE
  variant_bin
)

