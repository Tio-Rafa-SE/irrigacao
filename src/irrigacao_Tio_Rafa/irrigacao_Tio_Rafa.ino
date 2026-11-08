/*
  ============================================================
  IRRIGACAO AUTOMATICA COM ARDUINO
  ============================================================
  Autor:    Prof. Rafael de Souza Oliveira (Tio Rafa)
  Site:     https://tiorafa.tec.br
  E-mail:   contato@tiorafa.tec.br
  Redes:    @prof.tiorafa (YouTube, Instagram e TikTok)
  GitHub:   https://github.com/Tio-Rafa-SE/irrigacao
  Kit:      Mamute Eletronica - Kit Irrigacao com Arduino
            https://www.mamuteeletronica.com.br/kit-irrigacao-com-arduino-prof-rafael-oliveira-21797
  Licenca:  MIT

  Como funciona:
    O sensor de umidade de solo HD-38 (saida digital D0) envia
    nivel ALTO quando a terra esta seca. Nesse caso o Arduino
    aciona o rele e a bomba d'agua molha a planta. Terra
    umida de novo, o rele desliga a bomba.

  Ligacoes:
    Sensor D0  -> pino 2
    Rele (IN)  -> pino 3
    Sensor e rele: 5V e GND do Arduino

  Atencao: o modulo rele e ativo em nivel BAIXO
  (LOW liga a bomba, HIGH desliga).
*/

#define rele 3
#define sensor 2

bool irrigar = false;
void setup()
{
  pinMode(rele, OUTPUT);
  pinMode(sensor, INPUT);
  
  digitalWrite( rele, HIGH);
}

void loop() 
{
  irrigar = digitalRead(sensor);

  if(irrigar)
  {
    digitalWrite(rele, LOW);
  }
  else
  {
    digitalWrite(rele, HIGH);
  }

  delay(500);
}
