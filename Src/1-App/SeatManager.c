/**
 *
 * \file SeatManager_Template.c
 * \brief Rte Component Template for AUTOSAR SWC: SeatManager
 *
 * \author Sprints AUTOSAR Authoring Tool (SAAT) v1.0.2
 * Generated on 7/21/2020 02:26 PM
 *
 * For any inquiries: ebrahim.hamouda25@gmail.com
 *
 */

#include "Rte_SeatManager.h"

/**
 *
 * static StepMotorStepType
 *
 * Triggered By:
 *  - DataReceivedEventImpl.DRE_rpSeatCtrlBtns_HeightBtnState
 *
 */

 static StepMotorStepType BtnState2MotorState_Mapping(MultiStateBtnType HeightBtnState)
 {
	StepMotorStepType Step;
	
	if(HeightBtnState == MULTI_STATE_BTN_MINUS)
	{
		Step = MOTOR_STEP_MINUS;
	}
	else if(HeightBtnState == MULTI_STATE_BTN_PLUS)
	{
		Step = MOTOR_STEP_PLUS;
	}
	else
	{
		//Error
	}
	return Step;
 }

static StepMotorStepType Sensors2MotorStep_Mapping(SensorPositionType position,SensorWeightType weight)
{
	StepMotorStepType  Step = MOTOR_STEP_MINUS;

	switch (weight)
	{
	case SENSOR_POSITION_CATO_3 :   
		
		if (position < SENSOR_POSITION_STEP_3)
		{
			Step = MOTOR_STEP_PLUS;
		}
		break;
	
	case SENSOR_POSITION_CATO_2 : 
		
		if (position < SENSOR_POSITION_STEP_2)
		{
			Step = MOTOR_STEP_PLUS;
		}
		break;
	case SENSOR_POSITION_CATO_1 : 
		
		if (position < SENSOR_POSITION_STEP_1)
		{
			Step = MOTOR_STEP_PLUS;
		}
		break;
	case SENSOR_POSITION_CATO_0: 
		
		if (position < SENSOR_POSITION_STEP_0)
		{
			Step = MOTOR_STEP_PLUS;
		}
		break;
	default:
		break;
	}

	return Step;
}

/**
 *
 * Runnable SeatManager_SetHeight
 *
 * Triggered By:
 *  - DataReceivedEventImpl.DRE_rpSeatCtrlBtns_HeightBtnState
 *
 */


void SeatManager_SetHeight (void)
{
	Std_ReturnType status;
	StepMotorStepType Step;
	MultiStateBtnType HeightBtnState;
	
	/* Data Receive Points */
	status = Rte_Read_rpSeatCtrlBtns_HeightBtnState(&HeightBtnState);
	
	if (HeightBtnState != MULTI_STATE_BTN_INIT)
	{
		/* Map BtnState to MotorState */
		Step =  BtnState2MotorState_Mapping(HeightBtnState);

		/* Server Call Points */
		status = Rte_Call_rpCtrlMotor_Opr_Move_HeightMotor(Step);
	}
}


/**
 *
 * Runnable SeatManager_SetIncline
 *
 * Triggered By:
 *  - DataReceivedEventImpl.DRE_rpSeatCtrlBtns_InclineBtnState
 *
 */

void SeatManager_SetIncline (void)
{
	Std_ReturnType status;
	MultiStateBtnType InclineBtnState;
	StepMotorStepType Step;

	/* Data Receive Points */
	status = Rte_Read_rpSeatCtrlBtns_InclineBtnState(&InclineBtnState);
	
	if (InclineBtnState != MULTI_STATE_BTN_INIT)
	{	
		/* Map BtnState to MotorState */
		Step =  BtnState2MotorState_Mapping(InclineBtnState);
		
		/* Server Call Points */
	    status = Rte_Call_rpCtrlMotor_Opr_Move_InclineMotor(Step);
	}
	
}


/**
 *
 * Runnable SeatManager_SetSlide
 *
 * Triggered By:
 *  - DataReceivedEventImpl.DRE_rpSeatCtrlBtns_SlideBtnState
 *
 */

void SeatManager_SetSlide (void)
{
	Std_ReturnType status;
	MultiStateBtnType SlideBtnState;
	StepMotorStepType Step;

	/* Data Receive Points */
	status = Rte_Read_rpSeatCtrlBtns_SlideBtnState(&SlideBtnState);
	
	/* Map BtnState to MotorState */
	Step =  BtnState2MotorState_Mapping(SlideBtnState);

	/* Server Call Points */
	if (SlideBtnState != MULTI_STATE_BTN_INIT)
	{
		status = Rte_Call_rpCtrlMotor_Opr_Move_SlideMotor(Step);
	}
}


/**
 *
 * Runnable SeatManager_AutoHeight
 *
 * Triggered By:
 *  - TimingEventImpl.TE_SeatManager_AutoHeight_200ms
 *
 */

void SeatManager_AutoHeight (void)
{
	Std_ReturnType status;
	SensorPositionType position;
	SensorWeightType weight;
	StepMotorStepType Step;

	/* Server Call Points */
	status = Rte_Call_rpPositionSensor_GetPosition_Height(&position);
	status = Rte_Call_rpWeightSensor_GetWeight(&weight);
	
	/* Map sensors to MotorState */
	Step =  Sensors2MotorStep_Mapping(position,weight);

	status = Rte_Call_rpCtrlMotor_Opr_Move_HeightMotor(Step);
	
}


/**
 *
 * Runnable SeatManager_AutoSlide
 *
 * Triggered By:
 *  - TimingEventImpl.TE_SeatManager_AutoSlide_200ms
 *
 */

void SeatManager_AutoSlide (void)
{
	Std_ReturnType status;
	SensorPositionType position;
	SensorWeightType weight;
	StepMotorStepType Step;

	/* Server Call Points */
	status = Rte_Call_rpPositionSensor_GetPosition_Slide(&position);
	status = Rte_Call_rpWeightSensor_GetWeight(&weight);

	/* Map sensors to MotorState */
	Step =  Sensors2MotorStep_Mapping(position,weight);

	status = Rte_Call_rpCtrlMotor_Opr_Move_SlideMotor(Step);
	
}


/**
 *
 * Runnable SeatManager_AutoIncline
 *
 * Triggered By:
 *  - TimingEventImpl.TE_SeatManager_AutoIncline_200ms
 *
 */

void SeatManager_AutoIncline (void)
{
	Std_ReturnType status;
	SensorPositionType position;
	SensorWeightType weight;
	StepMotorStepType Step;

	/* Server Call Points */
	status = Rte_Call_rpPositionSensor_GetPosition_Incline(&position);
	status = Rte_Call_rpWeightSensor_GetWeight(&weight);

	/* Map sensors to MotorState */
	Step =  Sensors2MotorStep_Mapping(position,weight);

	status = Rte_Call_rpCtrlMotor_Opr_Move_InclineMotor(Step);
	
}