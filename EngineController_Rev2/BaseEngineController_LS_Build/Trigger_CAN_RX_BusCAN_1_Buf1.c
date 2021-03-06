/*
 * Trigger_CAN_RX_BusCAN_1_Buf1.c
 *
 */

/*---- INCLUDE FILES --------------------------------------------------------------------------------------*/
#include "Application.h"
#include "BaseEngineController_LS.h"
#include "BaseEngineController_LS_private.h"

/*---- CODE SPACE -----------------------------------------------------------------------------------------*/
#include <Pragma_Section_Start_text_code.h>
#include <Pragma_Section_End_data.h>
#include <Pragma_Section_End_bss.h>

/*
   Bus: CAN_1 (std)




   Masked IDs: CAN_1 (std)


   masked_id = 0x00000181
   masked_id = 0x00000180

   Masks: CAN_1 (std)
   computed mask = 0x000007FE
   computed id   = 0x00000180

 */

/*---------------------------------------------------------------*/
MHCAN_directslot MHCAN_directslot_RxSlot_8118p0005 = { 0 };

static boolean_T MHCAN_handler_RxSlot_8118p0005(S_CANMessage *messageObj)
{
  if ((messageObj->u4MessageID & 0x000007FF) == 0x00000181) {
    messageObj->u1Length = messageObj->u1Length > 8 ? 8 : messageObj->u1Length;

    {
      boolean_T new_message;
      new_message = !MHCAN_directslot_RxSlot_8118p0005.ready;
      MHCAN_directslot_RxSlot_8118p0005.message = *messageObj;
      MHCAN_directslot_RxSlot_8118p0005.ready = 1;
    }

    return 1;
  }

  return 0;
}

MHCAN_directslot MHCAN_directslot_RxSlot_8117p0006 = { 0 };

static boolean_T MHCAN_handler_RxSlot_8117p0006(S_CANMessage *messageObj)
{
  if ((messageObj->u4MessageID & 0x000007FF) == 0x00000180) {
    messageObj->u1Length = messageObj->u1Length > 8 ? 8 : messageObj->u1Length;

    {
      boolean_T new_message;
      new_message = !MHCAN_directslot_RxSlot_8117p0006.ready;
      MHCAN_directslot_RxSlot_8117p0006.message = *messageObj;
      MHCAN_directslot_RxSlot_8117p0006.ready = 1;
    }

    return 1;
  }

  return 0;
}

static const MHCAN_id_dispatcher_T MHCAN_consumers_0x000007FF[] = {
  { 0x00000181, MHCAN_handler_RxSlot_8118p0005 },

  { 0x00000180, MHCAN_handler_RxSlot_8117p0006 },
};

static const MHCAN_mask_dispatcher_T masks[] = {
  { 0x000007FF, 2, 0, (MHCAN_id_dispatcher_T *) MHCAN_consumers_0x000007FF },
};

/*---------------------------------------------------------------*/
void Trigger_CAN_RX_BusCAN_1_Buf1(E_TouCANNotificationEventMask in_EventMask,
  TouCANBufferHandle in_BufferHandle, NativePtrSizedInt_U in_uAppSuppliedData)
{
  S_CANMessage messageObj;
  NativeError_S sErrorResult;
  unsigned char idx;
  uint32_T maskidx;
  boolean_T handled;
  do {
    handled = 0;
    sErrorResult = SynchReadFromTouCAN(RES_CAN1, TOUCAN_BUFF1, &messageObj, 0);
    if (SUCCESS(sErrorResult)) {
      for (maskidx=0; maskidx < 1; maskidx++) {
        uint32_T ididx;
        if (!masks[maskidx].optimized_dispatcher) {
          for (ididx=0; ididx < masks[maskidx].consumer_count; ididx++) {
            if (masks[maskidx].consumer_list[ididx].consumer(&messageObj)) {
              handled = 1;
            }
          }
        } else {
          if (masks[maskidx].optimized_dispatcher(masks[maskidx].mask,
               masks[maskidx].consumer_list, &messageObj)) {
            handled = 1;
          }
        }
      }

      (CAN_1_std_receive_count_DataStore())++;
      if (handled) {
        (CAN_1_std_handled_count_DataStore())++;
      } else {
        (CAN_1_std_last_unhandled_id_DataStore()) = messageObj.u4MessageID;
      }

      if (sErrorResult == SUCCESS_Q_EMPTY)
        return;
    }
  } while (SUCCESS(sErrorResult));
}

/*---- END OF FILE -----------------------------------------------------------------------------------------*/
