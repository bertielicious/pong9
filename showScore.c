#include "config.h"
#include "set_address.h"
#include "writeChar.h"
void showScore(uchar score, uchar x, uchar page)
{
    uchar g;
    switch(score)
    {
        case 0:
            for(g = 0; g < 8; g++)
            {
                gameplay_area[page][x+g] = gameplay_area[page][x+g]|cero[g];
            } 
            break;
        case 1:
            for(g = 0; g < 8; g++)
            {
                gameplay_area[page][x+g] = gameplay_area[page][x+g]|uno[g];
            } 
            break;
        case 2:
            for(g = 0; g < 8; g++)
            {
                gameplay_area[page][x+g] = gameplay_area[page][x+g]|dos[g];
            } 
            break;
        case 3:
            for(g = 0; g < 8; g++)
            {
                gameplay_area[page][x+g] = gameplay_area[page][x+g]|tres[g];
            } 
            break;
        case 4:
            for(g = 0; g < 8; g++)
            {
                gameplay_area[page][x+g] = gameplay_area[page][x+g]|cuatro[g];
            } 
            break;
        case 5:
            for(g = 0; g < 8; g++)
            {
                gameplay_area[page][x+g] = gameplay_area[page][x+g]|cinco[g];
            } 
            break;
        case 6:
            for(g = 0; g < 8; g++)
            {
                gameplay_area[page][x+g] = gameplay_area[page][x+g]|seis[g];
            } 
            break;
        case 7:
            for(g = 0; g < 8; g++)
            {
                gameplay_area[page][x+g] = gameplay_area[page][x+g]|siete[g];
            } 
            break;
        case 8:
            for(g = 0; g < 8; g++)
            {
                gameplay_area[page][x+g] = gameplay_area[page][x+g]|ocho[g];
            } 
            break;
        case 9:
            for(g = 0; g < 8; g++)
            {
                gameplay_area[page][x+g] = gameplay_area[page][x+g]|nueve[g];
            } 
            break;
        default:
            for(g = 0; g < 8; g++)
            {
                gameplay_area[page][x+g] = gameplay_area[page][x+g]|0x00;
            } 
            break;
            
    }
}
