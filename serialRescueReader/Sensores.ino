#include "pines.h"



void SerialReading(){
  Serial.print("Sensores | ");
  for (int i = 0; i < SensorCount ; i ++){
    Serial.print(sensorValues[i]);
    Serial.print(" | ");
  
  }
  Serial.print("| POS:");
  Serial.println(posicion);
}



//Funcion para inicializar el sensor Infrarrojo, el objeto debe estar creado de forma global
//Para crear el objeto se debe usar: QTRSensors PID;
void inicializarSensores() {

  // Configuración de los sensores
  PID.setTypeAnalog();
  PID.setSensorPins((const uint8_t[]) {26, 25, 33, 32, 35, 34, 39, 36}, SensorCount);
  PID.setEmitterPin(27);
  PID.read(sensorValues);
}


void calibrarSensores() {
  //El límite del for define la duración de la calibración
  for (int i = 0; i < 350; i++) {

    PID.calibrate();
  }
  //Calculo de umbrales para cada sensor individual
  for (int i=0;i<SensorCount;i++){
    umbralValues[i] = ((PID.calibrationOn.minimum[i]+PID.calibrationOn.maximum[i])/2) + toleranciaUmbral;
  }

}