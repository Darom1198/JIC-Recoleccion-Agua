//Pines de Sensores
const int solenoide = 13;
const int sensorAgua = A5;

//Un dia en milisegundos
const long dia = 86400000;

//Declaracion de variable que recibe valor de lectura del sensor de agua
int lecturaAgua = 0;

void setup() {
  //Inicializacion de los sensores
  pinMode(solenoide, OUTPUT);
  pinMode(sensorAgua, INPUT);
}

void loop() {
  //El solenoide se cierra antes de comprobar si existe agua suficiente
  digitalWrite(solenoide, HIGH);
  //Lectura de sensor de agua
  lecturaAgua = analogRead(sensorAgua);
  if (lecturaAgua > 300) {
    //Se abre el solenoide
    digitalWrite(solenoide, LOW);
    //Se espera que la planta se riegue por 3 minutos
    delay(180000);
  } else {
    //Mantiene solenoide cerrado
    digitalWrite(solenoide, HIGH);
  }
  //El sensor de agua vuelve a verificar despues de un dia
  delay(day);
}
