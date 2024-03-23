#include "analogWrite.h"

int8_t _analog_write_channels[16] = {-1, -1, -1, -1, -1, -1, -1, -1,
                                     -1, -1, -1, -1, -1, -1, -1, -1};

int8_t analogWriteChannel(uint8_t pin) {
  int8_t channel = -1;

  for (uint8_t i = 0; i < 16; i++) {
    if (_analog_write_channels[i] == pin) {
      channel = i;
      break;
    }
  }

  if (channel == -1) {
    for (uint8_t i = 0; i < 16; i++) {
      if (_analog_write_channels[i] == -1) {
        _analog_write_channels[i] = pin;
        channel = i;
        ledcSetup(channel, 5000, 8);
        ledcAttachPin(pin, channel);
        break;
      }
    }
  }

  return channel;
}

void analogWrite(uint8_t pin, uint8_t speed) {
  int8_t channel = analogWriteChannel(pin);
  if (channel != -1) {
    ledcWrite(channel, speed);
  }
}
