#include <SPI.h> // SPI-Bibiothek hinzufügen
#include <MFRC522.h> // RFID-Bibiothek hinzufügen
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

#define SS_PIN 10 // SDA an Pin 10 (bei MEGA anders)
#define RST_PIN 9 // RST an Pin 9 (bei MEGA anders)

MFRC522 mfrc522(SS_PIN, RST_PIN); // RFID-Empfänger benennen



void setup()
{
lcd.begin();
lcd.setCursor(0,0);
lcd.print("Focus Lesegeraet");
lcd.setCursor(0,1);  
lcd.print("Viel Erfolg!"); 
Serial.begin(9600); // Serielle Verbindung starten (Monitor)
SPI.begin(); // SPI-Verbindung aufbauen
mfrc522.PCD_Init(); // Initialisierung des RFID-Empfängers
}



void loop() // Hier beginnt der Loop-Teil
{
if ( ! mfrc522.PICC_IsNewCardPresent()) // Wenn eine Karte in Reichweite ist...
{
return; // gehe weiter...
}
if ( ! mfrc522.PICC_ReadCardSerial()) // Wenn ein RFID-Sender ausgewählt wurde
{
return; // gehe weiter...
}

Serial.print("Die ID des RFID-TAGS lautet:"); // "Die ID des RFID-TAGS lautet:" wird auf den Serial Monitor geschrieben.


for (byte i = 0; i < mfrc522.uid.size; i++)


{
  

lcd.clear();
lcd.setCursor(0,0);
lcd.print("Energienummer:");
Serial.print(mfrc522.uid.uidByte[i], HEX); // Dann wird die UID ausgelesen, die aus vier einzelnen Blöcken besteht und der Reihe nach an den Serial Monitor gesendet. Die Endung Hex bedeutet, dass die vier Blöcke der UID als HEX-Zahl (also auch mit Buchstaben) ausgegeben wird
Serial.print(":"); // Der Befehl „Serial.print(" ");“ sorgt dafür, dass zwischen den einzelnen ausgelesenen Blöcken ein Leerzeichen steht.

lcd.setCursor(0,1);
lcd.print(mfrc522.uid.uidByte[0], HEX);
lcd.setCursor(2,1);
lcd.print(":");
lcd.setCursor(3,1);
lcd.print(mfrc522.uid.uidByte[1], HEX);
lcd.setCursor(5,1);
lcd.print(":");
lcd.setCursor(6,1);
lcd.print(mfrc522.uid.uidByte[2], HEX);
lcd.setCursor(8,1);
lcd.print(":");
lcd.setCursor(9,1);
lcd.print(mfrc522.uid.uidByte[3], HEX);
delay(3000);
lcd.clear();
lcd.setCursor(0,0);
lcd.print("Focus Lesegeraet");
lcd.setCursor(0,1);  
lcd.print("Viel Erfolg!"); 

}

Serial.println(); // Mit dieser Zeile wird auf dem Serial Monitor nur ein Zeilenumbruch gemacht.

}


