/* Testador de Cabos */

#define buzzer 10
char um ='u';
char cadeia[]="cadeia";
char teste[]={2,1};
char db9[] = {20, 21, 47, 48, 45, 0, 35, 36, 37};   // 9 pinos, quais poderia usar um mux
char binario[9];
char ports[4] = {11, 12, 13, 14};               // 4 vias, nesse caso
bool branco = false, preto = false, verde = false, vermelho = false;

void setup() {
  Serial.begin(115200);
  // Configurando os pinos de entrada
  for (int i = 0; i < 9; i++) {
    pinMode(db9[i], INPUT);
  }

  // Configurando os pinos de saída
  for (int i = 0; i < 4; i++) {
    pinMode(ports[i], OUTPUT);
  }  
}

void loop() {
  
  for(int i = 0; i < 4; i++) 
  {
    digitalWrite(ports[i], HIGH);

    if((digitalRead(37) == HIGH)&&ports[i]==0)
    {
      if((digitalRead(20)||digitalRead(48)||digitalRead(45)||digitalRead(0)||digitalRead(35)||digitalRead(36)||digitalRead(21)||digitalRead(47))== LOW)
      {
        branco = true;
      }
    }
    if((digitalRead(45)&&digitalRead(47) == HIGH)&&ports[i]==1)
    {
      if((digitalRead(20)||digitalRead(48)||digitalRead(45)||digitalRead(0)||digitalRead(35)||digitalRead(36)||digitalRead(21))== LOW)
      {
        preto = true;
      }
    }
    if((digitalRead(21)&&digitalRead(48)&&digitalRead(46) == HIGH)&&ports[i]==2)
    {
      if((digitalRead(20)||digitalRead(47)||digitalRead(45)||digitalRead(0)||digitalRead(35)||digitalRead(36)||digitalRead(37))==LOW)
      {
        verde = true;
      }
    }
    if((digitalRead(20)&&digitalRead(35) == HIGH)&&ports[i]==3)
    {
      if((digitalRead(21)||digitalRead(48)||digitalRead(45)||digitalRead(0)||digitalRead(47)||digitalRead(36)||digitalRead(37))== LOW)
      {
        vermelho = true;
      }
    }
  
    digitalWrite(ports[i], LOW);
  }

  if(branco, preto, verde, vermelho)
  {
    digitalWrite(buzzer, HIGH);
    delay(100);
    digitalWrite(buzzer, LOW);
    delay(100);
  }
  else
  {
    digitalWrite(buzzer, HIGH);
    delay(1000);
    digitalWrite(buzzer, LOW);
    delay(100);
  }
  branco =false;
  preto=false;
  verde=false;
  vermelho=false;
}
