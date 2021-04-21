//-----------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------
#include <SI_EFM8BB3_Register_Enums.h>                // SFR declarations
#include "../inc/InitDevice.h"
#include "../inc/SMBus_MasterMultibyte.h"
#include "../inc/SSD1306.h"

//#pragma userclass (xdata = flash)

xdata uint8_t sdat[1024] = {0x0, 0x0, 0xc0, 0xf0, 0xf8, 0x1c, 0xc, 0x4, 0x4, 0x4, 0x1c, 0xf8, 0xf0, 0xc0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x8, 0x8, 0xfc, 0xfc, 0xfc, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x60, 0x30, 0x18, 0xc, 0xc, 0xc, 0x1c, 0x3c, 0xf8, 0xf8, 0xe0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x20, 0x30, 0x18, 0xc, 0xc, 0xc, 0xc, 0x1c, 0xf8, 0xf8, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x80, 0xe0, 0x30, 0xf8, 0xfc, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x80, 0xe0, 0xfc, 0x8c, 0x8c, 0x8c, 0xc, 0xc, 0xc, 0xc, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x80, 0xc0, 0xe0, 0x70, 0x38, 0x18, 0xc, 0xc, 0x4, 0x4, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x38, 0x1c, 0xc, 0xc, 0xc, 0xc, 0xc, 0xc, 0xcc, 0xfc, 0x7c, 0x4, 0x0, 0x0, 0x0, 0xff, 0xff, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xf7, 0xff, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xff, 0xff, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x80, 0xc0, 0x60, 0x38, 0x1f, 0xf, 0x3, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x8, 0xc, 0xe, 0x1f, 0x3d, 0xf8, 0xf0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xe0, 0xd8, 0xcc, 0xc3, 0xc1, 0xc0, 0xc0, 0xff, 0xff, 0xc0, 0xc0, 0xc0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x1, 0x3, 0x3, 0x3, 0x7, 0xf, 0x1f, 0xfe, 0xf8, 0x0, 0x0, 0x0, 0x0, 0x0, 0xfe, 0xff, 0xff, 0x7, 0x6, 0x2, 0x2, 0x6, 0xe, 0xfe, 0xfc, 0xf8, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x80, 0xf0, 0xfe, 0x1f, 0x3, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x7, 0xf, 0x1c, 0x10, 0x10, 0x10, 0x10, 0x1c, 0xf, 0x7, 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x10, 0x10, 0x1f, 0x1f, 0x1f, 0x10, 0x10, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x10, 0x18, 0x1c, 0x1a, 0x19, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x0, 0x0, 0x0, 0x0, 0x0, 0x8, 0x1c, 0x18, 0x18, 0x10, 0x10, 0x10, 0x8, 0xc, 0x7, 0x3, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1f, 0x1f, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1c, 0x1c, 0x1c, 0x18, 0x10, 0x10, 0x18, 0x8, 0xe, 0x7, 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x7, 0xf, 0x1c, 0x18, 0x10, 0x10, 0x10, 0x18, 0xf, 0x7, 0x3, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1c, 0x1f, 0x7, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xf8, 0xfc, 0xc6, 0x82, 0x2, 0x2, 0x2, 0xce, 0xfc, 0x78, 0x0, 0x0, 0x0, 0x0, 0x0, 0xf0, 0xf8, 0xfc, 0x6, 0x2, 0x2, 0x2, 0x6, 0xc, 0xfc, 0xf8, 0xe0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x80, 0xe0, 0xf1, 0x1b, 0x7, 0x7, 0xf, 0x1f, 0x3d, 0xf8, 0xf0, 0xc0, 0x0, 0x0, 0x0, 0x0, 0x3, 0x7, 0xf, 0xc, 0xc, 0x8, 0x8, 0xc8, 0xfc, 0xff, 0x7f, 0xf, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x3, 0x7, 0xe, 0x8, 0x8, 0x8, 0x8, 0xc, 0x7, 0x3, 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x8, 0x8, 0xc, 0xc, 0x6, 0x7, 0x3, 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xe, 0xe, 0xe, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};

uint8_t SMB_DATA_IN[NUM_BYTES_RD];

int NUM_BYTES_WR = 6;

