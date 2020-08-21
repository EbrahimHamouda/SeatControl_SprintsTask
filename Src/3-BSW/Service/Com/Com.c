/*
* Com.c
*
* Created: 6/22/2020 1:28:09 AM
*  Author: ebrah
*/

#include "Com.h"
#include "Com_Pcfg.h"
#include <math.h>
#include "CANIF.h"

static ComSignal_t *temp_SignalCfg = Butns_ControlSignals;

void Com_SendSignal(uint8 SignalId,uint8* Data)
{
	/**/
	uint8 Pdu_Id			   = temp_SignalCfg[SignalId].ComIPduHandleId;
	uint8* Pdu_buffer		   = temp_SignalCfg[SignalId].ComPduBuffer;
	uint8 temp_ComBytePoistion = temp_SignalCfg[SignalId].ComBytePoistion;
	
	/*TODO Loop to cpy the whole size*/
	Pdu_buffer[temp_ComBytePoistion] = *Data;
	
	CanIf_Write(Pdu_Id,Pdu_buffer,3);
}

void Com_RxIndication(uint8 PduId,uint8* Dataptr)
{
	uint8  temp_ComBytePoistion;
	uint8* temp_ComPduBuffer;
	uint8 i;
	for(i=0; i< NUM_COM_Signls; i++)
	{
		uint8 temp_ComBytePoistion = temp_SignalCfg[i].ComBytePoistion;
		uint8* temp_ComPduBuffer    = temp_SignalCfg[i].ComPduBuffer;
		Com_UserComRxIndiction_t Rte_user = temp_SignalCfg[i].Com_UserRxIndiction;
		
		/*TODO Loop to cpy the whole size*/
		temp_ComPduBuffer[temp_ComBytePoistion] = Dataptr[temp_ComBytePoistion];
		
		// Call Signal Rte_User 
		Rte_user();
	}
}

void Com_ReceiveSignal(uint8 Signa_Id, void* _buffer)
{
	uint8* Pdu_buffer		   = temp_SignalCfg[Signa_Id].ComPduBuffer;
	uint8 temp_ComBytePoistion = temp_SignalCfg[Signa_Id].ComBytePoistion;
	
	/*TODO Loop to cpy the whole size*/
	*((uint8*)_buffer) =Pdu_buffer[temp_ComBytePoistion];
}