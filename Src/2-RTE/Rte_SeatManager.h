/**
 *
 * \brief Sprints AUTOSAR Master Class - SeatCtrlApp
 * \author Ebrahim Hamouda
 *
 * For any inquiries: ebrahim.hamouda25@gmail.com
 *
 */
 
#ifndef RTE_SEATMANAGER_H
#define RTE_SEATMANAGER_H

#include "Rte_SeatManager_Type.h"

/* RTE APIs Prototype Declaration */
Std_ReturnType Rte_Read_SeatManager_rpSeatCtrlBtns_HeightBtnState(MultiStateBtnType* HeightBtnState);
Std_ReturnType Rte_Read_SeatManager_rpSeatCtrlBtns_InclineBtnState(MultiStateBtnType* InclineBtnState);
Std_ReturnType Rte_Read_SeatManager_rpSeatCtrlBtns_SlideBtnState(MultiStateBtnType* SlideBtnState);
Std_ReturnType Rte_Call_SeatManager_rpHeightMotor_Move(StepMotorStepType Step);
Std_ReturnType Rte_Call_SeatManager_rpInclineMotor_Move(StepMotorStepType Step);
Std_ReturnType Rte_Call_SeatManager_rpSlideMotor_Move(StepMotorStepType Step);
Std_ReturnType Rte_Call_SeatManager_rpHeightSensor_GetPosition(SensorPositionType* Position);
Std_ReturnType Rte_Call_SeatManager_rpSlideSensor_GetPosition(SensorPositionType* Position);
Std_ReturnType Rte_Call_SeatManager_rpInclineSensor_GetPosition(SensorPositionType* Position);
Std_ReturnType Rte_Call_SeatManager_rpWeightSensor_GetWeight(SensorWeightType* Weight);

#define Rte_Read_rpSeatCtrlBtns_HeightBtnState		  Rte_Read_SeatManager_rpSeatCtrlBtns_HeightBtnState
#define Rte_Read_rpSeatCtrlBtns_InclineBtnState		  Rte_Read_SeatManager_rpSeatCtrlBtns_InclineBtnState
#define Rte_Read_rpSeatCtrlBtns_SlideBtnState		  Rte_Read_SeatManager_rpSeatCtrlBtns_SlideBtnState
#define Rte_Call_rpCtrlMotor_Opr_Move_HeightMotor	  Rte_Call_SeatManager_rpHeightMotor_Move
#define Rte_Call_rpCtrlMotor_Opr_Move_InclineMotor    Rte_Call_SeatManager_rpInclineMotor_Move
#define Rte_Call_rpCtrlMotor_Opr_Move_SlideMotor      Rte_Call_SeatManager_rpSlideMotor_Move
#define Rte_Call_rpPositionSensor_GetPosition_Height  Rte_Call_SeatManager_rpHeightSensor_GetPosition
#define Rte_Call_rpPositionSensor_GetPosition_Slide   Rte_Call_SeatManager_rpSlideSensor_GetPosition
#define Rte_Call_rpPositionSensor_GetPosition_Incline Rte_Call_SeatManager_rpInclineSensor_GetPosition
#define Rte_Call_rpWeightSensor_GetWeight			  Rte_Call_SeatManager_rpWeightSensor_GetWeight

/* Runnables Prototype Declaration */
void SeatManager_SetHeight(void);
void SeatManager_SetIncline(void);
void SeatManager_SetSlide(void);
void SeatManager_AutoHeight(void);
void SeatManager_AutoSlide(void);
void SeatManager_AutoIncline(void);

#endif