// Global holder for SMBus data.
// All transmit data is read from herexdata uint8_t sdat[1024] = {0x1, 0x0, 0xe0, 0xf0, 0xf8, 0x7c, 0xc, 0x4, 0x4, 0xc, 0x3c, 0xf8, 0xf8, 0xc0, 0x0, 0x1, 0x0, 0x0, 0x18, 0x18, 0xfc, 0xfc, 0xfe, 0xfe, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x0, 0x60, 0x78, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x3c, 0xfc, 0xf8, 0xf0, 0xc0, 0x0, 0x1, 0x0, 0x70, 0x38, 0x1c, 0xc, 0xc, 0xc, 0x1c, 0xfc, 0xfc, 0xf8, 0x70, 0x0, 0x0, 0x1, 0x0, 0x0, 0x0, 0x0, 0x80, 0xc0, 0xe0, 0x78, 0xfc, 0xfc, 0xfc, 0x0, 0x0, 0x0, 0x1, 0x0, 0x0, 0xc0, 0xf8, 0xfc, 0xdc, 0x9c, 0x9c, 0x9c, 0x1c, 0x1c, 0xe, 0x6, 0x0, 0x1, 0x0, 0x0, 0xc0, 0xe0, 0xf0, 0xf0, 0x78, 0x18, 0x1c, 0xc, 0x4, 0x4, 0x4, 0x0, 0x1, 0x0, 0x60, 0x7c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0xfc, 0xfc, 0xfc, 0x1c, 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xff, 0xff, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xff, 0xff, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xff, 0xff, 0xff, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x80, 0xc0, 0xf0, 0x7c, 0x1f, 0xf, 0x7, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x8, 0xc, 0xc, 0xe, 0x1f, 0xff, 0xfd, 0xf8, 0xe0, 0x0, 0x0, 0x0, 0xe0, 0xf8, 0xce, 0xc7, 0xc3, 0xc0, 0xc0, 0xff, 0xff, 0xff, 0xc0, 0xc0, 0x0, 0x0, 0x0, 0x1, 0x3, 0x3, 0x3, 0x3, 0x7, 0x7, 0xf, 0xff, 0xfe, 0xfc, 0xf0, 0x0, 0x0, 0x78, 0xff, 0xff, 0xff, 0xf, 0x6, 0x6, 0x6, 0x6, 0x1e, 0xfe, 0xfc, 0xf8, 0xf0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xc0, 0xf8, 0xff, 0x3f, 0x7, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x80, 0x0, 0x3, 0x7, 0xf, 0x1e, 0x18, 0x10, 0x10, 0x18, 0x1e, 0xf, 0xf, 0x3, 0x0, 0x80, 0x0, 0x0, 0x10, 0x10, 0x1f, 0x1f, 0x1f, 0x1f, 0x10, 0x10, 0x10, 0x0, 0x0, 0x0, 0x80, 0x10, 0x18, 0x1c, 0x1e, 0x1f, 0x1f, 0x1d, 0x1c, 0x1c, 0x1c, 0x1c, 0x18, 0x0, 0x0, 0x80, 0x0, 0x1c, 0x1c, 0x1c, 0x18, 0x18, 0x10, 0x18, 0x18, 0xf, 0x7, 0x7, 0x1, 0x0, 0x80, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1f, 0x1f, 0x1f, 0x0, 0x0, 0x0, 0x80, 0xc, 0x1c, 0x1c, 0x1c, 0x18, 0x18, 0x18, 0x18, 0x1c, 0xf, 0x7, 0x3, 0x0, 0x0, 0x80, 0x0, 0x3, 0xf, 0xf, 0x1f, 0x18, 0x18, 0x10, 0x10, 0x1c, 0x1f, 0xf, 0x7, 0x1, 0x80, 0x0, 0x0, 0x0, 0x0, 0x0, 0x10, 0x1e, 0x1f, 0x1f, 0x1, 0x0, 0x0, 0x0, 0x0, 0x80, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x70, 0xfc, 0xfc, 0xfe, 0x86, 0x2, 0x2, 0x86, 0xfe, 0xfe, 0xfc, 0x30, 0x0, 0x0, 0xe0, 0xf8, 0xfc, 0xfe, 0xe, 0x6, 0x2, 0x2, 0x6, 0xfe, 0xfc, 0xf8, 0xf0, 0x80, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xe0, 0xf1, 0xfb, 0x3f, 0xf, 0xf, 0x1f, 0x1f, 0x7d, 0xf9, 0xf8, 0xe0, 0x0, 0x0, 0x1, 0x7, 0xf, 0xf, 0xe, 0x1c, 0x1c, 0x8c, 0xec, 0xff, 0xff, 0xff, 0x3f, 0x3, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x3, 0x7, 0xf, 0xf, 0xc, 0x8, 0x8, 0xc, 0xe, 0xf, 0x7, 0x3, 0x0, 0x0, 0x0, 0x8, 0x8, 0xc, 0xc, 0xe, 0xf, 0x7, 0x7, 0x3, 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xe, 0xe, 0xe, 0xe, 0xe, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};

