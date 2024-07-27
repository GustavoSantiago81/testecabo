/*------- TESTADOR DE CABOS ------- */
//----- Definições dos pinos das Vias --------
#define canalBranco 38
#define canalPreto 39
#define canalVerde 40
#define canalVermelho 41
#define buzzer 42
#define but_cl 2
#define but_cm 1

char db9[] = {47, 48, 45, 0, 35, 21, 20, 36, 37};                                   // 9 pinos, quais estão na ordem do Pino 1 ao Pino 9
//char ports[4] = {38, 39, 40, 41};
char ports[4] = {canalBranco, canalPreto, canalVerde, canalVermelho};               // 4 vias, nesse caso
bool brancoIsOkay = false, pretoIsOkay = false, verdeIsOkay = false, vermelhoIsOkay = false;
int countBranco = 0, countPreto = 0, countVerde = 0, countVermelho = 0;

void setup() {
  Serial.begin(115200);
  pinMode(but_cl, INPUT_PULLUP);
  pinMode(but_cm, INPUT_PULLUP);
  // Configurando os pinos de entrada
  for (int i = 0; i < 9; i++) 
  {
    pinMode(db9[i], INPUT);
  }

  // Configurando os pinos de saída
  for (int i = 0; i < 4; i++) 
  {
    pinMode(ports[i], OUTPUT);
  }  

  pinMode(buzzer, OUTPUT);
  digitalWrite(buzzer, LOW);
}

void loop() 
{
  if(digitalRead(but_cl) == LOW){
    checkCL();
  }
  if(digitalRead(but_cm) == LOW){
    checkCM();
  }
}

void checkCL()
{
  Serial.println("iniciou função CL");
  for(int i = 0; i < 4; i++)
  {
    Serial.println("entrou no loop de canais");
    Serial.println("CANAL ATUAL: " + String(i));
    digitalWrite(ports[i], HIGH);
    delay(10);
    Serial.println("canal cor: " + String(ports[i]));
    if(ports[i] == canalBranco)
    {
      for(int i = 0; i < 9; i++)
      {
        Serial.println("pino atual: " + String(i));

        if(digitalRead(db9[i]) == HIGH)
        {
          brancoIsOkay = false;

          if(digitalRead(db9[6 - 1]) == HIGH || digitalRead(db9[9 - 1]) == HIGH)
            countBranco++;
            Serial.println("incrementou count branco");
        }
      }
      Serial.println("countBranco = " + String(countBranco));
      if(countBranco == 2)
      {
        brancoIsOkay = true;
      }
      Serial.println(String(brancoIsOkay));
    }

    if(ports[i] == canalPreto)
    {
      Serial.println("entrou no canalPreto");
      for(int i = 0; i < 9; i++)
      {
        Serial.println("pino atual: " + String(i));
        if(digitalRead(db9[i]) == HIGH)
        {
          pretoIsOkay = false;

          if(digitalRead(db9[5 - 1]) == HIGH || digitalRead(db9[3 - 1]) == HIGH)
            countPreto++;
            Serial.println("incrementou countPreto");
        }
      }
      Serial.println("countPreto = " + String(countPreto));
      if(countPreto == 2)
      {
        pretoIsOkay = true;
      }
    }

    if(ports[i] == canalVerde)
    {
      for(int i = 0; i < 9; i++)
      {
        if(digitalRead(db9[i]) == HIGH)
        {
          verdeIsOkay = false;
          if(digitalRead(db9[2 - 1]) == HIGH || digitalRead(db9[4 - 1]) == HIGH || digitalRead(db9[8 - 1]) == HIGH)
            countVerde++;
        }
      }

      if(countVerde == 3)
      {
        verdeIsOkay = true;
      }
    }

    if(ports[i] == canalVermelho)
    {
      for(int i = 0; i < 9; i++)
      {
        if(digitalRead(db9[i]) == HIGH)
        {
          vermelhoIsOkay = false;

          if(digitalRead(db9[1 - 1]) == HIGH || digitalRead(db9[7 - 1]) == HIGH)
            countVermelho++;
        }
      }

      if(countVermelho == 2)
      {
        vermelhoIsOkay = true;
      }
    }
    digitalWrite(ports[i], LOW);
  }
  if(brancoIsOkay)
  {
    Serial.println("branco ok");
  }
  if(pretoIsOkay)
  {
    Serial.println("preto ok");
  }
  if(verdeIsOkay)
  {
    Serial.println("verde ok");
  }
  if(vermelhoIsOkay)
  {
    Serial.println("vermelho ok");
  }
  if(brancoIsOkay&&pretoIsOkay&&verdeIsOkay&&vermelhoIsOkay)
  {
    digitalWrite(buzzer, HIGH);
    delay(200);
    digitalWrite(buzzer, LOW);
    delay(100);
    digitalWrite(buzzer, HIGH);
    delay(200);
    digitalWrite(buzzer, LOW);
  }
  else
  {
    digitalWrite(buzzer, HIGH);
    delay(1500);
    digitalWrite(buzzer, LOW);
    delay(200);
    digitalWrite(buzzer, HIGH);
    delay(1500);
    digitalWrite(buzzer, LOW);
  }
  brancoIsOkay=false;pretoIsOkay=false;verdeIsOkay=false;vermelhoIsOkay=false;
  countBranco=0;countPreto=0;countVerde=0;countVermelho=0;
}


