#include <Joystick.h>

// konfiguracja Joysticka wyświetlana w Urządzeniach i drukarkach
Joystick_ Joystick(JOYSTICK_DEFAULT_REPORT_ID,JOYSTICK_TYPE_GAMEPAD,
  4, 0,                   // Button Count / Hat Switch Count
  true, true, true,       // X / Y / Z Axis
  false, false, false,    // Rx / Ry / Rz
  true, true,             // rudder / throttle
  false, false, false);   // accelerator / brake / steering

void setup() {
  // Initialize Button Pins
  pinMode(5, INPUT_PULLUP); 
  pinMode(7, INPUT_PULLUP);
  pinMode(10, INPUT_PULLUP);
  pinMode(14, INPUT_PULLUP);

  // Initialize Joystick Library
  Joystick.begin();
  // inicjalizacja zakresów osi analogowych
  Joystick.setXAxisRange(0,1023);
  Joystick.setYAxisRange(0,1023);                                                                                                                                                                                                                                         
  Joystick.setZAxisRange(0,1023);
  Joystick.setRudderRange(0,1023);
  Joystick.setThrottleRange(0,1023);
}

// Constant that maps the phyical pin to the joystick button.
const int pinToButtonMap = 7;

// Last state of the button
int lastButtonState[4] = {0,0,0,0};

void loop() {
  Joystick.setXAxis(analogRead(A2));
  Joystick.setYAxis(analogRead(A1));
  Joystick.setZAxis(analogRead(A0));
  Joystick.setRudder(analogRead(A3));
  Joystick.setThrottle(analogRead(A6));

  // Read pin values
  for (int index = 0; index < 4; index++)
  {
    int currentButtonState = !digitalRead(index + pinToButtonMap);
    if (currentButtonState != lastButtonState[index])
    {
      Joystick.setButton(index, currentButtonState);
      lastButtonState[index] = currentButtonState;
    }
  }

  delay(50);
}