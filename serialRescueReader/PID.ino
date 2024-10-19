

void pidUpdate() {
  // Cálculo PID

 
  if (posicion >= lim1 && posicion <= -lim1) {  //dentro del rango de posicion -> no pid
    Ki = 0.003;
    Kp = 0.0;
    Kd = 0;
  }  else if (posicion > lim1 && posicion <= lim2) {  //pid suave
      Ki = 0.0009;
      Kd = 0.1;
      Kp = 0.3;
    }
    else if(posicion >= -lim2 && posicion < -lim1){
      Ki = 0.007;
      Kd = 0.8;
      Kp = 0.09;

    }
  else {  //-255 -> 255 pid agresivo
    Ki = 0.0; 
    Kp = 0.34;
    Kd = 0.5;
  }

  error = posicion - ref;
  integral = integral + lastError + error3 + error4 + error5 + error6;
  derivada = error - lastError;
  giro = Kp * error + Ki * integral + Kd * derivada;
  int velizq = Tp + giro;
  int velder = Tp - giro;

  if (velizq < minUmbral) {
    velizq = minUmbral;
  }
  if (velder < minUmbral) {
    velder = minUmbral;
  }
  if (velder > maxUmbral) {
    velder = maxUmbral;
  }
  if (velizq > maxUmbral) {
    velizq = maxUmbral;
  }


  if ( sensorValues[0] < umbralValues[0] and sensorValues[1] < umbralValues[1] and sensorValues[2] < umbralValues[2] and sensorValues[3] < umbralValues[3] and sensorValues[4] < umbralValues[4] and sensorValues[5] < umbralValues[5] and sensorValues[6] < umbralValues[6] and sensorValues[7] < umbralValues[7]){
   Motores(30,30);
  } else{
    Motores(velizq, velder);
  }
  
}




void errorUpdate() {
  error6 = error5;
  error5 = error4;
  error4 = error3;
  error3 = lastError;
  lastError = error;
}

//ACTUALIZAR VALORES DE PID DEPENDIENDO DEL ESTADO DE LA PISTA
