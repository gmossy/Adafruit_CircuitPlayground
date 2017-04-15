# Library Reference Guide to the Circuit Playground
A description of parameters a developer can use for the various components
of the [Circuit Playground](https://www.adafruit.com/products/3000).
These sketches were tested and verified with:
* Circuit Playground Developer Edition
* Arduino IDE 1.8.2
* Adafruit Circuit Playground Library 1.6.4

## Guide_redLED
#13 LED - this is the one LED that you can control.  The #13 LED, however, is connected 
to one of the main microcontroller's pins and you can turn it on or off when you start 
writing code. This LED also pulses to let you know when the bootloader is active and 
ready to receive a program

You can turn the #13 LED on by calling the procedure CircuitPlayground.redLED(true) and 
turn it off with CircuitPlayground.redLED(false)

## Guide_SlideSwitch
The slide switch is near the center, right above the JST Battery Jack. There's a little 
nub you can slide left or right. This switch is connected to digital pin #21. When 
switched to the left, the value reading is 'high' (thus the + symbol) and when switched 
right, the value read is 'low' (- symbol).


You can call CircuitPlayground.slideSwitch() to tell you which way the switch is flipped.
It will return true if the switch is to the left (+ side) and false if the switch is to 
the right (- side)


## Guide_PushButtons
The position (UP or DOWN) of the two push buttons are sent to the serial
monitor once per second.
```

```

## Hello_LightSensor
The reading (0-1023) from the light sensor is sent to the serial monitor once
per second.
```

```

## Hello_Temperature
The temperature is sent to the serial monitor once per second.
```

```

## Hello_Accelerometer
The readings (in m/s<sup>2</sup>) from the 3 axes of the accelerometer are sent
to the serial monitor once per second. (1G ~= 9.8 m/s<sup>2</sup>)
```

```

## Hello_SoundSensor
The reading (0-1023) from the sound sensor (microphone) is sent to the serial
monitor once per second.
```

```

## Hello_Speaker


## Hello_NeoPixels