/**
 *
 * \file MotorCtrl_Template.c
 * \brief Rte Component Template for AUTOSAR SWC: MotorCtrl
 *
 * \author Sprints AUTOSAR Authoring Tool (SAAT) v1.0.2
 * Generated on 7/21/2020 08:31 PM
 *
 * For any inquiries: ebrahim.hamouda25@gmail.com
 *
 */

#include "Rte_MotorCtrl.h"


/**
 *
 * Runnable HeightMotor_Move
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppCtrlMotor_Opr_Move_HeightMotor
 *
 */

void HeightMotor_Move (StepMotorStepType Step)
{
	Std_ReturnType status;

	/* Server Call Points */
	if (Step == MOTOR_STEP_PLUS)
	{
		status = Rte_Call_rpIoSetMotor_IOSetForward_Height();
	}
	else if (Step == MOTOR_STEP_MINUS)
	{
		status = Rte_Call_rpIoSetMotor_IOSetReverse_Height();
	}
	else
	{
		//ERROR
	}
}


/**
 *
 * Runnable InclineMotor_Move
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppCtrlMotor_Opr_Move_InclineMotor
 *
 */

void InclineMotor_Move (StepMotorStepType Step)
{
	Std_ReturnType status;

	/* Server Call Points */
	if (Step == MOTOR_STEP_PLUS)
	{
		status = Rte_Call_rpIoSetMotor_IOSetForward_Incline();
	}
	else if (Step == MOTOR_STEP_MINUS)
	{
		status = Rte_Call_rpIoSetMotor_IOSetReverse_Incline();
	}
	else
	{
		//ERROR
	}
}


/**
 *
 * Runnable SlideMotor_Move
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppCtrlMotor_Opr_Move_SlideMotor
 *
 */

void SlideMotor_Move (StepMotorStepType Step)
{
	Std_ReturnType status;

	/* Server Call Points */
	if (Step == MOTOR_STEP_PLUS)
	{
		status = Rte_Call_rpIoSetMotor_IOSetForward_Slide();
	}
	else if (Step == MOTOR_STEP_MINUS)
	{
		status = Rte_Call_rpIoSetMotor_IOSetReverse_Slide();
	}
	else
	{
		//ERROR
	}
}

