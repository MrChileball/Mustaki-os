

#include <QTRSensors.h>
#include <Wire.h>
#include "pines.h"


// Láser
//Adafruit_VL53L0X lox = Adafruit_VL53L0X();


QTRSensors PID;
const uint8_t SensorCount = 8;
uint16_t sensorValues[SensorCount];
uint16_t umbralValues[SensorCount];
int toleranciaUmbral = 200;                //Valor que se suma a los umbrales para asegurar la correcta lectura

// Frecuencia y resolución PWM
const int freq = 5000;
const int resolution = 8;


unsigned long lastUpdateTime = 0; // Tiempo del último manejo de cliente web
const unsigned long updateInterval = 1000; // Intervalo en milisegundos para manejar peticiones web

// Variables PID
float Kp = 0.23;  // Desviación del robot al respecto de la linea
// Mayor desviación == mayor corrección
float Ki = 0.0;      // Elimina el error ocupandoce de errores pasados
float Kd = 0.89;  // Reduce osilaciones
int ref = 0;
int Tp = 30;
float giro; //velocidad de giro para corregir

float integral = 0;
float derivada = 0;
float lastError = 0;

int error6 = 0;
int error5 = 0;
int error4 = 0;
int error3 = 0;
int error = 0;

//Limites del PID variable
uint8_t lim1 = -20;
uint8_t lim2 = 210;

int posicion; //estado del robot en la pista

//Umbral de velocidad
uint16_t minUmbral = 0;
uint16_t maxUmbral = 250;
//Umbral para detección de blanco y negro en la pista
uint16_t luzValue = 700;

uint8_t interCount = 0; //Contador número de intersecciones
uint8_t turnCount = 0; //Contador número de giros

uint8_t sectionEnd = 11; //Numero de intersecciones hasta detenerse;
uint8_t sectionDecision = 8; //Intersección donde debe decidir

bool decision = false;



void setup() {
  Serial.begin(115200);
 

  //Esta parta de código es necesaria para iniciar i2c
  //Wire.begin();
  //Wire.setClock(100000);  // Configura la velocidad del I2C a 100kHz (puedes probar también 400kHz)

  //Se inicia la comunicación serial
  

  //Se inicia el laser
  //iniciarLaser();

  // Configuración de los motores (PWM)
  ledcSetup(1, freq, resolution);
  ledcSetup(0, freq, resolution);
  ledcAttachPin(PWMB, 1);
  ledcAttachPin(PWMA, 0);

  pinMode(BIN2, OUTPUT);
  pinMode(BIN1, OUTPUT);
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);

  
  inicializarSensores();
  calibrarSensores();

  while(true){
    if(digitalRead(BUTTON)== true){
      Motores(40,40); 
      delay(1000); 
      break; x
    }
  }
}

void loop() {
  // Leer posición de los sensores
  PID.read(sensorValues);
  posicion = PID.readLineBlack(sensorValues);
  posicion = map(posicion, 0, 7000, -255, 255);

  int actualStatus = checkCases();
  

  if(actualStatus == 0){
    pidUpdate();
  } else if (actualStatus == 1){
    // intersección
    interCount++; 

    Motores(0, 0);
    delay(100);
    Motores(50, 50);
    delay(250);

    /*if (I == interseccionDecision) {  // Me indica que despues viene la dirección de camino
      flagMarcador = true;
      Motor(0, 0);
      delay(2000);
      Motor(50, 50);
      delay(200);
    } else if (I == interseccionDinamica && flagGiroIzquierda == true) {  //Dirección de camino izquierda
      girarIzquierda();
    } else if (I == interseccionDinamica && flagGiroDerecha == true) {  //Dirección de camino derecha
      girarDerecha();
    } else if (I == interseccionFin) {  // Final stop
      Motor(0, 0);
      // funcionLEDS();
    }*/
  } else if (actualStatus == 2){
    // blanco gap
    Motores(18,18);

  } else if (actualStatus == 3){
    // detecta izquierda
    leftTurn();
    turnCount++; 
  } else if (actualStatus == 4){
    // detecta derecha
    rightTurn();
    turnCount++; 
  }
  
  
  



  // Control de motores
  void errorUpdate();

  SerialReading();
  // Manejo de peticiones web

}





 