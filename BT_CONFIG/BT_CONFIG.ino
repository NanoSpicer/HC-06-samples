#include <SoftwareSerial.h>

#define bauds 9600
// Pins RX i TX
#define RX 11
#define TX 10

/*************************
 * 
 * CONFIGURACIÓ DEL MODUL A TRAVÉS DE TECLAT.
 * 
 *            
 *              !!!!ALERTA!!!! 
 * 
 * 
 * · LES COMANDES AT ***SENSE*** COA. (NI \n\r ni \n)
 * · Amb la llibreria Software Serial només es pot comunicar
 *   amb el mòdul a 9600 bauds!
 * · A través del Serial no és capaç de funcionar a més de 115200 bauds
 *    **NO POSAR LA VELOCITAT DEL MÒDUL MÉS ALTA QUE L'INDICAT**
 * 
 * 
 */
 
// Modul bluetooth que sera conectat a dos pins mitjançant la llibreria SoftwareSerial
// RX TX Especificació de la llibreria SoftwareSerial
SoftwareSerial modul(RX, TX); 

//Comanda que enviarem al mòdul bluetooth
String comanda = "";

void setup() {
  Serial.begin(bauds);
  modul.begin(bauds);
  // Ens asseguram de que els Serial estiguin llestos
  delay(1000);
  Serial.println("LLESTOS");
}

/** 
 *  L'HC-06 admet comanes AT a una velocitat de comanda/s. 
 *  Si s'en envien més, es perdran.
 */
void loop() {
  
  int aux;
  //Si hem escrit alguna cosa per el monitor serie es llegirà aqui
  if(Serial.available() > 0){
    comanda = "";
    while(Serial.available() > 0){
      aux = Serial.read();
      if(((char)aux!='\n')){
        comanda = comanda + ((char) aux);
      }
    }
    Serial.println(comanda);
    
    //Feim la comanda al mòdul
    modul.print(comanda);
    delay(1000);
  }

  //Si hi ha resposta la llegim i la mostram.
  if(modul.available() > 0 ){

    while(modul.available() > 0){
      aux = modul.read();
      Serial.print(((char)aux));
    }
    Serial.println("");
    delay(1000);
  }
  delay(1000);

}
