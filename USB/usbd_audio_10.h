/******************************************************************************
 * @file     usbd_audio.h
 * @brief    NuMicro series USB driver header file
 * @date     2017/04/26 09:30 a.m.
 *
 * @note
 * Copyright (C) 2017 Nuvoton Technology Corp. All rights reserved.
 ******************************************************************************/
#ifndef __USBD_UAC_H__
#define __USBD_UAC_H__

#include "demo.h"

#define PLAY_FEATURE_UNITID     0x06

/***************************************************/
/*      Audio Class-Specific Request Codes         */
/***************************************************/
/*!<Define Audio Class Specific Request */
#define UAC_REQUEST_CODE_UNDEFINED  0x00
#define UAC_SET_CUR                 0x01
#define UAC_GET_CUR                 0x81
#define UAC_SET_MIN                 0x02
#define UAC_GET_MIN                 0x82
#define UAC_SET_MAX                 0x03
#define UAC_GET_MAX                 0x83
#define UAC_SET_RES                 0x04
#define UAC_GET_RES                 0x84
#define UAC_SET_MEM                 0x05
#define UAC_GET_MEM                 0x85
#define UAC_GET_STAT                0xFF
#define HID_SET_REPORT              0x09
#define HID_SET_IDLE                0x0A
#define HID_SET_PROTOCOL            0x0B

#define MUTE_CONTROL                0x01
#define VOLUME_CONTROL              0x02
//#define AUTOMATIC_GAIN_CONTROL    0x07



/*-------------------------------------------------------------*/
/* Define EP maximum packet size */
#define CEP_MAX_PKT_SIZE        64
#define EPC_MAX_PKT_SIZE        8

#define CEP_BUF_BASE    0
#define CEP_BUF_LEN     CEP_MAX_PKT_SIZE
#define EPA_BUF_BASE    CEP_BUF_LEN
#define EPA_BUF_LEN 4

#ifdef __HID__
#define EPC_BUF_BASE    (EPA_BUF_BASE + EPA_BUF_LEN)
#define EPC_BUF_LEN     EPC_MAX_PKT_SIZE
#define EPB_BUF_BASE    (EPC_BUF_BASE + EPC_BUF_LEN)
#define EPB_BUF_LEN     (0x800 - CEP_BUF_LEN - EPA_BUF_LEN - EPC_BUF_LEN)
#else
#define EPB_BUF_BASE    (EPA_BUF_BASE + EPA_BUF_LEN)
#define EPB_BUF_LEN     (0x800 - CEP_BUF_LEN - EPA_BUF_LEN)

#endif

/*!<Define HID Class Specific Request */
#define GET_REPORT              0x01
#define GET_IDLE                0x02
#define GET_PROTOCOL            0x03
#define SET_REPORT              0x09
#define SET_IDLE                0x0A
#define SET_PROTOCOL            0x0B

#ifdef __HID__
#ifdef __MEDIAKEY__
#define HID_CTRL_MUTE        0x01
#define HID_CTRL_VOLUME_INC  0x02
#define HID_CTRL_VOLUME_DEC  0x04

#define HID_CTRL_EJECT       0x08
#define HID_CTRL_PLAY        0x01
#define HID_CTRL_STOP        0x02
#define HID_CTRL_PAUSE       0x04
#define HID_CTRL_NEXT        0x08
#define HID_CTRL_PREVIOUS    0x10
#define HID_CTRL_RECORD      0x20
#define HID_CTRL_REWIND      0x40
#define HID_CTRL_FF          0x80
#endif
#endif

#endif  /* __USBD_UAC_H__ */

/*** (C) COPYRIGHT 2017 Nuvoton Technology Corp. ***/
