/**
 *
 * \file HMI_Template.c
 * \brief Rte Component Template for AUTOSAR SWC: HMI
 *
 * \author Sprints AUTOSAR Authoring Tool (SAAT) v1.0.2
 * Generated on 7/12/2020 08:02 PM
 *
 * For any inquiries: ebrahim.hamouda25@gmail.com
 *
 */

#include "Rte_HMI.h"


static MultiStateBtnType Raw2Physical(uint8 BtnState)
{
	MultiStateBtnType ret_val;
	if(BtnState == 0) 
	{
		ret_val = MULTI_STATE_BTN_INIT;
	}
	if(BtnState == 1) 
	{		
		ret_val = MULTI_STATE_BTN_MINUS;
	}
	if(BtnState == 2) 
	{
		ret_val = MULTI_STATE_BTN_PLUS;
	}
	return ret_val;
}

/**
 *
 * Runnable HMI_MainFunction
 *
 * Triggered By:
 *  - TimingEventImpl.TE_HMI_MainFunction_100ms
 *
 */


void HMI_MainFunction (void)
{
	Std_ReturnType status;
	MultiStateBtnType HeightBtnState;
	MultiStateBtnType InclineBtnState;
	MultiStateBtnType SlideBtnState;
	uint8 Slide;
	uint8 Height;
	uint8 Incline;
	
	
	/* Data Receive Points */
	if(Rte_IsUpdated_rpSeatCtrlData_Height() == E_OK)
	{
		Rte_Read_rpSeatCtrlData_Height(&Height);
		HeightBtnState = Raw2Physical(Height);
		status = Rte_Write_ppSeatCtrlBtns_HeightBtnState(HeightBtnState);
	}
	else
	{
		/* code */
	}
	
	if(Rte_IsUpdated_rpSeatCtrlData_Slide() == E_OK)
	{
		status = Rte_Read_rpSeatCtrlData_Slide(&Slide);
		SlideBtnState = Raw2Physical(Slide);
		status = Rte_Write_ppSeatCtrlBtns_SlideBtnState(SlideBtnState);

	}
	else
	{
		
	}
	
	if(Rte_IsUpdated_rpSeatCtrlData_Incline() == E_OK)
	{
		status = Rte_Read_rpSeatCtrlData_Incline(&Incline);
		InclineBtnState = Raw2Physical(Incline);
		status = Rte_Write_ppSeatCtrlBtns_InclineBtnState(InclineBtnState);
	}
	else
	{
		
	}
	
}

