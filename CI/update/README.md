# stm32variant

By default, generates:
 - *PeripheralPins.c*
 - *PinNamesVar.h*
 - *variant_generic.cpp*
 - *variant_generic.h*
 - *boards_entry.txt*
 - *generic_clock.c*

for all xml files description available in [STM32CubeMX](http://www.st.com/en/development-tools/stm32cubemx.html) database.
By default, the database used is the one from GitHub:
        https://github.com/STMicroelectronics/STM32_open_pin_data
The internal database from STM32CubeMX directory can also be used.
The path have to be defined in `update_config.json`.

After file generation, review them carefully and please report any issue
[here](https://github.com/stm32duino/Arduino_Core_STM32/issues).
