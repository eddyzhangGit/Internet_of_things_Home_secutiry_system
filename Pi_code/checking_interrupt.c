/*


*Input         :None
*Return        :None
*/
#include <bcm2835.h>
#include <stdio.h>
#include <time.h>
#include <stdint.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/types.h>
#include <linux/I2C/I2Cdev.h>
#include "Init_STM.h"
#define PIN_INT RPI_GPIO_P1_22
#define PIN_SDA RPI_GPIO_P1_11
#define PIN_SCK RPI_GPIO_P1_16
#define PIN_FAKE RPI_GPIO_P1_18

void init_all(void)
{
	if (!bcm2835_init())
		return;

	bcm2835_I2C_begin();


	bcm2835_gpio_fsel(PIN_INT, BCM2835_GPIO_FSEL_INPT);           // Set RPI pin P1-15 to be an input for INTN
	bcm2835_interrupt_handler(&Interrupt_Handler);
	bcm2835_gpio_fsel(PIN_SDA, BCM2835_GPIO_FSEL_OUTP);           ///Set RPI pin P1-11 to be an output for SSN
	bcm2835_gpio_fsel(PIN_SCK, BCM2835_GPIO_FSEL_OUTP);         // Set RPI pin P1-16 to be an output for RESET

	bcm2835_I2C_write(0x10, 0x08);                              //Power on
	bcm2835_I2C_write(0x21, 0x14);                              //interrrupt active low and low threhold
	bcm2835_I2C_write(0x24, 0x08);                       //Set the low threold value to about 5 cms!


	while (1)
	{
		char distance[2];
		bcm2835_I2C_write(0x12, distance);
		printf("No interrupt Distance is %d cm\n",(int)((distance[1]<< 8 || distance[0])*0.072)); //2 byte value and apply sensitivity--->get distance
		delay(100);
		  
	}
}


void Interrrupt_Handler(void)
{
	byte pin_readings;
	bcm2835_gpio_read(PIN_INT, &pin_readings);
	if (pin_readings == 0)  //Active low
	{
		printf("Alert Home invation Distance : 3cm\n");
	}
}