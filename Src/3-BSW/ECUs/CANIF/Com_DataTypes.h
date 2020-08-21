/*
 * Com_DataTypes.h
 *
 * Created: 6/17/2020 4:48:39 PM
 *  Author: ebrah
 */ 


#ifndef CAN_DATATYPES_H_
#define CAN_DATATYPES_H_
#include "common.h"

typedef void (*User_CanRxIndiction_t)(uint8,uint8*);
typedef void (*Com_UserComRxIndiction_t)(void);
typedef enum
{
	RX,
	TX
} PduType_t;

typedef struct
{
	uint8 Message_Id;
	uint8 Data[8];
} Can_Frame_t;

typedef struct
{
	uint8 Pdu_Id; 
	PduType_t PduType;
	uint8 Message_ID;
	uint8 Mask;
	User_CanRxIndiction_t User_CanRxIndiction; // For Rx
} HOH_CfgType;

typedef struct
{
	uint8 ComHandleId;
	uint8 ComIPduHandleId;
	uint8* ComPduBuffer;
	uint8 ComBytePoistion;
	uint8 ComByteSize;
	Com_UserComRxIndiction_t Com_UserRxIndiction;
} ComSignal_t;


#endif /* CAN_DATATYPES_H_ */