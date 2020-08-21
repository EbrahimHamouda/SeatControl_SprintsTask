/**
 *
 * \brief Sprints AUTOSAR Master Class - SeatCtrlApp
 * \author Ebrahim Hamouda
 *
 * For any inquiries: ebrahim.hamouda25@gmail.com
 *
 */
 
#ifndef RTE_HEIGHTSENSOR_H
#define RTE_HEIGHTSENSOR_H

#include "Rte_Sensors_Type.h"

/* RTE APIs Prototype Declaration */
Std_ReturnType Rte_Call_HeightSensor_rpIOGetHeight_IOGet(IoPositionSensorReadingType* position);
Std_ReturnType Rte_Call_SlideSensor_rpIOGetSlide_IOGet(IoPositionSensorReadingType* position);
Std_ReturnType Rte_Call_InclineSensor_rpIOGetIncline_IOGet(IoPositionSensorReadingType* position);
Std_ReturnType Rte_Call_WeightSensor_rpIOGetWeight_IOGet(IoWeightSensorReadingType* weight);


#define Rte_Call_rpIoGetPoisition_IOGet_Height 				Rte_Call_HeightSensor_rpIOGetHeight_IOGet
#define Rte_Call_rpIoGetPoisition_IOGet_Incline 			Rte_Call_SlideSensor_rpIOGetSlide_IOGet
#define Rte_Call_rpIoGetPoisition_IOGet_Slide 				Rte_Call_InclineSensor_rpIOGetIncline_IOGet
#define Rte_Call_rpIoGetWeight_GetWeight 				    Rte_Call_WeightSensor_rpIOGetWeight_IOGet

/* Runnables Prototype Declaration */
void HeightSensor_GetPosition(SensorPositionType* Position);
void SlideSensor_GetPosition(SensorPositionType* Position);
void InclineSensor_GetPosition(SensorPositionType* Position);
void WeightSensor_GetWeight(SensorWeightType* Weight);

#endif