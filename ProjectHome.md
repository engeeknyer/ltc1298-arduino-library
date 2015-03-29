# LTC1298 ARDUINO LIBRARY #

## In short ##
The aim of this project is provide a set of tools for control the **LTC1298** _ADC converter_. This IC is a 12 bit an let the user a simple use. Any other component is need to run your projects with this IC attached to your Arduino.

## Using the library ##
This library includes the use of Arduino as SPI Master device. There are tw functions in the library:

  * **ltc1298****Init()**; Setup the SPI Bus. Must be run only once.
  ***ltc1298Read()**: Reads data from the 12bit ADC.
