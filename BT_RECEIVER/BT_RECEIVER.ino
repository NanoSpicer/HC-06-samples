
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
  // Mentre hi hagi bytes per llegir, els llegim
  if(Serial.available() > 0){
    while(Serial.available() > 0){
      Serial.print((char) Serial.read());
    }
    Serial.println(); Serial.println();
  }

  delay(2000);
  
}
