# HRV-controller
This is HRV smart controller for Home Assistant build using [ESPHome](https://esphome.io/). It use [Wemos D1 Mini](http://ihormelnyk.com/opentherm_adapter) and [DRF0971 i2c DAC](https://wiki.dfrobot.com/SKU_DFR0971_2_Channel_I2C_0_10V_DAC_Modul).

It was created as shool project at FIT VUT.

## Installation
- Install ESPHome
- Copy my_component_drf0971.h and HRV-controller.yaml to esphome data direcotry
- Edit HRV-controller.yaml to setup connection with Home Assistant
- Connect boards by schematic HRV_controller.pdf
- Flash the ESP and configure in Home Assistant. It should be auto-discovered by the ESPHome Integration.
- Add entites to your Home Assistant dashboard.
