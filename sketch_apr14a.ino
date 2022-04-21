#include <SPI.h>
#include <MFRC522.h>
const int pinRST = 9; // pin RST du module RC522
const int pinSDA = 10; // pin SDA du module RC522
MFRC522 rfid(pinSDA, pinRST);
char data;
void setup()
{
SPI.begin();
rfid.PCD_Init();
Serial.begin(9600);
Serial.println("0");
}
void loop()
{


if (rfid.PICC_IsNewCardPresent()) // on a dédecté un tag
{
if (rfid.PICC_ReadCardSerial()) // on a lu avec succès son contenu
 {

   
  

Serial.println("1");

delay (2000);
 }
 


}

}

