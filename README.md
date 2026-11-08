# Irrigação Autônoma com Arduino

Projeto do **Tio Rafa** (Prof. Rafael Oliveira) para ensinar, na prática, como fazer uma planta se virar sozinha quando você esquece de regar. Um Arduino lê a umidade do solo e liga uma bomba d'água só quando a terra está seca. Simples, barato e ótimo para a sala de aula.

O kit de componentes é vendido pela [Mamute Eletrônica](https://www.mamuteeletronica.com.br/kit-irrigacao-com-arduino-prof-rafael-oliveira-21797).

## Como funciona

1. O sensor de umidade de solo HD-38 (sonda anticorrosiva) mede a terra.
2. Quando a umidade fica abaixo do limite ajustado no potenciômetro do sensor, a saída digital (D0) vai para nível alto.
3. O Arduino lê esse sinal e aciona o relé.
4. O relé liga a bomba submersível e a água corre.
5. Terra úmida de novo? O sensor avisa, o relé desliga e a bomba descansa.

## Por que usar um sistema assim

- **Economia de água:** só irriga quando precisa.
- **Economia de energia:** a bomba só liga quando necessário.
- **Controle preciso:** evita o excesso de água, que também machuca as plantas.
- **Automático:** funciona sem ninguém por perto.
- **Flexível:** troque o tipo de planta ou de solo e basta ajustar o limite do sensor.
- **Baixo custo:** componentes comuns e fáceis de achar.

## Materiais

- Arduino (Uno ou compatível)
- Sensor de umidade de solo HD-38 com sonda anticorrosiva
- Módulo relé
- Bomba d'água submersível
- Fonte de alimentação para a bomba
- Jumpers e mangueira

## Ligações

Pinos usados no código:

| Função | Pino do Arduino |
|---|---|
| Sinal do sensor (D0) | 2 |
| Acionamento do relé | 3 |

Sensor (4 pinos): `VCC` no 5V do Arduino, `GND` no GND, `D0` no pino 2. O pino `A0` não é usado neste exemplo.

Alimentação e bomba:

- Positivo da fonte no `VIN` do Arduino e no relé.
- Negativo da fonte no `GND` do Arduino e na bomba.
- Positivo da bomba no relé.
- 5V e GND do Arduino no relé e no sensor.

## Código

O sketch está em [`src/irrigacao_Tio_Rafa/irrigacao_Tio_Rafa.ino`](src/irrigacao_Tio_Rafa/irrigacao_Tio_Rafa.ino).

Detalhe importante: o módulo relé usado é do tipo **ativo em nível baixo**. Por isso o código escreve `LOW` para ligar a bomba e `HIGH` para desligar. Se o seu módulo for ativo em nível alto, é só inverter os dois valores.

## Como carregar no Arduino

1. Instale a [Arduino IDE](https://www.arduino.cc/en/software).
2. No Windows, se a placa for clone com chip CH340, instale também o [driver CH340 (Drive_CH340_Install_Windows_v3_4.zip)](https://drive.google.com/file/d/1uep_2XclnLIY8_j_tbil4kdoYx7p8VdD/view).
3. Conecte o Arduino, escolha a placa e a porta em **Ferramentas**.
4. Abra o arquivo `.ino` e clique em **Carregar**.
5. Ajuste o potenciômetro do sensor até o ponto de umidade que você quer.

## Tutorial completo

O passo a passo ilustrado, com fotos da montagem, está no PDF:
[Irrigação com Arduino (PDF)](docs/Irrigacao_com_Arduino_Tio_Rafa.pdf), também disponível em [tiorafa.tec.br](https://tiorafa.tec.br/downloads/tutoriais/irrigacao-com-arduino.pdf)

Mais projetos em [tiorafa.tec.br](https://tiorafa.tec.br).

## Autor

**Tio Rafa** (Rafael de Souza Oliveira) · [@prof.tiorafa](https://www.youtube.com/@prof.tiorafa) · contato@tiorafa.tec.br

## Licença

[MIT](LICENSE)
