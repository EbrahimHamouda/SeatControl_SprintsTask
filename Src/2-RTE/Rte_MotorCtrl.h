/**
 *
 * \brief Sprints AUTOSAR Master Class - SeatCtrlApp
 * \author Ebrahim Hamouda
 *
 * For any inquiries: ebrahim.hamouda25@gmail.com
 *
 */
 
#ifndef RTE_HEIGHTMOTOR_H
#define RTE_HEIGHTMOTOR_H


#include "Rte_MotorCtrl_Type.h"

/* RTE APIs Prototype Declaration */
Std_ReturnType Rte_Call_HeightMotor_rpIOSetHeight_IOSetForward();
Std_ReturnType Rte_Call_HeightMotor_rpIOSetHeight_IOSetReverse();

Std_ReturnType Rte_Call_SlideMotor_rpIOSetSlide_IOSetForward();
Std_ReturnType Rte_Call_SlideMotor_rpIOSetSlide_IOSetReverse();

Std_ReturnType Rte_Call_InclineMotor_rpIOSetIncline_IOSetForward();
Std_ReturnType Rte_Call_InclineMotor_rpIOSetIncline_IOSetReverse();

#define Rte_Call_rpIoSetMotor_IOSetForward_Height 	    	Rte_Call_HeightMotor_rpIOSetHeight_IOSetForward
#define Rte_Call_rpIoSetMotor_IOSetReverse_Height 		    Rte_Call_HeightMotor_rpIOSetHeight_IOSetReverse

#define Rte_Call_rpIoSetMotor_IOSetForward_Slide 			Rte_Call_SlideMotor_rpIOSetSlide_IOSetForward
#define Rte_Call_rpIoSetMotor_IOSetReverse_Slide 			Rte_Call_SlideMotor_rpIOSetSlide_IOSetReverse

#define Rte_Call_rpIoSetMotor_IOSetForward_Incline    		Rte_Call_InclineMotor_rpIOSetIncline_IOSetForward
#define Rte_Call_rpIoSetMotor_IOSetReverse_Incline    		Rte_Call_InclineMotor_rpIOSetIncline_IOSetReverse

/* Runnables Prototype Declaration */
void HeightMotor_Move(StepMotorStepType Step);
void SlideMotor_Move(StepMotorStepType Step);
void InclineMotor_Move(StepMotorStepType Step);


#endif