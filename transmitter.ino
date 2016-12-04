/*   
 GNU GENERAL PUBLIC LICENSE
 Version 3, 29 June 2007

 Copyright (C) 2016 Vitor Torres.
 Everyone is permitted to copy and distribute verbatim copies
 of this license document, but changing it is not allowed.
 
 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
// 1) Documentaçao
//
// Código para o modulo Transmissor RF de 433MHz 
// Descrição: Este código envia um pacote de dados via RF a 433MHz
//
// Autor : Vitor Torres
// Data: 04/12/16
// MCU: ATEMEGA328P
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------

// 2) Diretivas de Pre-processador

//Biblioteca para uso dos módulos RF
#include <VirtualWire.h>

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------

// 3) Declarações Globais
char Valor_CharMsg[4]; // Guarda os caracteres da mensagem a ser enviada
int aux = 99; // Variável auxiliar usada para envio de caracteres

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------

// 4) Protótipos de funções

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------

// 5) Subrotinas
void setup() 
{
  Serial.begin(9600);   //baudrate = 9600 bits por segundo
  vw_set_tx_pin(4); // Seta a aentrada digital 4 do arduino como pino de transmissão do módulo RF 
  vw_setup(2000); // velocidade de comunicação do módulo RF
  Serial.println("Trasmissao modulo RF - Acione o botao...");
}

// Loop infinito de execução do código
void loop() 
{
  aux++;
  if (aux > 9) aux = 0;
  
  for (int i = 0; i <10; i++) 
  {    
    //Converte valor para envio
    itoa(aux,Valor_CharMsg,10);
    //Envio dos dados
    vw_send((uint8_t *)Valor_CharMsg, strlen(Valor_CharMsg));
    //Aguarda envio dos dados
    vw_wait_tx();
    Serial.print("Valor enviado: ");
    Serial.println(Valor_CharMsg);
  }
}
