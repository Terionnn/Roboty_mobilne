/**
  ******************************************************************************
  * File Name          : I2C.c
  * Description        : This file provides code for the configuration
  *                      of the I2C instances.
  ******************************************************************************
  ** This notice applies to any and all portions of this file
  * that are not between comment pairs USER CODE BEGIN and
  * USER CODE END. Other portions of this file, whether 
  * inserted by the user or by software development tools
  * are owned by their respective copyright owners.
  *
  * COPYRIGHT(c) 2018 STMicroelectronics
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "i2c.h"

#include "gpio.h"

/* USER CODE BEGIN 0 */

/* USER CODE END 0 */


/* I2C1 init function */

/* USER CODE BEGIN 1 */
uint8_t I2C_ReadByte(uint8_t addr, uint8_t reg)
{
	uint8_t data = 0;
	uint8_t d;
	while (HAL_I2C_GetState(&hi2c1) != HAL_I2C_STATE_READY);
	d = HAL_I2C_Master_Transmit(&hi2c1, addr << 1, &reg, 1, 100);
	if ( d != HAL_OK) {
		return d;
	}

	while (HAL_I2C_GetState(&hi2c1) != HAL_I2C_STATE_READY);
	d = HAL_I2C_Master_Receive(&hi2c1, addr << 1, &data, 1, 100);
	if ( d != HAL_OK) {
		return d;
	}
	return data;
}

uint8_t I2C_WriteByte(uint8_t addr, uint8_t reg, uint8_t data)
{
	uint8_t buf[] = {reg, data};
	uint8_t d;
	while (HAL_I2C_GetState(&hi2c1) != HAL_I2C_STATE_READY);
	d = HAL_I2C_Master_Transmit(&hi2c1, addr << 1, buf, 2, 100);
	if ( d != HAL_OK) {
		return d;
	}
	return HAL_OK;
}
/* USER CODE END 1 */

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
