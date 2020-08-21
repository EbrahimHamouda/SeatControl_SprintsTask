/**
 *
 * \brief Sprints AUTOSAR Master Class - SeatCtrlApp
 * \author Ebrahim Hamouda
 *
 * For any inquiries: ebrahim.hamouda25@gmail.com
 *
 */
 
#ifndef RTE_MAIN_H
#define RTE_MAIN_H

#include "Rte_Type.h"

#define RTE_E_MAX_AGE_EXCEDDED				128

typedef struct
{
	boolean IsUpdated;
	Std_ReturnType Status;
} Rte_DataFlagsType;

typedef struct
{
	Rte_DataFlagsType Height;
	Rte_DataFlagsType Incline;
	Rte_DataFlagsType Slide;
} Rte_SenderReceiverFlagsType;

typedef struct
{
	MultiStateBtnType HeightBtnState;
	MultiStateBtnType InclineBtnState;
	MultiStateBtnType SlideBtnState;
} Rte_SenderReceiverBuffersType;

Std_ReturnType Rte_Start(void);
Std_ReturnType Rte_Stop(void);

#endif