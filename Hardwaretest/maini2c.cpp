#include "mbed.h"
#include "BME280.h"

// in dit proof of concept gebruiken we I2C

//For IC2 intilization

char addr = 0x76 << 1; //OPGEPAST Mbed gebruikt 8 bit I2C addressen
BME280 TphIc2 = BME280(D4, D5, addr); 
//DO en D1 voor NUCLEO_L432KC
//D14 en D15 voor NUCLEO_F042K6

//PC serial initilization
Serial pc(USBTX, USBRX); //tx, rx


int main(){
    while(1){
        pc.printf("\n IC2");
        pc.printf("\n Humidity = %lf", TphIc2.getHumidity());
        pc.printf("\n Temperature = %lf", TphIc2.getTemperature());
        pc.printf("\n Presure = %lf", TphIc2.getPressure());
    }
}