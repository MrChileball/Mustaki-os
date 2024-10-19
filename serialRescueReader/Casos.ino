
  // Caso específico para gap o luz intensa
 /* bool todosMenorLuz = true;
  bool todosMayorLuz = true;
  for (int i = 0; i < 8; i++) {
    if (sensorValues[i] >= luzValue) {
      todosMenorLuz = false;
    }
    if (sensorValues[i] <= luzValue) {
      todosMayorLuz = false;
    }
  }*/



int checkCases () {
  int status;
  PID.read(sensorValues);
 //Que esta leyendo
  if (sensorValues[0] >= umbralValues[0] and sensorValues[1] >= umbralValues[1] and sensorValues[2] >= umbralValues[2] and sensorValues[3] >= umbralValues[3] and sensorValues[4] >= umbralValues[4] and sensorValues[5] >= umbralValues[5] and sensorValues[6] >= umbralValues[6] and sensorValues[7] >= umbralValues[7]) {
    status = 1;//negro interseccion
  } else if (sensorValues[0] < umbralValues[0] and sensorValues[1] < umbralValues[1] and sensorValues[2] < umbralValues[2] and sensorValues[3] < umbralValues[3] and sensorValues[4] < umbralValues[4] and sensorValues[5] < umbralValues[5] and sensorValues[6] < umbralValues[6] and sensorValues[7] < umbralValues[7]) {
    status = 2;//blanco gap
  } else if (sensorValues[0] < umbralValues[0] and sensorValues[1]< umbralValues[1] and sensorValues[2] < umbralValues[2]  and sensorValues[3] > umbralValues[3] and sensorValues[4] > umbralValues[4] and sensorValues[5] > umbralValues[5] and sensorValues[6] > umbralValues[6] and sensorValues[7] > umbralValues[7]) {
    status = 3; //detecta izquierda
  } else if (sensorValues[0] > umbralValues[0] and sensorValues[1] > umbralValues[1] and sensorValues[2] > umbralValues[2] and sensorValues[3] > umbralValues[3] and sensorValues[4] > umbralValues[4] and sensorValues[5] < umbralValues[5] and sensorValues[6] < umbralValues[6] and sensorValues[7] < umbralValues[7]) {
    status = 4; //detecta derecha 
  } else {
    status = 0;
  }
  return status;
}