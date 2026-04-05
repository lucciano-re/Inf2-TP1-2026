//Definición de Pines
const int PIN_BOTON = 2;
const int PIN_LED = 13;

//Variables de Estado y Tiempos
bool ledEncendido = false;

void setup() {
  pinMode(PIN_BOTON, INPUT);
  pinMode(PIN_LED, OUTPUT);
  digitalWrite(PIN_LED, LOW);
}

void loop() {
  int lecturaActual = digitalRead(PIN_BOTON);
  // debounce
  if (lecturaActual == HIGH && ledEncendido == false) {
    ledEncendido = true;
    delay(200); //debounce
  }
  //apagado
  else if (lecturaActual == HIGH && ledEncendido == true) {
    ledEncendido = false;
    delay(200);
  }
  //endload
  digitalWrite(PIN_LED, ledEncendido ? HIGH : LOW);
}
