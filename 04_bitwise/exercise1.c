#include<stdio.h>
#include<stdint.h>

void setBit(uint8_t *value, uint8_t bit){
    *value |= (1U<< bit);
    
}
void clearBit(uint8_t *value, uint8_t bit){
    *value &=~(1U<< bit);
    
}
void toggleBit(uint8_t *value, uint8_t bit){
    *value ^=(1U<<bit);
     
}
uint8_t readBit(uint8_t value, uint8_t bit){
    return (value >> bit) & 1;}
int main(void){
    uint8_t data = 0b00000000;
    setBit( &data, 3);
    clearBit(&data, 3);
    toggleBit(&data, 0);
    printf("Trang thai bit so 3: %d\n", readBit(data, 3));
    printf("Trang thai bit so 0: %d\n", readBit(data, 0));
}