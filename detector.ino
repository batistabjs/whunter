GNU GENERAL PUBLIC LICENSE
 Version 3, 29 June 2007

 Copyright (C) 2016 Luis Corbelino.
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
 
#include <VirtualWire.h>
void setup()
{
  Serial.begin(9600);           // Debugging only
  Serial.println("Agua-fi");      
  vw_setup(2000);               // determina a velocidade
  vw_rx_start();                // Inicia o recebimento
}

void loop()
{
uint8_t buf[VW_MAX_MESSAGE_LEN];
uint8_t buflen = VW_MAX_MESSAGE_LEN;
int rssi;
  if (vw_get_message(buf, &buflen))   // Non-blocking
  {
      int i;
      digitalWrite(13, true);         //recebeu mensagem
      Serial.println("");
      rssi = analogRead(A6);           // leitura da intensidade do sinal RF
      Serial.println(rssi);
      Serial.println("");
      digitalWrite(13, false);  
      
      if(rssi>300){                     //Vazamento detectado
    
          digitalWrite(6,true);         
      }
      else{
          digitalWrite(6,false);
      }
   }
}