uint8_t SMB_DATA_OUT[NUM_BYTES_WR_MAX];

uint8_t TARGET;                        // Target SMBus slave address
volatile int voltage = 0;
volatile int amp = 0;
volatile bool SMB_BUSY;                 // Software flag to indicate when the
                                       // SMB_Read() or SMB_Write() functions
                                       // have claimed the SMBus

volatile bool SMB_RW;                   // Software flag to indicate the
                                       // direction of the current transfer

uint16_t NUM_ERRORS;                   // Counter for the number of errors.

//-----------------------------------------------------------------------------
// Function Prototypes
//-----------------------------------------------------------------------------
void SMB_Write(void);
void SMB_Read(void);
void T0_Waitms(uint8_t ms);

//-----------------------------------------------------------------------------
// SiLabs_Startup() Routine
// ----------------------------------------------------------------------------
// This function is called immediately after reset, before the initialization
// code is run in SILABS_STARTUP.A51 (which runs before main() ). This is a
// useful place to disable the watchdog timer, which is enable by default
// and may trigger before main() in some instances.
//-----------------------------------------------------------------------------
void SiLabs_Startup (void)
{

}

// uart 0.4 0.5

void blink() {
  uint8_t i,j,k,n;
  for (n = 0; n < 2; n++) {
        for (i = 0; i < 20; i++)
          {
            NOP ();

        for (j = 0; j < 255; j++)
          {
            NOP ();

        for (k = 0; k < 255; k++)
          {
            NOP ();
          }}}
        P1 ^= 0x04; //toggle LED pin
    }
}

void write_pix(uint8_t* dat, int start) {
  uint8_t i = 0;
  NUM_BYTES_WR = 17;
  SMB_DATA_OUT[0] = 0x40;

  for (i = 0; i < 16; i++) {
      SMB_DATA_OUT[i + 1] = dat[start + i];
  }

  TARGET = SLAVE_ADDR << 1;
  SMB_Write();
  T0_Waitms (50);
}

void write_line(int val) {
  int i, j;
  int cur_val = 0;
  uint8_t dnum[8] = {11, 0, 0, 10, 0, 0, 11, 11};

  dnum[5] = (uint8_t) (val % 10);
  val = val / 10;
  dnum[4] = (uint8_t) (val % 10);
  val = val / 10;
  dnum[2] = (uint8_t) (val % 10);
  val = val / 10;
  dnum[1] = (uint8_t) (val % 10);

  if (dnum[1] == 0) {
      dnum[1] = 12;
  }

  for (i = 0; i < 3; i++) {
    for (j = 0; j < 8; j++) {
        cur_val = dnum[j];
        if (cur_val > 7) {
            cur_val = 128 * 3 + (cur_val - 8) * 16;
        } else {
            cur_val = cur_val * 16;
        }
        write_pix(sdat, i * 128 + cur_val);
    }
  }
}

