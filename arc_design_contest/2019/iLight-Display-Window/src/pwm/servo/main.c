/* ------------------------------------------
 * Copyright (c) 2017, Synopsys, Inc. All rights reserved.

 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:

 * 1) Redistributions of source code must retain the above copyright notice, this
 * list of conditions and the following disclaimer.

 * 2) Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following disclaimer in the documentation and/or
 * other materials provided with the distribution.

 * 3) Neither the name of the Synopsys, Inc., nor the names of its contributors may
 * be used to endorse or promote products derived from this software without
 * specific prior written permission.

 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
--------------------------------------------- */

/**
 * \defgroup	EMBARC_APP_TMPL		embARC Template Example
 * \ingroup	EMBARC_APPS_TOTAL
 * \ingroup	EMBARC_APPS_BOARD_EMSK
 * \ingroup	EMBARC_APPS_BAREMETAL
 * \brief	embARC Example for template
 *
 * \details
 * ### Extra Required Tools
 *
 * ### Extra Required Peripherals
 *
 * ### Design Concept
 *
 * ### Usage Manual
 *
 * ### Extra Comments
 *
 */

/**
 * \file
 * \ingroup	EMBARC_APP_TMPL
 * \brief	main source of template example
 */

/**
 * \addtogroup	EMBARC_APP_TMPL
 * @{
 */
/* embARC HAL */
#include "embARC.h"
#include "embARC_debug.h"
#include <stdio.h>

#include "Servo.h"

#define IOTDK_PWM_ID		        DW_PWM_TIMER_0_ID
#define IOTDK_PWM_CH_0		        0
#define IOTDK_PWM_CH_1		        1
#define IOTDK_PWM_CH_2		        2
#define IOTDK_PWM_CH_3		        3
#define IOTDK_PWM_CH_4		        4
#define IOTDK_PWM_CH_5		        5
#define IOTDK_PWM_CH_0_PIN			ARDUINO_PIN_3
#define IOTDK_PWM_CH_1_PIN		    ARDUINO_PIN_5
#define IOTDK_PWM_CH_2_PIN		    ARDUINO_PIN_6
#define IOTDK_PWM_CH_3_PIN		    ARDUINO_PIN_9
#define IOTDK_PWM_CH_4_PIN		    ARDUINO_PIN_10
#define IOTDK_PWM_CH_5_PIN		    ARDUINO_PIN_11

/** main entry */
int main(void)
{
	//SERVO_PTR servo;

	attach(ARDUINO_PIN_3, IOTDK_PWM_CH_0);

	for(int deg=0;deg<181;deg=deg+10){
		
		printf("deg=%d\n", deg);
		write(deg);
		
		//detach();
		board_delay_ms(1000,1);
	}
	detach();

	return E_SYS;
}

/** @} */


    