/*
 * CAN_Lcfg.c
 *
 * Created: 6/15/2020 12:01:23 PM
 *  Author: ebrah
 */ 
#include "CanIf_Pcfg.h"
#include "Com_DataTypes.h"
#include "Com.h"

HOH_CfgType HOHs_2_PDUs_Arr[NUM_PDU] =
{
		{
			0,
			RX,
			0xF0,
			0xFF,
			Com_RxIndication
		}
};