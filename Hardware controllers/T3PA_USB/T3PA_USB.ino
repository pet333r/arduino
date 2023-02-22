#include <Joystick.h>

// konfiguracja Joysticka wyświetlana w Urządzeniach i drukarkach
Joystick_ Joystick(JOYSTICK_DEFAULT_REPORT_ID,JOYSTICK_TYPE_JOYSTICK,
  0, 0,                   // Button Count / Hat Switch Count
  false, false, false,    // X / Y / Z Axis
  true, true, true,       // Rx / Ry / Rz
  false, false,           // rudder / throttle
  false, false, false);   // accelerator / brake / steering

int x_Axis = 0;
int y_Axis = 0;
int z_Axis = 0;

const bool initAutoSendState = true;

void setup() {
  Joystick.begin();
  // ustawienie zakresów odbioru danych z poszczególnych pedałów
  // zakres można sprawdzić w IDE > Serial Monitor
  Joystick.setRzAxisRange(240, 920);
  Joystick.setRyAxisRange(160, 880);
  Joystick.setRxAxisRange(150, 810);
}

void loop() {
  // Z
  z_Axis = analogRead(A2);
  Joystick.setRzAxis(z_Axis);
  Serial.print("Z: ");
  Serial.println(z_Axis);

  // Y
  y_Axis = analogRead(A0);
  Joystick.setRyAxis((y_Axis));
  Serial.print("Y: ");
  Serial.println(y_Axis);

  // X
  x_Axis = analogRead(A1);
  Joystick.setRxAxis(x_Axis);
  Serial.print("X: ");
  Serial.println(x_Axis);

  // opóźnienie: 20/1000 > 50 fps
  delay(20);
}