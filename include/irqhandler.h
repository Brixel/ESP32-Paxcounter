#ifndef _IRQHANDLER_H
#define _IRQHANDLER_H

#define DISPLAY_IRQ 0x01
#define BUTTON_IRQ 0x02
#define MATRIX_DISPLAY_IRQ 0x03
#define SENDCYCLE_IRQ 0x04
#define CYCLIC_IRQ 0x08
#define TIMESYNC_IRQ 0x10
#define MASK_IRQ 0x20
#define UNMASK_IRQ 0x40
#define GPS_IRQ 0x80

#include "globals.h"
#include "cyclic.h"
#include "senddata.h"
#include "timekeeper.h"

void irqHandler(void *pvParameters);
int mask_user_IRQ();
int unmask_user_IRQ();

#ifdef HAS_DISPLAY
void IRAM_ATTR DisplayIRQ();
#endif

#ifdef HAS_MATRIX_DISPLAY
void IRAM_ATTR MatrixDisplayIRQ();
#endif

#ifdef HAS_BUTTON
void IRAM_ATTR ButtonIRQ();
#endif

#if (HAS_GPS)
void IRAM_ATTR GpsIRQ();
#endif

#endif