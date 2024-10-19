// Función para leer la distancia usando un laser
/*int leerLaser() {
  VL53L0X_RangingMeasurementData_t measure;

  lox.rangingTest(&measure, false);
  // comprueba que no haya un error en la lectura
  if (measure.RangeStatus != 4) {
    return measure.RangeMilliMeter; 
  } else {
    return -1; //hubo en error, se retorna un valor -1 indicando error
  }
}

void iniciarLaser() {
  
  if (!lox.begin()) {
    Serial.println(F("Error al inicializar el VL53L0X"));
    while (1)
      ;
  }
}
*/