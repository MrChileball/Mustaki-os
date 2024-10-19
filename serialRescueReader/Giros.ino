void leftTurn(){
  Motores(-40, 40);  // Giro en el lugar, ajusta los valores de velocidad según sea necesario
  delay(1450);
  Motores(40,40);
  delay(350);  

}

void rightTurn(){
  Motores(40, -40);  // Giro en el lugar, ajusta los valores de velocidad según sea necesario
  delay(1450);
  Motores(40,40);
  delay(350);  

}
