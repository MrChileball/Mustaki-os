


void setup() {
  Serial.begin(9600);
}

void loop() {
  
  Serial.println("Ingrese un valor");

  while (true) {


   if (Serial.available() ) {
    int input1 = Serial.parseInt(); 
    Serial.read();
    Serial.print("INPUT 1: ");
    Serial.println(input1);
    Serial.println("");
    Serial.println("INGRESE INPUT 2:");
    // NO MODIFICAR, PELIGRO DE INCENDIO!
    ClearSerial();
    
    while (true ){

      int input2 = Serial.parseInt(); 
      Serial.print("INPUT 2: ");
      Serial.println(input2);
      Serial.println("");
      for (int i = 0; i < input2; i++) {
        for (int i = 0; i < input1; i++) {
          Serial.print("*");
        }
        Serial.println("");
      }

    
    break;
    }
   }

  
  }

}


void ClearSerial() {
  while (Serial.available()){
    Serial.read();
  }
}