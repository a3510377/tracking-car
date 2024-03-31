#include "HC595.h"

template <uint8_t size>
HC595<size>::HC595(const uint8_t dataPin, const uint8_t clockPin,
                   const uint8_t latchPin)
    : _dataPin(dataPin), _clockPin(clockPin), _latchPin(latchPin) {
  init();
}

template <uint8_t size>
void HC595<size>::init() {
  pinMode(_dataPin, OUTPUT);
  pinMode(_clockPin, OUTPUT);
  pinMode(_latchPin, OUTPUT);

  digitalWrite(_latchPin, LOW);
  digitalWrite(_dataPin, LOW);
  digitalWrite(_clockPin, LOW);
}

template <uint8_t size>
void HC595<size>::update() {
  digitalWrite(_latchPin, LOW);

  for (uint8_t i = size; i > 0; i--) {
    uint8_t temp = _data[i - 1];
    Serial.println("----------");
    Serial.println(temp, 2);
    for (uint8_t j = 0; j < 8; j++) {
      Serial.print(!!(temp & (1 << (7 - j))));
      Serial.print(" ");
      digitalWrite(_dataPin, !!(temp & (1 << (7 - j))));
      digitalWrite(_clockPin, HIGH);
      digitalWrite(_clockPin, LOW);
    }
    Serial.println();
  }

  digitalWrite(_latchPin, HIGH);
  digitalWrite(_latchPin, LOW);
}

template <uint8_t size>
HC595_PIN<size>& HC595<size>::operator[](const uint pin) {
  return HC595_PIN<size>(this, _data[pin]);
}

template <uint8_t size>
uint8_t* HC595<size>::get(void) {
  return _data;
}

template <uint8_t size>
uint8_t HC595<size>::get(uint8_t pin) {
  return (_data[pin / 8] >> (pin % 8)) & 1;
}

template <uint8_t size>
void HC595<size>::setAs(const uint8_t* data, bool update) {
  memcpy(_data, data, size);
  if (update) {
    this->update();
  }
}

template <uint8_t size>
void HC595<size>::set(uint8_t pin, uint8_t value, bool update) {
  uint8_t bitMask = 1 << (pin % 8);
  uint8_t byteIndex = pin / 8;

  if (value) _data[byteIndex] |= bitMask;
  else _data[byteIndex] &= ~bitMask;

  if (update) {
    this->update();
  }
}

template <uint8_t size>
void HC595<size>::setAllValue(uint8_t value, bool update) {
  for (uint8_t i = 0; i < size; i++) {
    _data[i] = value;
  }

  if (update) {
    this->update();
  }
}

template <uint8_t size>
void HC595<size>::move(uint8_t step, bool update) {}

template <uint8_t size>
inline HC595_PIN<size>::HC595_PIN(HC595<size>& other, uint8_t pin)
    : _hc595(other), _pin(pin) {}

template <uint8_t size>
HC595_PIN<size>& HC595_PIN<size>::operator=(const uint8_t status) {
  _hc595.set(_pin, status);

  return *this;
}
