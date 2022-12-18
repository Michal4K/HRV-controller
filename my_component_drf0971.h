#include "esphome.h"
#include "DFRobot_GP8403.h"
#include <Wire.h>
using namespace esphome;

DFRobot_GP8403 dac(&Wire,0x5F);

class CustomDFRobot2ChDAC0_10V : public Component, public FloatOutput {
 public:
  int channel;
  bool store_enabled;

  void setup() override {
    // This will be called by App.setup()
    while(dac.begin()!=0){
      ESP_LOGD("CustomDFRobot2ChDAC0_10V", "ERROR I2C connection.");
      delay(1000);
    }
    dac.setDACOutRange(dac.eOutputRange10V);
  }

  void set_channel(int ch) {
    if (ch == 0 || ch == 1 || ch == 2){
      channel = ch;
      ESP_LOGD("CustomDFRobot2ChDAC0_10V", "Channel set.");
    }
    else ESP_LOGD("CustomDFRobot2ChDAC0_10V", "ERROR setup channel. Must be 0 for 0 or 1 for 1 or 2 for both channel.");
  }

  
  void enable_store(bool e) {
    store_enabled = e;
    ESP_LOGD("CustomDFRobot2ChDAC0_10V", "Storing last set value in DAC: %d", e);
  }

  void set_out_range(int v) {
    if(v == 10) dac.setDACOutRange(dac.eOutputRange10V);
    else if(v == 5) dac.setDACOutRange(dac.eOutputRange5V);
    else ESP_LOGD("CustomDFRobot2ChDAC0_10V", "ERROR setup output range. Must be 5 for 0 - 5V or 10 for 0 - 10V.");
  }
  void write_state(float state) override {
    // state is the amount this output should be on, from 0.0 to 1.0
    // we need to convert it to an integer first
    int value = state * 10000;
    dac.setDACOutVoltage(value,channel);
    if(store_enabled) dac.store();
    ESP_LOGD("CustomDFRobot2ChDAC0_10V", "Set output voltage: %f on channel: %d", float(value)/1000, channel);
  }
};
