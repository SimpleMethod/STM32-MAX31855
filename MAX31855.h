/*
 * MAX31855.h
 *
 *  Created on: 16.08.2021
 *      Author: SimpleMethod
 *
 *Copyright 2021 SimpleMethod
 *
 *Permission is hereby granted, free of charge, to any person obtaining a copy of
 *this software and associated documentation files (the "Software"), to deal in
 *the Software without restriction, including without limitation the rights to
 *use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies
 *of the Software, and to permit persons to whom the Software is furnished to do
 *so, subject to the following conditions:
 *
 *The above copyright notice and this permission notice shall be included in all
 *copies or substantial portions of the Software.
 *
 *THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 *THE SOFTWARE.
 ******************************************************************************
 */

#ifndef INC_MAX31855_H_
#define INC_MAX31855_H_

#include "main.h"

typedef struct {
	uint16_t pin;
	GPIO_TypeDef *port;
} MAX31855_GPIO;

typedef struct {
	MAX31855_GPIO nss;
	SPI_HandleTypeDef *hspi;
	uint8_t fault;
	uint8_t ocFault;
	uint8_t scgFault;
	uint8_t scvFault;
	int32_t intTemp;
	uint8_t intTempSign;
	int32_t extTemp;
	uint8_t extTempSign;
} MAX31855_StateHandle;

MAX31855_StateHandle MAX31855_Handle;

void MAX31855_Init(MAX31855_StateHandle *MAX31855, SPI_HandleTypeDef * hspi, GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin);
uint8_t MAX31855_GetFault(MAX31855_StateHandle *MAX31855);
float MAX31855_GetTemperature(MAX31855_StateHandle *MAX31855);
float MAX31855_GeInternalTemperature(MAX31855_StateHandle *MAX31855);
void MAX31855_ReadData(MAX31855_StateHandle *MAX31855);
void MAX31855_SetNSSState(MAX31855_StateHandle *MAX31855, GPIO_PinState state);
float MAX31855_GetTemperatureInFahrenheit(MAX31855_StateHandle *MAX31855);
float MAX31855_GeInternalTemperatureInFahrenheit(MAX31855_StateHandle *MAX31855);




#endif /* INC_MAX31855_H_ */