int main (void)
{
  uint8_t SFRPAGE_save;

  volatile uint8_t dat;               // Test counter
  volatile uint8_t data_count;        // SMB_DATA_IN and SMB_DATA_OUT counter

  uint8_t dval;
  int ncnt = 0;
  int n2cnt = 0;
  int n3cnt = 0;
  int i = 0;

  enter_DefaultMode_from_RESET();


  //P0 = 0xFF; //set all pins to high so inputs can operate
  //P1 = 0xFF;
  //P2 = 0xFF;

  // ALEX STUFF
//  SFRPAGE_save = SFRPAGE;
//  SFRPAGE = 0x30;
//  DAC0L = (546&0xFF);
//  DAC0H = ((546>>8)&0xFF);
//  DAC1L = 119;
//  DAC1H = 3;
//  SFRPAGE = SFRPAGE_save;
                            // Spin forever

/*
  //enter_BusFreeMode_from_RESET();

     // If slave is holding SDA low because of an improper SMBus reset or error
     while(!SDA)
     {
        // Provide clock pulses to allow the slave to advance out
        // of its current state. This will allow it to release SDA.
        XBR2 = 0x40;                     // Enable Crossbar
        SCL = 0;                         // Drive the clock low
        for(i = 0; i < 255; i++);        // Hold the clock low
        SCL = 1;                         // Release the clock
        while(!SCL);                     // Wait for open-drain
                                         // clock output to rise
        for(i = 0; i < 10; i++);         // Hold the clock high
        XBR2 = 0x00;                     // Disable Crossbar

     }

     blink();
     enter_DefaultMode_from_RESET();
*/

     blink();
     T0_Waitms (50);

     // <------------ init screen
     NUM_BYTES_WR = 5;
     SMB_DATA_OUT[0] = 0;
     SMB_DATA_OUT[1] = SSD1306_DISPLAYOFF;
     SMB_DATA_OUT[2] = SSD1306_SETDISPLAYCLOCKDIV;
     SMB_DATA_OUT[3] = 0x80;
     SMB_DATA_OUT[4] = SSD1306_SETMULTIPLEX;
     TARGET = SLAVE_ADDR << 1;
     SMB_Write();
     T0_Waitms (50);

     NUM_BYTES_WR = 2;
     SMB_DATA_OUT[0] = 0;
     SMB_DATA_OUT[1] = 64 - 1;
     TARGET = SLAVE_ADDR << 1;
     SMB_Write();
     T0_Waitms (50);

     NUM_BYTES_WR = 5;
     SMB_DATA_OUT[0] = 0;
     SMB_DATA_OUT[1] = SSD1306_SETDISPLAYOFFSET;
     SMB_DATA_OUT[2] = 0x0;
     SMB_DATA_OUT[3] = SSD1306_SETSTARTLINE | 0x0;
     SMB_DATA_OUT[4] = SSD1306_CHARGEPUMP;
     TARGET = SLAVE_ADDR << 1;
     SMB_Write();
     T0_Waitms (50);

     NUM_BYTES_WR = 2;
     SMB_DATA_OUT[0] = 0;
     SMB_DATA_OUT[1] = 0x14;
     TARGET = SLAVE_ADDR << 1;
     SMB_Write();
     T0_Waitms (50);

     NUM_BYTES_WR = 5;
     SMB_DATA_OUT[0] = 0;
     SMB_DATA_OUT[1] = SSD1306_MEMORYMODE;
     SMB_DATA_OUT[2] = 0x00;
     SMB_DATA_OUT[3] = SSD1306_SEGREMAP | 0x1;
     SMB_DATA_OUT[4] = SSD1306_COMSCANDEC;
     TARGET = SLAVE_ADDR << 1;
     SMB_Write();
     T0_Waitms (50);

     NUM_BYTES_WR = 2;
     SMB_DATA_OUT[0] = 0;
     SMB_DATA_OUT[1] = SSD1306_SETCOMPINS;
     TARGET = SLAVE_ADDR << 1;
     SMB_Write();
     T0_Waitms (50);

     NUM_BYTES_WR = 2;
     SMB_DATA_OUT[0] = 0;
     SMB_DATA_OUT[1] = 0x12;
     TARGET = SLAVE_ADDR << 1;
     SMB_Write();
     T0_Waitms (50);

     NUM_BYTES_WR = 2;
     SMB_DATA_OUT[0] = 0;
     SMB_DATA_OUT[1] = SSD1306_SETCONTRAST;
     TARGET = SLAVE_ADDR << 1;
     SMB_Write();
     T0_Waitms (50);

     NUM_BYTES_WR = 2;
     SMB_DATA_OUT[0] = 0;
     SMB_DATA_OUT[1] = 0xCF;
     TARGET = SLAVE_ADDR << 1;
     SMB_Write();
     T0_Waitms (50);

     NUM_BYTES_WR = 2;
     SMB_DATA_OUT[0] = 0;
     SMB_DATA_OUT[1] = SSD1306_SETPRECHARGE;
     TARGET = SLAVE_ADDR << 1;
     SMB_Write();
     T0_Waitms (50);

     NUM_BYTES_WR = 2;
     SMB_DATA_OUT[0] = 0;
     SMB_DATA_OUT[1] = 0xF1;
     TARGET = SLAVE_ADDR << 1;
     SMB_Write();
     T0_Waitms (50);

     NUM_BYTES_WR = 7;
     SMB_DATA_OUT[0] = 0;
     SMB_DATA_OUT[1] = SSD1306_SETVCOMDETECT;
     SMB_DATA_OUT[2] = 0x40;
     SMB_DATA_OUT[3] = SSD1306_DISPLAYALLON_RESUME;
     SMB_DATA_OUT[4] = SSD1306_NORMALDISPLAY;
     SMB_DATA_OUT[5] = SSD1306_DEACTIVATE_SCROLL;
     SMB_DATA_OUT[6] = SSD1306_DISPLAYON;
     TARGET = SLAVE_ADDR << 1;
     SMB_Write();
     T0_Waitms (50);


     // <---- load stuff to screen

     // <--- clear screen ---->
     NUM_BYTES_WR = 6;
     SMB_DATA_OUT[0] = 0;
     SMB_DATA_OUT[1] = SSD1306_PAGEADDR;
     SMB_DATA_OUT[2] = 0;
     SMB_DATA_OUT[3] = 0xFF;
     SMB_DATA_OUT[4] = SSD1306_COLUMNADDR;
     SMB_DATA_OUT[5] = 0;
     TARGET = SLAVE_ADDR << 1;
     SMB_Write();
     T0_Waitms (50);

     NUM_BYTES_WR = 2;
     SMB_DATA_OUT[0] = 0;
     SMB_DATA_OUT[1] = 128 - 1;
     TARGET = SLAVE_ADDR << 1;
     SMB_Write();

     //SCON0 |= SCON0_REN__RECEIVE_ENABLED;
     SFRPAGE = SFRPAGE_save;
     ncnt = 0;
     while (1) {
        // first line
        write_line(voltage);

        // black space
        for (n2cnt = 0; n2cnt < 8; n2cnt++) {
           write_pix(sdat, 7 * 128);
        }

        // second line
        write_line(amp);

        // black space
        for (n2cnt = 0; n2cnt < 8; n2cnt++) {
          write_pix(sdat, 7 * 128);
        }
        ncnt++;
     }

}

