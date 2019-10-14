/*                  16f1459
 *                  ---------
 *   +5 Volts    1 |Vdd      | 20 0 Volts
 *Player select  2 |RA5      | 19
 * Paddle up  L  3 |RA4      | 18
 *    MCLR/ RST  4 |         | 17
 *    GREEN LED  5 |RC5      | 16
 *           CE  6 |RC4      | 15
 *RST op to 5110 7 |         | 14  RC2 Paddle down L
 *           SS  8 |         | 13 
 *           SDO 9 |         | 12
 *           TX 10 |         | 11  SCK
 *                  ---------
 
 */



#include "config.h"
#include <stdio.h>
#include "main.h"
#include "config_osc.h"
#include "setup_ports.h"
#include "init_spi.h"
#include "set_usart.h"
#include "putch.h"
#include "lcd_setup.h"
#include "TMR0_setup.h"
#include "TMR1_setup.h"
#include "interrupt isr.h"
#include "lcdWrite.h"
#include "set_address.h"
#include "set_game_area.h"
#include "paddleMove.h"
#include "animate.h"
#include "posnBall.h"
#include "render.h"
#include "clearScreen.h"
#include "update.h"
#include "clearPosition.h"
#include "writeChar.h"
#include "showScore.h"
#include "splitDigits.h"

void main(void) 
{
config_osc();       // internal clock frequency = 8MHz
setup_ports();      
init_spi();
set_usart();
lcd_setup();        // configures the LCD
set_game_area();
TMR0_setup();
TMR1_setup();
clearScreen();

printf("Pong !\n");
bool flag = 0;
uchar g;
float row = 2 ;
float col = 2 ;
uchar currentScore = 0;
float colSpeed = 0.9;
float rowSpeed = 2;
//set initial ball position
set_address(0, page);   // column = 0, page = 3
lcdWrite (paddle[0], HIGH);
set_address(1, page);   // column = 1, page = 3
GIE = 0;    // interrupts off
lcdWrite (paddle[1],HIGH);

splitDigits(rightScore);
showScore(units, 60,1);

splitDigits(leftScore);
showScore(units, 16,1);

GIE = 1; //interrupts on

        while(1)
        {
            if(col > (WIDTH-3))     // when ball columns = 80, 81, 82, send the motion of the ball from right to left
            {    
               colSpeed = -0.3;     
            }
           
            
            
           
            if(col < 3 && ( (position[page][0] && position[page][1]) >0))// || (position[page-1][0] && position[page-1][1]) > 0)) // when col = 2, send the motion of the ball from left to right
                
            {
                
                colSpeed = 0.3;
                clearPosition();        // clears data stored in collision detecting array position[6][2]]
                
                leftScore = leftScore + 1;  // as the paddle detected a collision with the ball, increment the left score
                for(g = 0; g < 8; g++)
                {
                    gameplay_area[1][16+g] = 0x00;  // clear previous leftScore from LCD to avoid over writing updated score
                    gameplay_area[1][10+g] = 0x00;
                } 
                splitDigits(leftScore); // split the score into units and tens
                showScore(units, 16,1); // show the units score at position col = 16, row = 1
                if(leftScore > 9)       // only show the tens digit of the score when units are greater than 9
                {
                    showScore(tens, 8,1);   // show the tens score at position col = 8, row = 1;
                }
           
            } 
            if(col <2)
            {
                while(1);
            }
           
            col = col + colSpeed;
            animate(col, 12, 0); 
        }
}  
              

                            

