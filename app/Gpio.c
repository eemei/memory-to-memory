#include "Gpio.h"
void delay (uint32_t delaycount){
	while (delaycount != 0){
		delaycount--;
	}
}

 void configurePort(int direction, int pinNum, GPIO *port) {

	 gpioUnresetEnableClock(port);
	 port->MODER &= ~(3<<(pinNum* 2));			//mode.pin= output
	 port->MODER |= direction << (pinNum * 2);

	 port->OTYPER &= ~(3<<(pinNum* 2));			//otype.pin = push-pull;
	 port->OTYPER |= 0 << (pinNum);

	 port->OSPEEDR &= ~(3 << (pinNum* 2));		//ospeed.pin = high speed;
	 port->OSPEEDR |= VERY_HIGH_SPEED << (pinNum * 2);
 	 }

 void configurePortInput(int pinNum, GPIO *port){
	 port->PUPDR &= ~(3 << (pinNum* 2));
	 port->PUPDR |= PULL_DOWN << (pinNum * 2);
 }

void writeOne(uint16_t pinNum, GPIO *port) {
	//HAL_GPIO_WritePin(port, pinNum, GPIO_PIN_SET);
	port->ODR &= ~( 1 << (pinNum));
	port->ODR |= 1 << (pinNum);
	}

void writeZero (uint16_t pinNum, GPIO *port){
	//HAL_GPIO_WritePin(port,pinNum, GPIO_PIN_RESET);
	port->ODR &= ~( 1 << (pinNum));
	port->ODR |= 0 << (pinNum);
	}

void ReadOne (uint16_t pinNum, GPIO *port) {
	port->IDR &= 1;
}

void portBitSetReset (int pinNum, GPIO *port){
	port->BSRR = 0x00006000;
}


