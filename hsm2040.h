/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef _HSM2040_H_
#define _HSM2040_H_

#include "ccid.h"

#define USB_REQ_CCID        0xA1

extern const uint8_t historical_bytes[];

#define DEBUG_PAYLOAD(p,s) { \
    TU_LOG3("Payload %s (%d bytes):\r\n", #p,s);\
    for (int i = 0; i < s; i += 16) {\
        for (int j = 0; j < 16; j++) {\
            if (j < s-i) TU_LOG3("%02X ",p[i+j]);\
            else TU_LOG3("   ");\
            if (j == 7) TU_LOG3(" ");\
            } TU_LOG3(":  "); \
        for (int j = 0; j < MIN(16,s-i); j++) {\
            TU_LOG3("%c",p[i+j]);\
            if (j == 7) TU_LOG3(" ");\
            }\
            TU_LOG3("\r\n");\
        } TU_LOG3("\r\n"); \
    }


#endif