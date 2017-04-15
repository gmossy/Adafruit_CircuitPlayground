# Library Reference Guide to the Circuit Playground
A description of parameters a developer can use for the various components
of the [Circuit Playground](https://www.adafruit.com/products/3000).
These sketches were tested and verified with:
* Circuit Playground Developer Edition
* Arduino IDE 1.8.2
* Adafruit Circuit Playground Library 1.6.4

## redLED
    13 LED - this is the one LED that you can control. The #13 LED, however,is connected 
	to one of the main microcontroller's pins and you can turn it on or off when you
	start writing code. This LED also pulses to let you know when the bootloader is
	active and ready to receive a program
 
      Library Reference
	You can turn the #13 LED on by calling the procedure CircuitPlayground.redLED(true)
	and turn it off with CircuitPlayground.redLED(false) or HIGH or LOW
	example:
	  	CircuitPlayground.redLED(true);
  		delay(500);
  		CircuitPlayground.redLED(false);
  		delay(500);
	
## SlideSwitch
	The slide switch is near the center, right above the JST Battery Jack. There's a
	little nub you can slide left or right. This switch is connected to digital pin
	#21. When switched to the left, the value reading is 'high' (thus the + symbol) and
	when switched right, the value read is 'low' (- symbol).
	
      Library Reference
	You can call CircuitPlayground.slideSwitch() to tell you which
	way the switch is flipped. It will return true if the switch is to the left (+
	side) and false if the switch is to the right (- side)
	example:
	  slideSwitch = CircuitPlayground.slideSwitch();
	  

## PushButtons
	There are two momentary pushbuttons, you can use these in any of your projects to
	change modes, indicate when to start or stop a sketch, modify behavior, really
	anything! The Left button is connected to digital pin #4 The Right button is
	connected to digital pin #19 Both have 10KΩ pull-down resistors. That means that
	when the button is pressed the value read off those pins will be 'high'.
    
    Library Reference
	You can ask if the buttons are pressed by calling CircuitPlayground.leftButton() or
	CircuitPlayground.rightButton(). They will return true if and only if the button in
	question is being pressed right when the function is called.
	example:
	  leftButtonPressed = CircuitPlayground.leftButton();
      rightButtonPressed = CircuitPlayground.rightButton();
  
## LightSensor
	There is an analog light sensor, part number ALS-PT19, in the top left part of the
	board. This can be used to detect ambient light, with similar spectral response to
	the human eye. There is a 10K balancing resistor to convert the current drive to
	voltage. This sensor is connect to analog pin #A5, you can use analogRead or the
	library to read the analog value. It will read between 0 and 1023 with higher
	values corresponding to brighter light levels. The range is approximately 0 Lux to
	1500 Lux maximum. 1000 Lux will roughly read as 2 Volts (or about 680 as a raw
	analog reading). A reading of about 300 is common for most indoor light levels.
	Note that outdoor daylight is 10,000 Lux or even higher, so this sensor is best
	suited for indoor light levels!
	DataSheet:  https://cdn-shop.adafruit.com/product-files/2748/2748+datasheet.pdf

     Library Reference
	 You can request the raw analog reading (0 = no light, up to 1023
	= ~1500 Lux) with CircuitPlayground.lightSensor()
	example:
	value = CircuitPlayground.lightSensor();

## Temperature
	You can sense the temperature using the onboard thermistor. A thermistor is a
	resistor that changes it's resistance based on the temperature. They are a little
	more complex to use than temperature sensors that spit out Celsius, but they're
	also much less expensive. We use the NTC thermistor (Murata NCP15XH103F03RC) for
	temperature sensing. While it isn't an all-in-one temperature sensor, with linear
	output, it's easy to calculate the temperature based on the analog voltage on
	analog pin #A0. There's a 10K 1% resistor connected to it as a pull down. You can
	read the analog value and calculate the temperature with the beta-constant, or just
	use the Circuit Playground library.  
	Refer to https://learn.adafruit.com/thermistor/

    Library Reference
	You can retreive the current calculated temperature with
	CircuitPlayground.temperature() which will return you a floating point number in
	Centigrade. If you need Fahrenheit use CircuitPlayground.temperatureF()
	example:
	  float tempC, tempF;
	
	  tempC = CircuitPlayground.temperature();
      tempF = CircuitPlayground.temperatureF();


## Accelerometer
	There is a powerful MEMS accelerometer in the very center of your Circuit
	Playground. This part is the LIS3DH, a 3-axis (X, Y and Z) sensing accelerometer.
	Accelerometers are the sensors in your WiiMote, phone, and other electronic devices
	that can sense tilt, gravity, motion and 'tap' effects. These sensors used to cost
	$20 each but now are so common we can include them for beginners! The sensor can
	sense ±2g, 4g, 8g (g = 9.8 meters/s2). Of course, at all times on earth you will
	sense 1 g of gravity! The LIS3DH is connected to the hardware SPI pins (to leave
	the I2C pins free) and has the chip select (CS) pin on digital pin #8 and an
	optional interrupt output on digital pin #7 (also known as IRQ #4)

     Library Reference
	 Motion in X Y and Z

	You can ask the sensor for the amount of g detected in X, Y and Z directions.
	Positive values mean acceleration in the direction of the arrow on the silkscreen.
	For X that means towards the USB jack. For Y that is to the left. For Z that is
	straight up pointing towards you when looking at the circuit board.
	
	CircuitPlayground.motionX(), CircuitPlayground.motionY(),
	CircuitPlayground.motionZ() will each return a floating point value. 
	
	Setting Accelerometer Range
	example:
	  float X, Y, Z;
	  X = CircuitPlayground.motionX();
      Y = CircuitPlayground.motionY();
  	  Z = CircuitPlayground.motionZ();

	You can change the range, a smaller range (±2g) will give more precision. Larger
	ranges (±8g) can sense greater forces. You can set it whenever you like using
	CircuitPlayground.setAccelRange(range) where range can be LIS3DH_RANGE_2_G,
	LIS3DH_RANGE_4_G or LIS3DH_RANGE_8_G 
	
	Tap Detection
	example:
		void setup(){
		CircuitPlayground.setAccelRange(LIS3DH_RANGE_4_G);
		}

	You can turn on tap detection by calling CircuitPlayground.setAccelTap(taps,
	threshhold)
	
	Tap detection can detect single taps or 'double taps' (like a
	double-click). If taps is 1 you will only detect single taps, one at a time. If
	taps is 2, you will be able to detect both single taps and double taps. 
	
	You can detect taps in real time by calling CircuitPlayground.getAccelTap(). It will 
	return 0 if no tap is detected, 1 if a single tap is detected, and 2 or 3 if double
	tap is detected. 
	
	The problem with that is you need to query it within about 100
	milliseconds of the tapping, which can be difficult to do. If you are comfortable
	with interrupts you can use the interrupt output to have a function called when a
	tap is detected: attachInterrupt(digitalPinToInterrupt(7), myfunction, RISING) will
	call myfunction whenever the tap or doubletap occurs.
	Here is a reference on how to use arduino interupts;
	https://www.arduino.cc/en/Reference/AttachInterrupt

## SoundSensor
	A thin MEMS microphone can be used to detect audio levels and even perform basic
	FFT functions. You can read the analog voltage corresponding to the audio on analog
	pin #A4. Note that this is the raw analog audio waveform! When it's silent there
	will be a reading of ~330 and when loud the audio will read between 0 and 800 or
	so. Averaging and smoothing must be done to convert this to sound-pressure-level.
	The microphone is sensitive to 100 Hz - 10,000 Hz audio frequencies. See the
	datasheet for more details.

	Library Reference
	You can read the raw analog value from the amplified microphone with
	CircuitPlayground.soundSensor() this will give you just a value from between 0 and
	1023 where the default 'quiet' voltage is ~330. At this time there is no function
	for automatic sound pressure level or frequency binning.
	example:
	  value = CircuitPlayground.soundSensor();


## Speaker
	You can make your circuit playground sing with the built in buzzer. This is a
	miniature magnetic speaker connected to digital pin #5 with a transistor driver. It
	is quite small but can beep with conviction! It's not good for playing detailed
	audio, more for beeping and buzzing and simple bleepy tunes. The driver circuitry
	is an on/off transistor driver, so you will only be able to play square waves. It
	is also not the same loudness over all frequencies but is designed to be the
	loudest at around 4 KHz.
	
	Library Reference
	You can play basic square wave beeps/tones with
	CircuitPlayground.playTone(frequency, duration_ms). Where frequency is the
	frequency in Hertz and duration is the time to play the beep for, in millisecods.
	That means CircuitPlayground.playTone(440, 500) will play 440 Hz (middle A) for 500
	milliseconds (half of a second). The call will take the amount of time that it
	takes to play the tone, so if you have a duration of, say, 5000 milliseconds your
	Circuit Playground will spend 5 seconds playing a tone and won't be doing anything
	else.

	example:
	 	void loop() {
 	 	CircuitPlayground.playTone(440, 500);
		}

## NeoPixels
	One of the fanciest accessories on Circuit Playground are ten (10!) full color LEDs
	called NeoPixels. Each of these ten Pixels contain bright red+green+blue sub-LEDs
	and can display any of 16,777,216 different colors! These pixels are controlled by
	a single data pin, #17. Unlike non-smart RGB LEDs, you can set the color and a
	little chip inside the LED will handle the PWM for you. Since they are controlled
	in a chain, you will need to tell the Circuit Playground's NeoPixel code which one
	you want to set the color for. Each NeoPixel is numbered, starting with #0 at the
	top left and going counter clockwise till you reach #9

      Library Reference
	setPixelColor

	You can set the color for each pixel with the built in NeoPixel library:
	
	CircuitPlayground.setPixelColor(n, red, green, blue)
	
	Where n is between 0 and 9 and
	indicates which LED you are setting. red/green/blue vary between 0 (off) and 255
	(full on) 
	  CircuitPlayground.setPixelColor(0, 255,   0,   0);
	  or
	  CircuitPlayground.setPixelColor(0, 0xFF0000);
	
	clearPixels

	You can quickly turn all the LEDs off with CircuitPlayground.clearPixels()
	
	setBrightness
	example
		void setup() {
  		CircuitPlayground.begin();
 		CircuitPlayground.setBrightness(255);
		}

	By default the global brightness of the LEDs is set to 30 out of 255. This means
	that the LEDs won't be insanely bright when you first use them. You can change the
	global brightness at the beginning of the sketch (in setup) by running
	CircuitPlayground.setBrightness(b) where b varies from 0 (no LEDs will ever light)
	to 255 (incredibly bright!) setBrightness only affects pixel colors set after it is
	called. That is, if you set an LED color and then call setBrightness, it wont
	affect that older LED color. Only going forward will the brightness change to be
	different.
	example
		void setup() {
		CircuitPlayground.setBrightness(100)
		}
	
## Capacitive Touch
	All 8 non-power pads (e.g. not the GND/3.3V/VBATT) around the Circuit Playground
	have the ability to act as capacitive touch pads. Each pad has a 1 MΩ resistor
	between it and digital pin #30. You can toggle this pin in your sketch to control
	whether the resistor is a pullup or pulldown or floating. Note that this means that
	all the pads have a 2 MΩ resistance between them, not important for 99% of uses but
	may be confusing for some cases where you are trying to detect very high resistance
	values

Library Reference

	You can get the capacitance reading from a pin using CircuitPlayground.readCap(pin)
	and just set the pin to any of the pad #'s next to the pad (e.g. 0, 1, 2, 3, 6, 9,
	10 and 12) The number returned will vary from about 0 to about 1000. Any reading
	above approximately 50 will correspond to a touch, but it does depend a bit on what
	material and length is connected to the pin so you will need to adjust your code
	based on your setup.
	
	
