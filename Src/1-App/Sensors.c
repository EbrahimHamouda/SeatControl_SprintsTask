/**
 *
 * \file Sensors_Template.c
 * \brief Rte Component Template for AUTOSAR SWC: Sensors
 *
 * \author Sprints AUTOSAR Authoring Tool (SAAT) v1.0.2
 * Generated on 7/21/2020 08:58 PM
 *
 * For any inquiries: ebrahim.hamouda25@gmail.com
 *
 */

#include "Rte_Sensors.h"


static SensorPositionType Io_position2AppPoition_Mapping(IoPositionSensorReadingType Io_position)
{
	SensorPositionType ret_val;
	if (Io_position == 0)
	{
		ret_val = SENSOR_POSITION_STEP_0;
	}
	else if ((Io_position > 0) && (Io_position <= 64))
	{
		ret_val = SENSOR_POSITION_STEP_1;
	}
	else if ((Io_position > 64) && (Io_position <= 192))
	{
		ret_val = SENSOR_POSITION_STEP_2;
	}
	else if ((Io_position > 192) && (Io_position <= 255))
	{
		ret_val = SENSOR_POSITION_STEP_3;
	}
	else
	{
		// ERROR
	}
	return ret_val;
}

static SensorWeightType Io_Weight2AppWeight_Mapping(IoWeightSensorReadingType IO_weight)
{
	SensorWeightType ret_val;
	if (IO_weight < 60)
	{
		ret_val = SENSOR_POSITION_CATO_0;
	}
	else if ((IO_weight > 60) && (IO_weight <= 80))
	{
		ret_val = SENSOR_POSITION_CATO_1;
	}
	else if ((IO_weight > 80) && (IO_weight <= 100))
	{
		ret_val = SENSOR_POSITION_CATO_2;
	}
	else if ((IO_weight > 100) && (IO_weight <= 255))
	{
		ret_val = SENSOR_POSITION_CATO_3;
	}
	else
	{
		// ERROR
	}
	return ret_val;
}

/**
 *
 * Runnable HeightSensor_GetPosition
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppPositionSensor_GetPosition_Height
 *
 */

void HeightSensor_GetPosition (SensorPositionType* position)
{
	IoPositionSensorReadingType Io_position;

	/* Server Call Points */
	Rte_Call_rpIoGetPoisition_IOGet_Height(&Io_position);

	/* Mapping Raw poisition to Physical poisition */
	*position = Io_position2AppPoition_Mapping(Io_position);
}


/**
 *
 * Runnable InclineSensor_GetPosition
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppPositionSensor_GetPosition_Incline
 *
 */

void InclineSensor_GetPosition (SensorPositionType* position)
{
	IoPositionSensorReadingType Io_position;

	/* Server Call Points */
	Rte_Call_rpIoGetPoisition_IOGet_Incline(&Io_position);
	
	/* Mapping Raw poisition to Physical poisition */
	*position = Io_position2AppPoition_Mapping(Io_position);
}


/**
 *
 * Runnable SlideSensor_GetPosition
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppPositionSensor_GetPosition_Slide
 *
 */

void SlideSensor_GetPosition (SensorPositionType* position)
{
	IoPositionSensorReadingType Io_position;

	/* Server Call Points */
	Rte_Call_rpIoGetPoisition_IOGet_Slide(&Io_position);
	
	/* Mapping Raw poisition to Physical poisition */
	*position = Io_position2AppPoition_Mapping(Io_position);
}


/**
 *
 * Runnable WeightSensor_GetWeight
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppWeightSensor_GetWeight
 *
 */

void WeightSensor_GetWeight (SensorWeightType* weight)
{
	IoWeightSensorReadingType IO_weight;

	/* Server Call Points */
	Rte_Call_rpIoGetWeight_GetWeight(&IO_weight);
	
	/* Mapping Raw weight to Physical weight */
	*weight = Io_Weight2AppWeight_Mapping(IO_weight);
}

