/**
 *
 * \file IoHwAbs_Template.c
 * \brief Rte Component Template for AUTOSAR SWC: IoHwAbs
 *
 * \author Sprints AUTOSAR Authoring Tool (SAAT) v1.0.2
 * Generated on 7/21/2020 08:31 PM
 *
 * For any inquiries: ebrahim.hamouda25@gmail.com
 *
 */

#include "Rte_IoHwAbs.h"
#include "Adc.h"
#include "pwm.h"



/*
* Private Data
*/
typedef struct 
{
	uint8 Height_position;
	uint8 Slide_position;
	uint8 Incline_position;
} Io_PositionStruct_type;

Io_PositionStruct_type Io_PositionStruct =
{
	14,
	14,
	14
};



/**
 *
 * Runnable IoHwAbs_ECUGet_Height
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppIoGetPosition_IOGet_Height
 *
 */

void IoHwAbs_ECUGet_Height (IoPositionSensorReadingType* position)
{
	/* Read Poisition Sensor 
	*  Work around read instead angel of stepper motor 
	*/
	*position = Io_PositionStruct.Height_position;
}


/**
 *
 * Runnable IoHwAbs_ECUGet_Incline
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppIoGetPosition_IOGet_Incline
 *
 */

void IoHwAbs_ECUGet_Incline (IoPositionSensorReadingType* position)
{
	/* Read Poisition Sensor 
	*  Work around read instead angel of stepper motor 
	*/
	*position = Io_PositionStruct.Incline_position;
}


/**
 *
 * Runnable IoHwAbs_ECUGet_Slide
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppIoGetPosition_IOGet_Slide
 *
 */

void IoHwAbs_ECUGet_Slide (IoPositionSensorReadingType* position)
{
	/* Read Poisition Sensor 
	*  Work around read instead angel of stepper motor 
	*/
	*position = Io_PositionStruct.Slide_position;
}


/**
 *
 * Runnable IoHwAbs_ECUGet_Weight
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppIoGetWeight_IOGet_Weight
 *
 */

void IoHwAbs_ECUGet_Weight (IoWeightSensorReadingType* weight)
{
	/* Read weight POT-HG	*/
	*weight = adc_read(0);
}


/**
 *
 * Runnable IoHwAbs_ECUSetForward_Height
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppIoSetMotor_IOSetForward_Height
 *
 */

void IoHwAbs_ECUSetForward_Height (void)
{
	/*Change Position */
	if (Io_PositionStruct.Height_position < 32)
	{	
		pwm_generate(D7,(++Io_PositionStruct.Height_position));
	}
}


/**
 *
 * Runnable IoHwAbs_ECUSetForward_Incline
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppIoSetMotor_IOSetForward_Incline
 *
 */

void IoHwAbs_ECUSetForward_Incline (void)
{
	/*Change Position */
	if (Io_PositionStruct.Incline_position < 32)
	{	
		pwm_generate(D5,(++Io_PositionStruct.Incline_position));
	}
}


/**
 *
 * Runnable IoHwAbs_ECUSetForward_Slide
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppIoSetMotor_IOSetForward_Slide
 *
 */

void IoHwAbs_ECUSetForward_Slide (void)
{
	/*Change Poisition */
	if (Io_PositionStruct.Slide_position < 32)
	{	
		pwm_generate(D4,(++Io_PositionStruct.Slide_position));
	}
}


/**
 *
 * Runnable IoHwAbs_ECUSetReverse_Height
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppIoSetMotor_IOSetReverse_Height
 *
 */

void IoHwAbs_ECUSetReverse_Height (void)
{
	/*Change Poisition */
	if (Io_PositionStruct.Height_position > 14)
	{	
		pwm_generate(D7,(--Io_PositionStruct.Height_position));
	}
}


/**
 *
 * Runnable IoHwAbs_ECUSetReverse_Incline
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppIoSetMotor_IOSetReverse_Incline
 *
 */

void IoHwAbs_ECUSetReverse_Incline (void)
{
	/*Change Poisition */
	if (Io_PositionStruct.Incline_position > 14)
	{	
		pwm_generate(D5,(--Io_PositionStruct.Incline_position));
	}
}


/**
 *
 * Runnable IoHwAbs_ECUSetReverse_Slide
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppIoSetMotor_IOSetReverse_Slide
 *
 */

void IoHwAbs_ECUSetReverse_Slide (void)
{
	Std_ReturnType status;
	/*Change Poisition */
	if (Io_PositionStruct.Slide_position > 14)
	{	
		pwm_generate(D4,(--Io_PositionStruct.Slide_position));
	}
}

