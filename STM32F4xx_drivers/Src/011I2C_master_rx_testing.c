/*
 * 011I2C_master_rx_testing.c
 *
 *  Created on: 22-Jan-2021
 *      Author: Sayan Rana
 */

#include <stdio.h>
#include <string.h>
#include <stm32f407xx.h>

/*
 * PB10-------> SCL
 * PB11-------> SDA
 */

// Own device address(Only used in slave mode)
#define MY_ADDR				0x61
// Slave address(Only used in master mode)
#define SLAVE_ADDR			0x68


I2C_Handle_t I2C2Handle;

// rcv_buffer
uint8_t rcv_buf[32];


// Software delay for testing purpose
void delay(void)
{
	for(uint32_t i = 0; i < 500000; i++);
}


void GPIO_ButtonInit(void)
{
	GPIO_Handle_t gpioBtn;
	//Button(Input) pin configuration.
	gpioBtn.pGPIOx = GPIOA;
	gpioBtn.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_0;
	gpioBtn.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_IN;
	gpioBtn.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	gpioBtn.GPIO_PinConfig.GPIO_PuPdControl = GPIO_NO_PUPD;

	GPIO_Init(&gpioBtn);
}


void I2C2_GPIOInit(void)
{
	GPIO_Handle_t I2CPins;

	I2CPins.pGPIOx = GPIOB;
	I2CPins.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_ALTFN;
	I2CPins.GPIO_PinConfig.GPIO_PinOpType = GPIO_OP_TYPE_OD;
	I2CPins.GPIO_PinConfig.GPIO_PuPdControl = GPIO_PIN_PU;
	I2CPins.GPIO_PinConfig.GPIO_PinAltFunction = 4;
	I2CPins.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;

	// SCL
	I2CPins.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_10;
	GPIO_Init(&I2CPins);

	// SDA
	I2CPins.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_11;
	GPIO_Init(&I2CPins);
}


void I2C2_Init(void)
{
	I2C2Handle.pI2Cx = I2C2;
	I2C2Handle.I2C_Config.I2C_ACKControl = I2C_ACK_ENABLE;
	I2C2Handle.I2C_Config.I2C_DeviceAddress = MY_ADDR;
	I2C2Handle.I2C_Config.I2C_FMDutyCycle = I2C_FM_DUTY_2;
	I2C2Handle.I2C_Config.I2C_SCLSpeed = I2C_SCL_SPEED_SM;

	I2C_Init(&I2C2Handle);
}


int main()
{
	uint8_t commandCode, len;

	//GPIO Button init
	GPIO_ButtonInit();

	// I2C pin init
	I2C2_GPIOInit();

	// I2C Peripheral configuration
	I2C2_Init();

	// Enable the I2C peripheral
	I2C_PeripheralControl(I2C2, ENABLE);

	// Enabling ACK after PE = 1;
	I2C_ManageAcking(I2C2, I2C_ACK_ENABLE);

	// Wait for button press
	while(1)
	{
		// Wait till button is pressed
		while(!( GPIO_ReadFromInputPin(GPIOA, GPIO_PIN_NO_0) ) );

		// to avoid button de-bouncing related issues 200ms of delay
		delay();

		commandCode = 0x51;		// Command code to get length information from slave

		// Master send command code to slave for length information
		I2C_MasterSendData(&I2C2Handle, &commandCode, 1, SLAVE_ADDR,I2C_ENABLE_SR);

		// Master reading response(Length info) from slave
		I2C_MasterReceiveData(&I2C2Handle, &len, 1, SLAVE_ADDR, I2C_ENABLE_SR);

		commandCode = 0x52;		// Command code to initiate the data reception from slave

		// Master sends command code to slave for length number of data reception
		I2C_MasterSendData(&I2C2Handle, &commandCode, 1, SLAVE_ADDR, I2C_ENABLE_SR);

		// Master receiving data from slave(length of data = len)
		I2C_MasterReceiveData(&I2C2Handle, rcv_buf, len, SLAVE_ADDR, I2C_DISABLE_SR);

		rcv_buf[len] = '\0';
		printf("Message is : %s\n",rcv_buf);

	}



}













