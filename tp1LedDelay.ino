//Definición de Pines
const int PIN_BOTON = 2;
const int PIN_LED = 13;

//Variables de Estado y Tiempos
bool ledEncendido = false;
bool ultimoEstadoBoton = LOW;
unsigned long tiempoInicio = 0;
unsigned long ultimoTiempoDebounce = 0;
const unsigned long tiempoDebounce = 50;//arreglo problemas de boton
const unsigned long intervaloDeseado = 60000;//delay

void setup() {
  pinMode(PIN_BOTON, INPUT);
  pinMode(PIN_LED, OUTPUT);
  digitalWrite(PIN_LED, LOW);
}

void loop() {
  int lecturaActual = digitalRead(PIN_BOTON);

  // debounce
  if (lecturaActual != ultimoEstadoBoton) {
    ultimoTiempoDebounce = millis();
  }
  if ((millis() - ultimoTiempoDebounce) > tiempoDebounce) {

    if (lecturaActual == HIGH && ledEncendido == false) {
      ledEncendido = true;
      tiempoInicio = millis(); //contador led
      delay(200); //debounce
    }
    //apagado prematuro
    else if (lecturaActual == HIGH && ledEncendido == true) {
      ledEncendido = false;
      delay(200);
    }
  }

  if (ledEncendido) {
    //cuenta regresiba
    if (millis() - tiempoInicio >= intervaloDeseado) {
      ledEncendido = false;
    }
  }

  //debounce
  ultimoEstadoBoton = lecturaActual;

  //end
  digitalWrite(PIN_LED, ledEncendido ? HIGH : LOW);
}
