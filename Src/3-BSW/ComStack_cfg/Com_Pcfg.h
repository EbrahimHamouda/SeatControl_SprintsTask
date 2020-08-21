/*
 * Com_Pcfg.h
 *
 * Created: 6/22/2020 6:35:43 AM
 *  Author: ebrah
 */ 


#ifndef COM_PCFG_H_
#define COM_PCFG_H_

#define  NUM_COM_IPDUs			1

#define  NUM_COM_Signls			3

#define  COM_PDU_BUFFER_SIZE	3

typedef enum
{
	ComConf_ComSignal_HeightBtnSignal,
	ComConf_ComSignal_SlideBtnSignal,
	ComConf_ComSignal_InclineBtnSignal,
} E_COM_Signals;

typedef enum
{
	SEAT_BUTTN,
} E_COM_PUDS;

extern const ComSignal_t Butns_ControlSignals[NUM_COM_Signls];

#endif /* COM_PCFG_H_ */