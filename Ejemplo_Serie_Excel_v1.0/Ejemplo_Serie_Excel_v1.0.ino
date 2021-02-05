
//Saúl Íñiguez -- OpenEngineering
//Prog: Ejemplo_Serie_Excel   Versión: 1.0   Fecha: 04/02/2021

int ledPin = 13;   //Led integrado en placa

void setup() {
  Serial.begin(115200);
}

void loop() {
  pinMode(ledPin, OUTPUT);
  serialHandler();
}

void serialHandler() {
  while (Serial.available() <= 0) {}
  String data = Serial.readStringUntil('\n');
  if (data == "A") {  //Se envían los datos cuando se recibe una C
    Serial.println("He recibido una A");
  } else if (data == "B") {
    Serial.println("He recibido una B");
  } else if (data == "ON") {
    digitalWrite(ledPin, HIGH);
    Serial.println("Led encendido");
  } else if (data == "OFF") {
    digitalWrite(ledPin, LOW);
    Serial.println("Led apagado");
  }
  Serial.flush();
}
