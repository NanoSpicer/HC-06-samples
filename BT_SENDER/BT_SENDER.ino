
/**************************************************
 * 
 * EXEMPLE AMB EL BUILT-IN Serial.
 * 
 * CONFIGURACIÓ:
 * 
 *          ARDUINO NANO - HC-06
 *    GROC       TX         RX
 *    VERD       RX         TX
 *    RED        3V3        VCC
 *    NEGRE      GND        GND
 * 
 **************************************************/
void setup() {
  // Inicialitzam el Built-In Serial.
  Serial.begin(9600);
}
void loop() {
  // Enviam el missatge desitjat
  Serial.println("MISSATGE PER UN LINUX!!!");

  delay(2000);
  
}
