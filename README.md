# STM32 MAX31855 

## STM32 library for MAX31855 temperature sensor using HAL and SPI

![proof of concept](https://raw.githubusercontent.com/SimpleMethod/STM32-MAX31855/master/doc/temp.png)

# Example:

     /* USER CODE BEGIN 2 */
    	MAX31855_Init(&MAX31855_Handle, &hspi3,SPI3_NSS_GPIO_Port, SPI3_NSS_Pin);
    	uint32_t Timer = HAL_GetTick();
     /* USER CODE END 2 */
     /* Infinite loop */
     /* USER CODE BEGIN WHILE */
    	while (1) {
   
    		if ((HAL_GetTick() - Timer) > 1000) {
    			MAX31855_ReadData(&MAX31855_Handle);
    			if(!MAX31855_GetFault(&MAX31855_Handle))
    			{
    			printf("Temperature: %f\r\nInternal temperature: %f\r\n", MAX31855_GetTemperature(&MAX31855_Handle),MAX31855_GetTemperatureInFahrenheit(&MAX31855_Handle));
    			}
    			Timer = HAL_GetTick();
    		}
    		/* USER CODE END WHILE */
    		/* USER CODE BEGIN 3 */
    	}
     /* USER CODE END 3 */


# SPI Settings:
| Options|   Value|
|-------------|---------------|
|Mode   | Full-Duplex Master  |
| Frame Format | Motorola  |
| Data Size | 8 Bits|
| First Bite | MSB First|
| Clock Polarity (CPOL) | Low|
| Clock Phase (CPHA) | 1 Edge|

### **If using SPI in "Receive only the Master" mode, see this case:** https://github.com/SimpleMethod/STM32-MAX31855/issues/1
### **For using printf with float is needed add -u _printf_float in MCU GCC linker**
