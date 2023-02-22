#include <Joystick.h>

// konfiguracja Joysticka wyświetlana w Urządzeniach i drukarkach
Joystick_ Joystick(JOYSTICK_DEFAULT_REPORT_ID,JOYSTICK_TYPE_GAMEPAD,
  0, 0,                   // Button Count / Hat Switch Count
  false, false, false,       // X / Y / Z Axis
  false, false, false,    // Rx / Ry / Rz
  true, false,             // rudder / throttle
  false, false, false);   // accelerator / brake / steering

int value_rudder = 0;

void setup() {
	// Initialize Joystick Library
	Joystick.begin();
	Joystick.setRudderRange(320, 670);
}

void loop() {
	value_rudder = analogRead(A0);
	Joystick.setRudder(value_rudder);

	Serial.println(value_rudder);

	delay(20);
}
