//VARIABLES
int carGreen = 12;
int carYellow = 11;
int carRed = 10;
int passGreen = 9;
int passRed = 8;
int button = 2;
int btnEstado;



void setup() {
  pinMode(carRed, OUTPUT);
  pinMode(carYellow, OUTPUT);
  pinMode(carGreen, OUTPUT);
  pinMode(passRed, OUTPUT);
  pinMode(passGreen, OUTPUT);
}


void loop() {
   btnEstado = digitalRead(button); 
   ejecutar();
}


void ejecutar(){
  //EVALUA EL ESTADO DEL PIN 2 DEL BOTON SI ESTA PRECIONADO O NO 
  if(btnEstado != LOW){
    btnPasarPeaton();
  }else{
    for(int i=0; i < 1 ; i++){
        // para como parametro el estado de los leds 12 11 10 
        senialSemaforo(carGreen);
        senialSemaforo(carYellow);
        senialSemaforo(carRed);
      }
  }
}

void senialSemaforo(int pass){
  //utilizo el metodo pasarPeaton para evaluar el estado de los leds 12 11 10 y realizo que se apagen y encienda los leds por order 12 11 10 
  pasarPeaton(pass);
  digitalWrite(pass,HIGH);
  delay(1000);
  digitalWrite(pass,LOW);
}



void btnPasarPeaton(){
    //paso como parametro el estado de los leds 12 11 10 para que luego sea evaluado 
    senialPeaton(carGreen);
    senialPeaton(carYellow);
    senialPeaton(carRed);
  
}

void senialPeaton(int pass){
  //HACE PARPADEAR LOS LEDS 12 11 10 a traves de la funcion for 3 veces y  utilizo el metodo pasarPeaton para
  // evaluar el estado de los leds 12 11 10 y reutilizo codigo 
  pasarPeaton(pass);
  for(int i = 0 ; i < 3 ; i++){
    digitalWrite(pass,LOW);
    delay(500);
    digitalWrite(pass,HIGH);
    delay(500);
  }
  digitalWrite(pass,LOW);
}






void pasarPeaton(int pass){
    //EVALUA EN QUE ESTADO SE ENCUENTRA EL PIN 12 , 11 , 10  Y ENCIENDE O APAGA LOS LEDS 9 O 8 
    //SEGUN EL CASO 
    switch(pass){
    case 12:
      digitalWrite(passGreen,LOW);
      digitalWrite(passRed,HIGH);
    break;
    case 11:
      digitalWrite(passRed,HIGH);
    break;
    case 10:
      digitalWrite(passRed,LOW);
      digitalWrite(passGreen,HIGH);
    break;
  }
}
 
