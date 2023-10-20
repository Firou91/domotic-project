// S'il n'y a ni présence, ni luminosité:
//    Descendre les volets
//    Eteindre la lumière
// Sinon s'il y a pas de luminosité mais qu'il y a une présence
//    Descendre les volets
//    Allumer la lumière
// Sinon s'il y a lumminosité mais pas de présence
//    Monter les volets
//    Eteindre la lumière
// Sinon s'il y a luminosité et présence
//    Monter les volets
//    Eteindre la lumière
// Sinon
//    Ne rien faire
// Fin si

#include <Wire.h>
#include <rgb_lcd.h>

#define FERMETURE_VOLET 8
#define OUVERTURE_VOLET 9

#define PRESENCE_SENSOR A2
#define BRIGHTNESS_SENSOR A0
bool presenceValue;
int brightnessValue;
float brightnessPercentage;

#define LED A3

rgb_lcd lcd;

void setup() {
  Serial.begin(9600);

  pinMode(FERMETURE_VOLET, OUTPUT);
  pinMode(OUVERTURE_VOLET, OUTPUT);

  pinMode(PRESENCE_SENSOR, INPUT);
  pinMode(BRIGHTNESS_SENSOR, INPUT);

  lcd.begin(16, 2);
  lcd.setRGB(148, 63, 222);
  lcd.clear();
  // lcd.setCursor(0, 0);
  // lcd.print("BONNE JOURNEE");
  // lcd.setCursor(0, 1);
  // lcd.print("SIR MILES AXELROD");
  
  // for (byte i = 0; i < 15; i++) {
  //   lcd.setCursor(0 - i, 0);
  //   lcd.print("BONNE JOURNEE SIR MILES AXELROD :)  ");
  //   delay(2000);
  // }
}

void loop() {
  presenceValue = digitalRead(PRESENCE_SENSOR);
  brightnessValue = analogRead(BRIGHTNESS_SENSOR);

  brightnessPercentage = (brightnessValue) / (1023.0) * 100;

  // Serial.print("--------------------------");
  // Serial.print("\n");
  // Serial.print("Présence : "); Serial.println(presenceValue);
  // Serial.print("\n");
  // Serial.print("Luminosité : "); Serial.println(brightnessPercentage); Serial.print("%");
  // Serial.print("\n");
  // Serial.print("--------------------------");
  lcd.setCursor(0, 0);
  lcd.print("PRESENCE:");
  lcd.setCursor(11, 0);
  lcd.print(presenceValue);

  lcd.setCursor(0, 1);
  lcd.print("LUMINOSITE:");
  lcd.setCursor(11, 1);
  lcd.print(brightnessPercentage);
  lcd.setCursor(15, 1);
  lcd.print("%");


  if (brightnessPercentage <= 5 & presenceValue == false) {

    digitalWrite(FERMETURE_VOLET, HIGH);
    digitalWrite(OUVERTURE_VOLET, LOW);
    digitalWrite(LED, LOW);

    Serial.print("--------------------------");
    Serial.print("\n");
    Serial.print("Le volet descend et la lumière s'éteint");
    Serial.print("\n");
    Serial.print("--------------------------");

    delay(3000);

    digitalWrite(FERMETURE_VOLET, LOW);
    digitalWrite(OUVERTURE_VOLET, LOW);

  } else if (brightnessPercentage <=5 & presenceValue == true) {

    digitalWrite(FERMETURE_VOLET, HIGH);
    digitalWrite(OUVERTURE_VOLET, LOW);
    digitalWrite(LED, HIGH);
    
    Serial.print("--------------------------");
    Serial.print("\n");
    Serial.print("Le volet se ferme et la lumière s'allume");
    Serial.print("\n");
    Serial.print("--------------------------");

    delay(3000);

    digitalWrite(FERMETURE_VOLET, LOW);
    digitalWrite(OUVERTURE_VOLET, LOW);

  } else if (brightnessPercentage >= 5 & presenceValue == true) {

    digitalWrite(FERMETURE_VOLET, LOW);
    digitalWrite(OUVERTURE_VOLET, HIGH);
    digitalWrite(LED, LOW);

    Serial.print("--------------------------");
    Serial.print("\n");
    Serial.print("Le volet s'ouvre et la lumière s'éteint");
    Serial.print("\n");
    Serial.print("--------------------------");

    delay(3000);

    digitalWrite(FERMETURE_VOLET, LOW);
    digitalWrite(OUVERTURE_VOLET, LOW);

  } else if (brightnessPercentage >= 5 & presenceValue == true) {

    digitalWrite(FERMETURE_VOLET, LOW);
    digitalWrite(OUVERTURE_VOLET, HIGH);
    digitalWrite(LED, LOW);

    Serial.print("--------------------------");
    Serial.print("\n");
    Serial.print("Le volet s'ouvre et la lumière s'éteint");
    Serial.print("\n");
    Serial.print("--------------------------");

    delay(3000);

    digitalWrite(FERMETURE_VOLET, LOW);
    digitalWrite(OUVERTURE_VOLET, LOW);

  }
  
  digitalWrite(FERMETURE_VOLET, LOW);
  digitalWrite(OUVERTURE_VOLET, LOW);

  delay(10000);
}