/* CARDIOMAPA */
void checkCM()
{
  for(int i = 0; i < 4; i++)
  {
    digitalWrite(ports[i], HIGH);
    delay(100);
    if(ports[i] == canalBranco)
    {
      for(int i = 0; i < 7; i++)
      {
        delay(100);
        if(digitalRead(db9[i] == HIGH))
        {
          brancoIsOkay = false;

          if(digitalRead(db9[3 - 1]) == HIGH || digitalRead(db9[5 - 1]) == HIGH)
            countBranco++;
        }
      }

      if(countBranco == 2)
      {
        brancoIsOkay = true;
      }
    }

    if(ports[i] == canalPreto)
    {
      for(int i = 0; i < 7; i++)
      {
        delay(100);
        if(digitalRead(db9[i] == HIGH))
        {
          pretoIsOkay = false;

          if(digitalRead(db9[2 - 1]) == HIGH || digitalRead(db9[4 - 1]) == HIGH)
            countPreto++;
        }
      }

      if(countPreto == 2)
      {
        pretoIsOkay = true;
      }
    }

    if(ports[i] == canalVerde)
    {
      for(int i = 0; i < 7; i++)
      {
        delay(100);
        if(digitalRead(db9[i] == HIGH))
        {
          verdeIsOkay = false;
          delay(100);
          if(digitalRead(db9[7 - 1]) == HIGH)
            countVerde++;
        }
      }

      if(countVerde == 1)
      {
        verdeIsOkay = true;
      }
    }

    if(ports[i] == canalVermelho)
    {
      for(int i = 0; i < 7; i++)
      {
        delay(100);
        if(digitalRead(db9[i] == HIGH))
        {
          vermelhoIsOkay = false;

          if(digitalRead(db9[1 - 1]) == HIGH || digitalRead(db9[6 - 1]) == HIGH)
            countVermelho++;
        }
      }

      if(countVermelho == 2)
      {
        vermelhoIsOkay = true;
      }
    }
    digitalWrite(ports[i], LOW);
  }
  
  if(brancoIsOkay&&pretoIsOkay&&verdeIsOkay&&vermelhoIsOkay)
  {
    digitalWrite(buzzer, HIGH);
    delay(200);
    digitalWrite(buzzer, LOW);
    delay(100);
    digitalWrite(buzzer, HIGH);
    delay(200);
    digitalWrite(buzzer, LOW);
  }
  else
  {
    digitalWrite(buzzer, HIGH);
    delay(1500);
    digitalWrite(buzzer, LOW);
  }
  brancoIsOkay=false;pretoIsOkay=false;verdeIsOkay=false;vermelhoIsOkay=false;
  countBranco=0;countPreto=0;countVerde=0;countVermelho=0;
}