## Firmata
	Firmata is a protocol for communicating with microcontrollers from software on a
	host computer. The protocol can be implemented in firmware on any microcontroller
	architecture as well as software on any host computer software package. The Arduino
	repository described here is a Firmata library for Arduino and Arduino-compatible
	devices.

   https://github.com/firmata/arduino#firmata-client-libraries

## Hardware Pins
	Starting from the Micro USB jack and going counter-clockwise here are what the pins do.
	GND - Same as the other Ground pins
	
	SCL #3 - This is a special-purpose pin. It is connected to the
		microcontroller's pin #3. This pin can also act as a PWM output and an
		interrupt input (INT0). The other special usage is connecting to I2C sensors
		and devices, as the I2C Clock pin

	SDA #2 - This is a special-purpose pin. It is connected to the microcontroller's
		pin #2. This pin can also act as a PWM output and an interrupt input (INT1). The
		other special usage is connecting to I2C sensors and devices, as the I2C Data pin
	
	3.3V - Same as the other 3.3V power supply pins
	
	RX #0 - This is a special-purpose pin. It is connected to the microcontroller's pin
		#0. This pin can also act as an interrupt input (INT2). The other special usage is
		connecting to UART/Serial sensors and devices, as the Data Receive (RX) pin.

	TX #1 - This is a special-purpose pin. It is connected to the microcontroller's pin
		#1. This pin can also act as an interrupt input (INT3). The other special usage is
		connecting to UART/Serial sensors and devices, as the Data Transmit (TX) pin.

	GND - Same as the other Ground pins

##  Further References
    Adafruit
    https://learn.adafruit.com/circuit-playground-lesson-number-0/install-software-linux?view=all#basic-leds
    