//-----------------------------------------------------------------------------
// Support Functions
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// SMB_Write
//-----------------------------------------------------------------------------
//
// Return Value : None
// Parameters   : None
//
// Writes a single byte to the slave with address specified by the <TARGET>
// variable.
// Calling sequence:
// 1) Write target slave address to the <TARGET> variable
// 2) Write outgoing data to the <SMB_DATA_OUT> variable array
// 3) Call SMB_Write()
//
//-----------------------------------------------------------------------------
void SMB_Write(void)
{
   while(SMB_BUSY);                    // Wait for SMBus to be free.
   SMB_BUSY = 1;                       // Claim SMBus (set to busy)
   SMB_RW = 0;                         // Mark this transfer as a WRITE
   SMB0CN0_STA = 1;                    // Start transfer
}

//-----------------------------------------------------------------------------
// SMB_Read
//-----------------------------------------------------------------------------
//
// Return Value : None
// Parameters   : None
//
// Reads a single byte from the slave with address specified by the <TARGET>
// variable.
// Calling sequence:
// 1) Write target slave address to the <TARGET> variable
// 2) Call SMB_Write()
// 3) Read input data from <SMB_DATA_IN> variable array
//
//-----------------------------------------------------------------------------
void SMB_Read(void)
{
   while(SMB_BUSY);                    // Wait for bus to be free.
   SMB_BUSY = 1;                       // Claim SMBus (set to busy)
   SMB_RW = 1;                         // Mark this transfer as a READ

   SMB0CN0_STA = 1;                    // Start transfer

   while(SMB_BUSY);                    // Wait for transfer to complete
}

//-----------------------------------------------------------------------------
// T0_Waitms
//-----------------------------------------------------------------------------
//
// Return Value : None
// Parameters   :
//   1) uint8_t ms - number of milliseconds to wait
//                        range is full range of character: 0 to 255
//
// Configure Timer0 to wait for <ms> milliseconds using SYSCLK as its time
// base.
//
//-----------------------------------------------------------------------------
void T0_Waitms(uint8_t ms)
{

  uint8_t i,j,k,n;


  for (j = 0; j < 20; j++)
    {
      NOP ();

  for (k = 0; k < 255; k++){
    NOP ();
  }
    }

}
