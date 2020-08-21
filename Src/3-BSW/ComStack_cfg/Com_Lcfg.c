/*
 * Com_Lcfg.c
 *
 * Created: 6/22/2020 6:35:24 AM
 *  Author: ebrah
 */
#include "Com_DataTypes.h"
#include "Com_Pcfg.h"
#include "Rte_Cbk.h"

static uint8 Com_Buffer[NUM_COM_IPDUs][COM_PDU_BUFFER_SIZE]; 

const ComSignal_t Butns_ControlSignals[NUM_COM_Signls] =
{
	{
		ComConf_ComSignal_HeightBtnSignal,
		SEAT_BUTTN,
		&Com_Buffer[0],
		0,
		1,
		Rte_ComCbk_HeightBtnSignal
	},
	{
		ComConf_ComSignal_SlideBtnSignal,
		SEAT_BUTTN,
		&Com_Buffer[0],
		1,
		1,
		Rte_ComCbk_SlideBtnSignal
	},
	{
		ComConf_ComSignal_InclineBtnSignal,
		SEAT_BUTTN,
		&Com_Buffer[0],
		2,
		1,
		Rte_ComCbk_InclineBtnSignal
	}
};


