const int BUTTON_PIN = D1;  // GPIO5
const int LED_BUILTIN_D1 = D4;  // Ugrađeni LED na D1 Mini
const int BROJ_KLIKOVA = 3;

void setup() {
  Serial.begin(115200);
  pinMode(BUTTON_PIN, OUTPUT);
  pinMode(LED_BUILTIN_D1, OUTPUT);
  digitalWrite(BUTTON_PIN, LOW);
  digitalWrite(LED_BUILTIN_D1, HIGH);  // LED je invertovan - HIGH = ugašen

  Serial.println("\n\n=== Button Clicker pokrenut ===");
  Serial.println("Cekam 1 sekundu...");
  delay(1000);

  Serial.print("Simuliram ");
  Serial.print(BROJ_KLIKOVA);
  Serial.println(" klika:");

  // Simuliraj klikove
  for (int i = 0; i < BROJ_KLIKOVA; i++) {
    Serial.print("  Klik ");
    Serial.print(i + 1);
    Serial.println(" - HIGH");

    digitalWrite(BUTTON_PIN, HIGH);
    digitalWrite(LED_BUILTIN_D1, LOW);  // LED upaljen
    delay(600);

    Serial.println("         - LOW");
    digitalWrite(BUTTON_PIN, LOW);
    digitalWrite(LED_BUILTIN_D1, HIGH);  // LED ugašen
    delay(1600);
  }

  Serial.println("=== Gotovo! ===");
}

void loop() {
  // Gotovo - ništa više ne radimo
}
