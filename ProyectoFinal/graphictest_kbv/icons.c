#if defined(__arm__) || defined(ESP8266) || defined(ESP32)
#define PROGMEM
#else 
#include <Arduino.h>
#endif

const unsigned char PROGMEM penguin[16] = {   
  0x1E, 0x00, //    ####   
  0x3F, 0x00, //   ######  
  0x3F, 0x80, //   ####### 
  0x7F, 0x80, //  ######## 
  0x7F, 0x80, //  ######## 
  0xF3, 0xC0, // ####  ####
  0xED, 0xC0, // ### ## ###
  0xE3, 0xC0, // ###   ####
  0xE9, 0xC0, // ### #  ###
  0xF5, 0xC0, // #### # ###
  0xF3, 0xC0, // ####  ####
  0x7F, 0x80, //  ######## 
  0x7F, 0x80, //  ######## 
  0x7F, 0x80, //  ######## 
  0x3F, 0x00, //   ######  
  0x1E, 0x00, //    ####
};

const unsigned char PROGMEM icon_40x40[3200] = {  /* 0X00,0X10,0X28,0X00,0X28,0X00,0X01,0X1B, */
    0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF,
    0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF,
    0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF,
    0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF,
    0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF,
    0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF,
    0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0X5D, 0XEF, 0X71, 0X8C, 0X31, 0X84, 0X31, 0X84,
    0X93, 0XC5, 0X92, 0XCD, 0X91, 0XCD, 0X91, 0XD5, 0X91, 0XD5, 0X91, 0XCD, 0X72, 0XCD, 0X72, 0XC5,
    0X56, 0XDE, 0XBE, 0XFF, 0XDB, 0XDE, 0XFB, 0XDE, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF,
    0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF,
    0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF,
    0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XCE, 0X7B, 0X00, 0X00, 0X00, 0X00, 0X00, 0X00,
    0X00, 0X5A, 0X20, 0XDD, 0X20, 0XDD, 0X20, 0XDD, 0X20, 0XDD, 0X20, 0XDD, 0XE0, 0XD4, 0XA0, 0XD4,
    0X61, 0XA3, 0XA7, 0X39, 0XE5, 0X18, 0X05, 0X21, 0X92, 0X94, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF,
    0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF,
    0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF,
    0XFF, 0XFF, 0XFF, 0XFF, 0XF9, 0XEE, 0XEB, 0X9B, 0XA1, 0X18, 0X23, 0X73, 0X81, 0XC5, 0X21, 0X9C,
    0X61, 0X39, 0X81, 0XEE, 0X40, 0XFF, 0XE0, 0XFE, 0XE0, 0XFE, 0XE0, 0XFE, 0X40, 0XFF, 0XC0, 0XF6,
    0XC0, 0X49, 0XA0, 0X18, 0X00, 0X42, 0X60, 0X18, 0X00, 0X00, 0X74, 0XB5, 0XFF, 0XFF, 0XFF, 0XFF,
    0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF,
    0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF,
    0XFF, 0XFF, 0X93, 0XCD, 0XC3, 0XBB, 0XA0, 0X51, 0XE1, 0X39, 0XC2, 0XFF, 0XE0, 0XFF, 0XE0, 0XFF,
    0X63, 0XBD, 0X61, 0XE6, 0X40, 0XFF, 0XE0, 0XFE, 0XE0, 0XFE, 0XC0, 0XFE, 0X60, 0XFF, 0X21, 0X73,
    0XE1, 0X28, 0X81, 0XEE, 0X61, 0XFF, 0X21, 0XEE, 0XA0, 0X41, 0X20, 0X08, 0X90, 0XCD, 0XDE, 0XFF,
    0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF,
    0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0X5C, 0XF7,
    0X0B, 0XAC, 0XC0, 0XB3, 0XA1, 0XEE, 0XC3, 0X5A, 0X22, 0X8C, 0XE1, 0XFF, 0X40, 0XFF, 0X40, 0XFF,
    0XC0, 0XFF, 0X80, 0XFF, 0X20, 0XFF, 0X20, 0XFF, 0X20, 0XFF, 0X00, 0XFF, 0X20, 0XFF, 0XA1, 0XAC,
    0X21, 0XC5, 0X20, 0XFF, 0X60, 0XFE, 0X00, 0XFF, 0X02, 0XDE, 0XE0, 0X20, 0X40, 0X82, 0X49, 0XBC,
    0X3B, 0XEF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF,
    0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0X5C, 0XF7, 0X67, 0X9B,
    0XE0, 0XB3, 0X81, 0XFF, 0XC3, 0XFF, 0X83, 0X9C, 0X82, 0XDE, 0XC0, 0XFF, 0X60, 0XFF, 0X60, 0XFF,
    0X40, 0XFF, 0X60, 0XFF, 0X40, 0XFF, 0X40, 0XFF, 0X40, 0XFF, 0X20, 0XFF, 0X00, 0XFF, 0X60, 0XFF,
    0X40, 0XFF, 0XA0, 0XFE, 0X80, 0XFE, 0X40, 0XFE, 0XE0, 0XFE, 0XA2, 0XB4, 0X41, 0XBC, 0X20, 0XCC,
    0X87, 0XA3, 0XB8, 0XE6, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF,
    0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0X9D, 0XF7, 0XA8, 0XA3, 0X60, 0XBC,
    0XA2, 0XFF, 0XA5, 0XFF, 0X44, 0XFF, 0XA1, 0XFF, 0XA0, 0XFF, 0X60, 0XFF, 0X80, 0XFF, 0X80, 0XFF,
    0X80, 0XFF, 0X80, 0XFF, 0X60, 0XFF, 0X60, 0XFF, 0X40, 0XFF, 0X40, 0XFF, 0X20, 0XFF, 0X20, 0XFF,
    0X00, 0XFF, 0XC0, 0XFE, 0XA0, 0XFE, 0X80, 0XFE, 0X40, 0XFE, 0X60, 0XFE, 0X20, 0XFE, 0X40, 0XFE,
    0XE0, 0XCB, 0XE3, 0X92, 0X7C, 0XF7, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF,
    0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0X4C, 0XAC, 0XC0, 0XB3, 0XA4, 0XFF,
    0XA6, 0XFF, 0X45, 0XFF, 0X62, 0XFF, 0X80, 0XFF, 0X80, 0XFF, 0X80, 0XFF, 0XA0, 0XFF, 0XA0, 0XFF,
    0XA0, 0XFF, 0XA0, 0XFF, 0X80, 0XFF, 0X80, 0XFF, 0X80, 0XFF, 0X60, 0XFF, 0X40, 0XFF, 0X40, 0XFF,
    0X20, 0XFF, 0XE0, 0XFE, 0XC0, 0XFE, 0X80, 0XFE, 0X60, 0XFE, 0X40, 0XFE, 0X20, 0XFE, 0X00, 0XFE,
    0XE0, 0XFD, 0XE0, 0XC3, 0X2A, 0XAC, 0X7D, 0XF7, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF,
    0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XD4, 0XD5, 0X40, 0XAB, 0X43, 0XFF, 0XA8, 0XFF,
    0X67, 0XFF, 0X62, 0XFF, 0X80, 0XFF, 0X80, 0XFF, 0XA0, 0XFF, 0XA0, 0XFF, 0XC0, 0XFF, 0XC0, 0XFF,
    0XC0, 0XFF, 0XA0, 0XFF, 0XA0, 0XFF, 0XA0, 0XFF, 0X80, 0XFF, 0X80, 0XFF, 0X60, 0XFF, 0X40, 0XFF,
    0X40, 0XFF, 0X00, 0XFF, 0XE0, 0XFE, 0XA0, 0XFE, 0X80, 0XFE, 0X40, 0XFE, 0X20, 0XFE, 0XE0, 0XFD,
    0XE0, 0XFD, 0XC0, 0XFD, 0XA0, 0XA2, 0X11, 0XBD, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF,
    0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XDA, 0XE6, 0XE4, 0X9A, 0XE1, 0XE5, 0XE8, 0XFF, 0X69, 0XFF,
    0X65, 0XFF, 0X60, 0XFF, 0X80, 0XFF, 0XA0, 0XFF, 0XC0, 0XFF, 0XE0, 0XFF, 0XE0, 0XFF, 0XE0, 0XFF,
    0XE0, 0XFF, 0XC0, 0XFF, 0XC0, 0XFF, 0XA0, 0XFF, 0XA0, 0XFF, 0X80, 0XFF, 0X80, 0XFF, 0X60, 0XFF,
    0X40, 0XFF, 0X00, 0XFF, 0X00, 0XFF, 0X20, 0XFF, 0XE0, 0XFE, 0X60, 0XFE, 0X20, 0XFE, 0X00, 0XFE,
    0XC0, 0XFD, 0XE0, 0XFD, 0XE0, 0XE4, 0X85, 0XAB, 0XFA, 0XE6, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF,
    0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0X2B, 0XB4, 0XC0, 0XB3, 0XC8, 0XFF, 0X8C, 0XFF, 0X68, 0XFF,
    0X61, 0XFF, 0XA0, 0XFF, 0XA0, 0XFF, 0XC0, 0XFF, 0XE0, 0XFF, 0XE1, 0XFF, 0XA1, 0XDE, 0X61, 0XEF,
    0XE1, 0XFF, 0XE0, 0XFF, 0XE0, 0XFF, 0XC0, 0XFF, 0XC0, 0XFF, 0XA0, 0XFF, 0X80, 0XFF, 0X60, 0XFF,
    0X40, 0XFF, 0X60, 0XFF, 0XC0, 0XFF, 0X61, 0XDE, 0X00, 0XE6, 0X80, 0XFE, 0X40, 0XFE, 0X00, 0XFE,
    0XE0, 0XFD, 0XC0, 0XFD, 0XE0, 0XFD, 0XC0, 0XC3, 0XE9, 0XAB, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF,
    0XFF, 0XFF, 0XFF, 0XFF, 0X5D, 0XEF, 0XA3, 0XAB, 0XA3, 0XF6, 0XCC, 0XFF, 0X4C, 0XFF, 0X64, 0XFF,
    0X80, 0XFF, 0XA0, 0XFF, 0XC0, 0XFF, 0XE0, 0XFF, 0X61, 0XEF, 0X22, 0X6B, 0X82, 0X5A, 0X82, 0XB5,
    0XE2, 0XFF, 0XE1, 0XFF, 0XE0, 0XFF, 0XE0, 0XFF, 0XE0, 0XFF, 0XA0, 0XFF, 0X80, 0XFF, 0X60, 0XFF,
    0XA0, 0XFF, 0XE1, 0XFF, 0X42, 0X8C, 0XC1, 0X41, 0X21, 0XA4, 0XA0, 0XFE, 0X80, 0XFE, 0X20, 0XFE,
    0XE0, 0XFD, 0XC0, 0XFD, 0XA0, 0XFD, 0X20, 0XF5, 0XC0, 0X9A, 0X35, 0XD6, 0XFF, 0XFF, 0XFF, 0XFF,
    0XFF, 0XFF, 0XFF, 0XFF, 0X51, 0XC5, 0X60, 0XBC, 0XC9, 0XFF, 0X8E, 0XFF, 0X6A, 0XFF, 0X61, 0XFF,
    0X80, 0XFF, 0XA0, 0XFF, 0XC0, 0XFF, 0XE1, 0XFF, 0XE1, 0X62, 0X80, 0X10, 0X05, 0XE7, 0XA4, 0XF7,
    0XE4, 0XFF, 0XE3, 0XFF, 0XE2, 0XFF, 0XE0, 0XFF, 0XE0, 0XFF, 0XC0, 0XFF, 0XA0, 0XFF, 0XA0, 0XFF,
    0XC1, 0XFF, 0XE2, 0X83, 0X40, 0X08, 0X22, 0XCE, 0X60, 0XF7, 0XA0, 0XFE, 0X60, 0XFE, 0X20, 0XFE,
    0XE0, 0XFD, 0XC0, 0XFD, 0X80, 0XFD, 0XA0, 0XFD, 0XA0, 0XC3, 0XAC, 0XBC, 0XFF, 0XFF, 0XFF, 0XFF,
    0XFF, 0XFF, 0XDE, 0XFF, 0XA7, 0XAB, 0X81, 0XDD, 0XED, 0XFF, 0XB0, 0XFF, 0X69, 0XFF, 0X60, 0XFF,
    0X80, 0XFF, 0XA0, 0XFF, 0XE0, 0XFF, 0X61, 0XD6, 0X22, 0X29, 0XA6, 0X31, 0XE3, 0X7B, 0X46, 0XEF,
    0XE6, 0XFF, 0XE4, 0XFF, 0XE2, 0XFF, 0XE1, 0XFF, 0XE0, 0XFF, 0XC0, 0XFF, 0XA0, 0XFF, 0XE0, 0XFF,
    0X81, 0XD6, 0XA0, 0X18, 0XC4, 0X18, 0XA1, 0X62, 0XC1, 0XCD, 0X40, 0XFF, 0X60, 0XFE, 0X20, 0XFE,
    0XE0, 0XFD, 0XC0, 0XFD, 0X80, 0XFD, 0X80, 0XFD, 0XA0, 0XEC, 0X48, 0XBC, 0XDF, 0XFF, 0XFF, 0XFF,
    0XFF, 0XFF, 0XF9, 0XE6, 0XE3, 0X9A, 0X67, 0XEE, 0XD1, 0XFF, 0XB0, 0XFF, 0X86, 0XFF, 0X60, 0XFF,
    0X80, 0XFF, 0XA0, 0XFF, 0XE0, 0XFF, 0X60, 0X94, 0X91, 0X73, 0XD9, 0XBD, 0X00, 0X00, 0X05, 0X84,
    0XE8, 0XFF, 0XE5, 0XFF, 0XE3, 0XFF, 0XE1, 0XFF, 0XE0, 0XFF, 0XC0, 0XFF, 0XA0, 0XFF, 0XE0, 0XFF,
    0X20, 0XAD, 0XE9, 0X41, 0XB7, 0XB5, 0X01, 0X00, 0X60, 0X62, 0X21, 0XFF, 0X80, 0XFE, 0X20, 0XFE,
    0XE0, 0XFD, 0XC0, 0XFD, 0X80, 0XFD, 0X60, 0XFD, 0X20, 0XF5, 0XE3, 0XBB, 0XD9, 0XE6, 0XFF, 0XFF,
    0XFF, 0XFF, 0XD3, 0XCD, 0X40, 0XA3, 0X2B, 0XF7, 0XD3, 0XFF, 0XB0, 0XFF, 0X63, 0XFF, 0X60, 0XFF,
    0X80, 0XFF, 0XA0, 0XFF, 0XE0, 0XFF, 0XA0, 0X9C, 0X30, 0X6B, 0X97, 0XB5, 0X00, 0X00, 0X83, 0X52,
    0XC6, 0XFF, 0XE5, 0XFF, 0XE3, 0XFF, 0XE1, 0XFF, 0XE0, 0XFF, 0XC0, 0XFF, 0XA0, 0XFF, 0XE0, 0XFF,
    0X20, 0XAD, 0XEA, 0X41, 0X77, 0XAD, 0X01, 0X00, 0XC0, 0X49, 0XE0, 0XF6, 0XA0, 0XFE, 0X20, 0XFE,
    0XE0, 0XFD, 0XC0, 0XFD, 0X80, 0XFD, 0X60, 0XFD, 0X40, 0XFD, 0XA0, 0XBB, 0XD3, 0XCD, 0XFF, 0XFF,
    0XFF, 0XFF, 0X50, 0XCD, 0X00, 0XB4, 0X8E, 0XFF, 0XF4, 0XFF, 0XB0, 0XFF, 0X42, 0XFF, 0X60, 0XFF,
    0X80, 0XFF, 0XA0, 0XFF, 0XE0, 0XFF, 0XA1, 0XDE, 0X01, 0X21, 0X00, 0X00, 0X00, 0X00, 0X25, 0X8C,
    0XE5, 0XFF, 0XE3, 0XFF, 0XE2, 0XFF, 0XE0, 0XFF, 0XE0, 0XFF, 0XC0, 0XFF, 0XA0, 0XFF, 0XE0, 0XFF,
    0XE1, 0XDE, 0X01, 0X21, 0X00, 0X00, 0X00, 0X00, 0X61, 0X5A, 0X20, 0XFF, 0X80, 0XFE, 0X20, 0XFE,
    0X00, 0XFE, 0XE0, 0XFD, 0XA0, 0XFD, 0X60, 0XFD, 0X60, 0XFD, 0XC0, 0XCB, 0X71, 0XCD, 0XFF, 0XFF,
    0XFF, 0XFF, 0X50, 0XCD, 0X40, 0XC4, 0XB0, 0XFF, 0XF5, 0XFF, 0X8F, 0XFF, 0X41, 0XFF, 0X80, 0XFF,
    0XA0, 0XFF, 0XC0, 0XFF, 0XE0, 0XFF, 0XE1, 0XFF, 0X21, 0X8C, 0X60, 0X10, 0X43, 0X6B, 0X44, 0XEF,
    0XE2, 0XFF, 0XE2, 0XFF, 0XE1, 0XFF, 0XE0, 0XFF, 0XC0, 0XFF, 0XA0, 0XFF, 0X80, 0XFF, 0X80, 0XFF,
    0XE1, 0XFF, 0XC1, 0XA4, 0XC2, 0X18, 0XA2, 0X39, 0XA1, 0XCD, 0X20, 0XFF, 0X60, 0XFE, 0X20, 0XFE,
    0XC0, 0XFD, 0X80, 0XFD, 0X80, 0XFD, 0X60, 0XFD, 0X60, 0XFD, 0XE0, 0XCB, 0X91, 0XCD, 0XFF, 0XFF,
    0XFF, 0XFF, 0X50, 0XCD, 0X40, 0XC4, 0XD2, 0XFF, 0XF7, 0XFF, 0XAF, 0XFF, 0X01, 0XFF, 0X00, 0XFF,
    0X00, 0XFF, 0X40, 0XFF, 0XA0, 0XFF, 0XE0, 0XFF, 0XA1, 0XFF, 0X82, 0XD6, 0XC2, 0XFF, 0XE0, 0XFF,
    0XE0, 0XFF, 0XE0, 0XFF, 0XE0, 0XFF, 0XC0, 0XFF, 0XC0, 0XFF, 0XA0, 0XFF, 0X80, 0XFF, 0X60, 0XFF,
    0X60, 0XFF, 0XC1, 0XFF, 0X82, 0XDE, 0XC2, 0XEE, 0X61, 0XFF, 0X80, 0XFE, 0XC0, 0XFD, 0X20, 0XFD,
    0XA1, 0XFC, 0X61, 0XFC, 0X61, 0XFC, 0XC0, 0XFC, 0X60, 0XFD, 0XE0, 0XCB, 0X51, 0XC5, 0XFF, 0XFF,
    0XFF, 0XFF, 0X50, 0XCD, 0X60, 0XC4, 0XD4, 0XFF, 0XF9, 0XFF, 0X2D, 0XFF, 0X00, 0XFE, 0XC0, 0XFD,
    0XA1, 0XFD, 0X21, 0XFE, 0XE0, 0XFE, 0XC0, 0XFF, 0XE0, 0XFF, 0XE0, 0XFF, 0XE0, 0XFF, 0XE0, 0XFF,
    0XE0, 0XFF, 0XE0, 0XFF, 0XC0, 0XFF, 0XC0, 0XFF, 0XA0, 0XFF, 0X80, 0XFF, 0X80, 0XFF, 0X60, 0XFF,
    0X40, 0XFF, 0X40, 0XFF, 0X80, 0XFF, 0X20, 0XFF, 0XA0, 0XFE, 0X20, 0XFE, 0X01, 0XFD, 0X01, 0XFC,
    0X62, 0XFB, 0X42, 0XFB, 0X82, 0XFB, 0X21, 0XFC, 0X20, 0XFD, 0X00, 0XD4, 0X71, 0XC5, 0XFF, 0XFF,
    0XFF, 0XFF, 0X50, 0XCD, 0X20, 0XC4, 0XD4, 0XFF, 0XBA, 0XFF, 0X2E, 0XFE, 0XE1, 0XFC, 0X61, 0XFC,
    0X61, 0XFC, 0X01, 0XFD, 0X01, 0XFE, 0X20, 0XFF, 0XA0, 0XFF, 0XA0, 0XFF, 0XC0, 0XFF, 0XC0, 0XFF,
    0XC0, 0XFF, 0XC0, 0XFF, 0XA0, 0XFF, 0XA0, 0XFF, 0X80, 0XFF, 0X80, 0XFF, 0X60, 0XFF, 0X40, 0XFF,
    0X40, 0XFF, 0X00, 0XFF, 0XC0, 0XFE, 0XA0, 0XFE, 0X80, 0XFE, 0X80, 0XFD, 0X61, 0XFC, 0X62, 0XFB,
    0XA3, 0XFA, 0XA3, 0XFA, 0X42, 0XFB, 0X01, 0XFC, 0XE0, 0XFC, 0XE0, 0XCB, 0X71, 0XCD, 0XFF, 0XFF,
    0XFF, 0XFF, 0X50, 0XCD, 0XC0, 0XB3, 0XB3, 0XFF, 0X7A, 0XFF, 0X91, 0XFD, 0X03, 0XFC, 0X02, 0XFB,
    0X22, 0XFB, 0X62, 0XFC, 0X81, 0XFD, 0XC0, 0XFE, 0XA0, 0XFF, 0XA0, 0XFF, 0XA0, 0XFF, 0XA0, 0XFF,
    0XA0, 0XFF, 0XA0, 0XFF, 0X80, 0XFF, 0X80, 0XFF, 0X60, 0XFF, 0X60, 0XFF, 0X40, 0XFF, 0X40, 0XFF,
    0X20, 0XFF, 0XE0, 0XFE, 0XC0, 0XFE, 0XA0, 0XFE, 0X60, 0XFE, 0X60, 0XFD, 0X41, 0XFC, 0X62, 0XFB,
    0XC3, 0XFA, 0XA3, 0XFA, 0X42, 0XFB, 0X01, 0XFC, 0X20, 0XFD, 0XC0, 0XCB, 0X91, 0XCD, 0XFF, 0XFF,
    0XFF, 0XFF, 0X14, 0XD6, 0X20, 0XAB, 0X51, 0XF7, 0XBE, 0XFF, 0X17, 0XFE, 0X65, 0XFC, 0X61, 0XFB,
    0XA2, 0XFB, 0XA1, 0XFC, 0XC1, 0XFD, 0X00, 0XFF, 0X80, 0XFF, 0X80, 0XFF, 0X80, 0XFF, 0X80, 0XFF,
    0X80, 0XFF, 0X80, 0XFF, 0X80, 0XFF, 0X60, 0XFF, 0X60, 0XFF, 0X60, 0XFF, 0X40, 0XFF, 0X20, 0XFF,
    0X00, 0XFF, 0XC0, 0XFE, 0XA0, 0XFE, 0X80, 0XFE, 0X60, 0XFE, 0XC0, 0XFD, 0XC0, 0XFC, 0X41, 0XFC,
    0XC1, 0XFB, 0XA2, 0XFB, 0X01, 0XFC, 0XA0, 0XFC, 0X40, 0XFD, 0XA0, 0XC3, 0XF4, 0XD5, 0XFF, 0XFF,
    0XFF, 0XFF, 0X5B, 0XEF, 0X24, 0X9B, 0X49, 0XE6, 0XB8, 0XFF, 0X92, 0XFE, 0X25, 0XFD, 0XA0, 0XFC,
    0X02, 0XFD, 0XE1, 0XFD, 0XE0, 0XFE, 0X40, 0XFF, 0X60, 0XFF, 0X40, 0XFF, 0X60, 0XFF, 0X60, 0XFF,
    0X60, 0XFF, 0X60, 0XFF, 0X40, 0XFF, 0X40, 0XFF, 0X40, 0XFF, 0X40, 0XFF, 0X20, 0XFF, 0X00, 0XFF,
    0XC0, 0XFE, 0XA0, 0XFE, 0X80, 0XFE, 0X40, 0XFE, 0X40, 0XFE, 0X00, 0XFE, 0X80, 0XFD, 0X01, 0XF5,
    0X41, 0XFD, 0X01, 0XFD, 0XC0, 0XFC, 0X40, 0XFD, 0X00, 0XF5, 0XC4, 0XBB, 0XFA, 0XE6, 0XFF, 0XFF,
    0XFF, 0XFF, 0XFF, 0XFF, 0X2A, 0XB4, 0XA0, 0XD4, 0XA2, 0XFE, 0X20, 0XFE, 0XE0, 0XFD, 0X00, 0XFE,
    0X80, 0XFE, 0X21, 0XEE, 0X41, 0XE6, 0X40, 0XFF, 0X40, 0XFF, 0X40, 0XFF, 0X40, 0XFF, 0X40, 0XFF,
    0X40, 0XFF, 0X40, 0XFF, 0X40, 0XFF, 0X20, 0XFF, 0X20, 0XFF, 0X00, 0XFF, 0XE0, 0XFE, 0XC0, 0XFE,
    0XA0, 0XFE, 0X80, 0XFE, 0X60, 0XFE, 0X40, 0XFE, 0X00, 0XFE, 0X00, 0XFE, 0X00, 0XFE, 0X40, 0XCC,
    0XE1, 0XAB, 0XC1, 0XED, 0X80, 0XFD, 0X60, 0XFD, 0X60, 0XE4, 0X29, 0XB4, 0XFF, 0XFF, 0XFF, 0XFF,
    0XFF, 0XFF, 0XFF, 0XFF, 0X15, 0XD6, 0XE0, 0XBB, 0X60, 0XFE, 0XC8, 0XFE, 0XC8, 0XFE, 0X02, 0XFF,
    0X60, 0XDD, 0X40, 0XA3, 0XA1, 0XDD, 0X40, 0XFF, 0X20, 0XFF, 0X20, 0XFF, 0X20, 0XFF, 0X20, 0XFF,
    0X20, 0XFF, 0X20, 0XFF, 0X20, 0XFF, 0X00, 0XFF, 0XE0, 0XFE, 0XC0, 0XFE, 0XC0, 0XFE, 0XA0, 0XFE,
    0X80, 0XFE, 0X60, 0XFE, 0X40, 0XFE, 0X20, 0XFE, 0X20, 0XFE, 0X20, 0XFE, 0X20, 0XFE, 0X40, 0XED,
    0XC0, 0X9A, 0X40, 0XA3, 0X80, 0XF5, 0X60, 0XFD, 0X60, 0XBB, 0XEE, 0XBC, 0XFF, 0XFF, 0XFF, 0XFF,
    0XFF, 0XFF, 0XFF, 0XFF, 0XDF, 0XFF, 0X63, 0XAB, 0X42, 0XE5, 0XB4, 0XFF, 0X97, 0XFF, 0XAA, 0XF6,
    0X80, 0XAB, 0XA0, 0X92, 0XA1, 0XDD, 0X41, 0XFF, 0X40, 0XFF, 0X60, 0XFF, 0X60, 0XFF, 0X60, 0XFF,
    0X60, 0XFF, 0X40, 0XFF, 0X40, 0XFF, 0X40, 0XFF, 0X20, 0XFF, 0X20, 0XFF, 0X00, 0XFF, 0XE0, 0XFE,
    0XC0, 0XFE, 0X80, 0XFE, 0X61, 0XFE, 0X00, 0XFE, 0XA0, 0XED, 0X20, 0XE5, 0X21, 0XCC, 0X80, 0XB3,
    0X00, 0XBC, 0XE0, 0XC3, 0X40, 0XED, 0XC0, 0XEC, 0X60, 0X92, 0X97, 0XE6, 0XFF, 0XFF, 0XFF, 0XFF,
    0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0X0F, 0XC5, 0X00, 0XA3, 0XAA, 0XF6, 0X93, 0XFF, 0X2D, 0XEE,
    0X63, 0XDD, 0X80, 0XD5, 0X42, 0XB4, 0X82, 0XCC, 0X00, 0XCD, 0X40, 0XD5, 0XA0, 0XDD, 0XE1, 0XE5,
    0XC1, 0XE5, 0XC1, 0XE5, 0XC1, 0XE5, 0XC1, 0XE5, 0X80, 0XDD, 0X60, 0XDD, 0X20, 0XD5, 0XC0, 0XCC,
    0XA0, 0XCC, 0X61, 0XC4, 0X21, 0XC4, 0X01, 0XBC, 0X01, 0XBC, 0XE0, 0XBB, 0XC0, 0XBB, 0X60, 0XD4,
    0X80, 0XFD, 0X40, 0XFD, 0X80, 0XFD, 0X80, 0XBB, 0X2B, 0XAC, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF,
    0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0X9D, 0XF7, 0X87, 0XA3, 0X60, 0XD4, 0X0A, 0XFF, 0XCF, 0XFE,
    0XC9, 0XFE, 0XC0, 0XFE, 0XC0, 0XF6, 0X40, 0XE6, 0X41, 0XCD, 0X42, 0XB4, 0XC1, 0XAB, 0X60, 0XA3,
    0X60, 0XA3, 0X80, 0XA3, 0X80, 0XA3, 0X80, 0XA3, 0XA0, 0XAB, 0XC1, 0XAB, 0XE1, 0XB3, 0X22, 0XB4,
    0X82, 0XC4, 0XC0, 0XCC, 0X00, 0XD5, 0X60, 0XE5, 0X81, 0XED, 0X80, 0XF5, 0X80, 0XFD, 0X80, 0XFD,
    0X40, 0XFD, 0X80, 0XFD, 0X80, 0XE4, 0X85, 0XAB, 0X5C, 0XEF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF,
    0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFA, 0XE6, 0X23, 0XA3, 0XE0, 0XE4, 0XE8, 0XFE,
    0X6A, 0XFE, 0X05, 0XFE, 0X40, 0XFE, 0XA0, 0XFE, 0XC0, 0XFE, 0XE1, 0XFE, 0XA0, 0XF6, 0XA0, 0XF6,
    0XA0, 0XF6, 0XA0, 0XF6, 0X80, 0XF6, 0X80, 0XF6, 0X80, 0XF6, 0X60, 0XF6, 0X61, 0XFE, 0X81, 0XFE,
    0X61, 0XFE, 0X20, 0XFE, 0X00, 0XFE, 0XC0, 0XFD, 0X80, 0XFD, 0X60, 0XFD, 0X20, 0XFD, 0X20, 0XFD,
    0X60, 0XFD, 0X20, 0XF5, 0XA0, 0XA2, 0XB4, 0XCD, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF,
    0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0X52, 0XC5, 0XE0, 0XA2, 0XA1, 0XF5,
    0X86, 0XFE, 0X06, 0XFE, 0XE2, 0XFD, 0XE0, 0XFD, 0X00, 0XFE, 0X20, 0XFE, 0X20, 0XFE, 0X20, 0XFE,
    0X40, 0XFE, 0X20, 0XFE, 0X20, 0XFE, 0X20, 0XFE, 0X00, 0XFE, 0XE0, 0XFD, 0XE0, 0XFD, 0XC0, 0XFD,
    0XA0, 0XFD, 0X80, 0XFD, 0X60, 0XFD, 0X40, 0XFD, 0X20, 0XFD, 0X20, 0XFD, 0X20, 0XFD, 0X40, 0XFD,
    0X60, 0XFD, 0X60, 0XBB, 0X6C, 0XB4, 0XDE, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF,
    0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0X92, 0XCD, 0XC0, 0XA2,
    0X20, 0XED, 0X22, 0XFE, 0XC1, 0XFD, 0XA0, 0XFD, 0XC0, 0XFD, 0XE0, 0XFD, 0XE0, 0XFD, 0XE0, 0XFD,
    0XE0, 0XFD, 0XE0, 0XFD, 0XC0, 0XFD, 0XC0, 0XFD, 0XC0, 0XFD, 0XC0, 0XFD, 0XA0, 0XFD, 0X80, 0XFD,
    0X80, 0XFD, 0X60, 0XFD, 0X40, 0XFD, 0X20, 0XFD, 0X20, 0XFD, 0X20, 0XFD, 0X60, 0XFD, 0X40, 0XFD,
    0X20, 0XB3, 0XEA, 0XA3, 0X9D, 0XF7, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF,
    0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0X8E, 0XBC,
    0XE1, 0XA2, 0X00, 0XE5, 0XE0, 0XFD, 0XC0, 0XFD, 0XA0, 0XFD, 0XA0, 0XFD, 0XA0, 0XFD, 0XA0, 0XFD,
    0XC0, 0XFD, 0XA0, 0XFD, 0XA0, 0XFD, 0XA0, 0XFD, 0XA0, 0XFD, 0X80, 0XFD, 0X80, 0XFD, 0X60, 0XFD,
    0X40, 0XFD, 0X20, 0XFD, 0X20, 0XFD, 0X20, 0XFD, 0X20, 0XFD, 0X80, 0XFD, 0X00, 0XF5, 0X40, 0XBB,
    0X2B, 0XAC, 0X9D, 0XF7, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF,
    0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF,
    0X35, 0XD6, 0XE2, 0X9A, 0XA0, 0XC3, 0XA0, 0XFD, 0XE0, 0XFD, 0X80, 0XFD, 0X60, 0XFD, 0X80, 0XFD,
    0X80, 0XFD, 0X60, 0XFD, 0X60, 0XFD, 0X60, 0XFD, 0X60, 0XFD, 0X60, 0XFD, 0X40, 0XFD, 0X40, 0XFD,
    0X20, 0XFD, 0X20, 0XFD, 0X40, 0XFD, 0X60, 0XFD, 0X60, 0XFD, 0X00, 0XD4, 0XC1, 0X9A, 0X10, 0XC5,
    0XDE, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF,
    0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF,
    0XFF, 0XFF, 0X98, 0XDE, 0X2B, 0XAC, 0X40, 0XB3, 0X00, 0XD4, 0X40, 0XFD, 0X80, 0XFD, 0X80, 0XFD,
    0X60, 0XFD, 0X40, 0XFD, 0X40, 0XFD, 0X40, 0XFD, 0X40, 0XFD, 0X40, 0XFD, 0X40, 0XFD, 0X40, 0XFD,
    0X40, 0XFD, 0X60, 0XFD, 0X40, 0XFD, 0X40, 0XDC, 0X80, 0XBB, 0XE8, 0XAB, 0X57, 0XDE, 0XFF, 0XFF,
    0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF,
    0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF,
    0XFF, 0XFF, 0XFF, 0XFF, 0XDF, 0XFF, 0X37, 0XD6, 0X86, 0XA3, 0XC0, 0X9A, 0XE0, 0XCB, 0X80, 0XEC,
    0XE0, 0XF4, 0X20, 0XFD, 0X20, 0XFD, 0X20, 0XFD, 0X20, 0XFD, 0X20, 0XFD, 0X20, 0XFD, 0X00, 0XF5,
    0XA0, 0XEC, 0X00, 0XD4, 0X40, 0XB3, 0X03, 0X9B, 0X92, 0XC5, 0XBD, 0XF7, 0XFF, 0XFF, 0XFF, 0XFF,
    0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF,
    0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF,
    0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XBE, 0XF7, 0XF5, 0XCD, 0XAD, 0XBC, 0X69, 0XBC,
    0X05, 0XBC, 0X03, 0XC4, 0X01, 0XC4, 0X01, 0XC4, 0X01, 0XC4, 0X01, 0XC4, 0XE2, 0XC3, 0X24, 0XC4,
    0X68, 0XBC, 0XAC, 0XBC, 0XD3, 0XCD, 0X9E, 0XF7, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF,
    0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF,
    0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF,
    0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF,
    0X5B, 0XEF, 0X98, 0XDE, 0X56, 0XD6, 0X57, 0XD6, 0X57, 0XD6, 0X56, 0XD6, 0X77, 0XDE, 0X1B, 0XEF,
    0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF,
    0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF,
    0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF,
    0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF,
    0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF,
    0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF,
    0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF,
};

const unsigned char PROGMEM wifi_full[2048] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x49, 0x21, 0x71, 0xC2, 0x71, 0xC2, 0x71, 0xC2, 0x71, 0xC2,
    0x71, 0xC2, 0x71, 0xC2, 0x71, 0xC2, 0x71, 0xC2, 0x71, 0xC2, 0x71, 0xC2, 0x71, 0xC2, 0x71, 0xC2,
    0x71, 0xC2, 0x71, 0xC2, 0x71, 0xC2, 0x71, 0xC2, 0x71, 0xC2, 0x71, 0xC2, 0x71, 0xC2, 0x71, 0xC2,
    0x71, 0xC2, 0x71, 0xC2, 0x71, 0xC2, 0x71, 0xC2, 0x41, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x28, 0xA0, 0xCB, 0x23, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4,
    0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4,
    0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4,
    0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xC3, 0x03, 0x18, 0x60, 0x00, 0x00,
    0x08, 0x20, 0xD3, 0x23, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4,
    0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4,
    0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4,
    0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xC3, 0x03, 0x00, 0x00,
    0x59, 0x61, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4,
    0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4,
    0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4,
    0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0x41, 0x01,
    0x8A, 0x22, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4,
    0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4,
    0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4,
    0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0x71, 0xC2,
    0x92, 0x42, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4,
    0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4,
    0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4,
    0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0x71, 0xC2,
    0x92, 0x42, 0xF4, 0x89, 0xFE, 0x34, 0xFE, 0xB7, 0xFF, 0x19, 0xFF, 0x3A, 0xFF, 0x3A, 0xFE, 0xD8,
    0xFE, 0x76, 0xF5, 0xD1, 0xF5, 0x0C, 0xEB, 0xE6, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4,
    0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4,
    0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0x71, 0xC2,
    0x92, 0x42, 0xF4, 0xEC, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x19, 0xF5, 0x90, 0xEC, 0x06, 0xEB, 0xA4,
    0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4,
    0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0x71, 0xC2,
    0x92, 0x42, 0xF4, 0x06, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0x54,
    0xF4, 0x47, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4,
    0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0x71, 0xC2,
    0x92, 0x42, 0xEB, 0xA4, 0xFF, 0x9D, 0xFF, 0xFF, 0xFF, 0xBD, 0xFF, 0x7C, 0xFF, 0x7C, 0xFF, 0x9D,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xF6, 0x13, 0xEB, 0xE5, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4,
    0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0x71, 0xC2,
    0x92, 0x42, 0xEB, 0xA4, 0xF4, 0x47, 0xEB, 0xE5, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4,
    0xEB, 0xC4, 0xF4, 0x48, 0xF5, 0x2E, 0xFE, 0x55, 0xFF, 0xBD, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x7C, 0xF4, 0xAA, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4,
    0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0x71, 0xC2,
    0x92, 0x42, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4,
    0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xC4, 0xF5, 0x0C, 0xFE, 0xF9, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xF5, 0xB1, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4,
    0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0x71, 0xC2,
    0x92, 0x42, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xF4, 0x27, 0xF4, 0xCB, 0xF5, 0x0C, 0xF5, 0x0C,
    0xF4, 0xAB, 0xF4, 0x27, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xF4, 0xEC,
    0xFF, 0x7C, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0x34, 0xEB, 0xC4, 0xEB, 0xA4,
    0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0x71, 0xC2,
    0x92, 0x42, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xFE, 0xF8, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x9D, 0xFE, 0x76, 0xF4, 0xEC, 0xEB, 0xC4, 0xEB, 0xA4, 0xEB, 0xA4,
    0xEB, 0xC5, 0xFE, 0x34, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0x55, 0xEB, 0xA4,
    0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0x71, 0xC2,
    0x92, 0x42, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xF6, 0x13, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x7C, 0xF5, 0x6F, 0xEB, 0xC4,
    0xEB, 0xA4, 0xEB, 0xA4, 0xF5, 0x4E, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xF5, 0xF2,
    0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0x71, 0xC2,
    0x92, 0x42, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xF4, 0x69, 0xF5, 0x0C, 0xF4, 0xAA, 0xF4, 0x89,
    0xF4, 0xCB, 0xF5, 0x6F, 0xFE, 0x55, 0xFF, 0x9D, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x1A,
    0xF4, 0x48, 0xEB, 0xA4, 0xEB, 0xA4, 0xF5, 0x0C, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xF5, 0x0D, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0x71, 0xC2,
    0x92, 0x42, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4,
    0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xC4, 0xF4, 0xEC, 0xFF, 0x19, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xDE, 0xF5, 0x0D, 0xEB, 0xA4, 0xEB, 0xA4, 0xF5, 0x4E, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xBE, 0xF4, 0x27, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0x71, 0xC2,
    0x92, 0x42, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4,
    0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xF5, 0x4E, 0xFF, 0xDE,
    0xFF, 0xFF, 0xFF, 0xFF, 0xF5, 0x4E, 0xEB, 0xA4, 0xEB, 0xA4, 0xFE, 0x54, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFE, 0xB7, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0x71, 0xC2,
    0x92, 0x42, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xC4, 0xFF, 0x3A, 0xFF, 0x9D,
    0xFF, 0x9C, 0xFF, 0x19, 0xF6, 0x13, 0xF4, 0xAA, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xF4, 0x48,
    0xFF, 0x7C, 0xFF, 0xFF, 0xFF, 0xFF, 0xF4, 0xEC, 0xEB, 0xA4, 0xEB, 0xC5, 0xFF, 0x7C, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xF4, 0xEC, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0x71, 0xC2,
    0x92, 0x42, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xFE, 0xD8, 0xFF, 0x19,
    0xFF, 0x19, 0xFF, 0x9C, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x1A, 0xF4, 0xAA, 0xEB, 0xA4, 0xEB, 0xA4,
    0xF4, 0x47, 0xFF, 0x9D, 0xFF, 0xFF, 0xFF, 0xBE, 0xF4, 0x47, 0xEB, 0xA4, 0xF4, 0xEC, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x19, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0x71, 0xC2,
    0x92, 0x42, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4,
    0xEB, 0xA4, 0xEB, 0xA4, 0xF4, 0x27, 0xF5, 0xD1, 0xFF, 0xBD, 0xFF, 0xFF, 0xF5, 0xD2, 0xEB, 0xA4,
    0xEB, 0xA4, 0xF4, 0xAA, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0xD8, 0xEB, 0xA4, 0xEB, 0xA4, 0xFE, 0xF9,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xF4, 0xCB, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0x71, 0xC2,
    0x92, 0x42, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4,
    0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEC, 0x06, 0xFE, 0xB7, 0xFF, 0xFF, 0xFE, 0x34,
    0xEB, 0xA4, 0xEB, 0xA4, 0xF6, 0x13, 0xFF, 0xFF, 0xFF, 0xFF, 0xF4, 0xEC, 0xEB, 0xA4, 0xF5, 0x0C,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0x55, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0x71, 0xC2,
    0x92, 0x42, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4,
    0xF4, 0x27, 0xF5, 0x4E, 0xF5, 0x2D, 0xEB, 0xE5, 0xEB, 0xA4, 0xEB, 0xC4, 0xFE, 0x96, 0xFF, 0xFF,
    0xF5, 0x6F, 0xEB, 0xA4, 0xEB, 0xE5, 0xFF, 0xBE, 0xFF, 0xFF, 0xFE, 0xF9, 0xEB, 0xA4, 0xEB, 0xC4,
    0xFF, 0x9D, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xDE, 0xEB, 0xC5, 0xEB, 0xA4, 0xEB, 0xA4, 0x71, 0xC2,
    0x92, 0x42, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xEB, 0xA4, 0xF4, 0xEC,
    0xFF, 0xDF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x9D, 0xEC, 0x48, 0xEB, 0x84, 0xEB, 0xC5, 0xFF, 0x5B,
    0xFF, 0xDE, 0xEC, 0x07, 0xE3, 0x84, 0xF5, 0xF3, 0xFF, 0xFF, 0xFF, 0xFF, 0xEC, 0x28, 0xE3, 0x84,
    0xF6, 0x14, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xEC, 0xAB, 0xE3, 0x64, 0xE3, 0x64, 0x79, 0xE2,
    0xAA, 0x64, 0xB2, 0x84, 0xB2, 0x84, 0xB2, 0x84, 0xB2, 0x84, 0xB2, 0x84, 0xB2, 0xC5, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xEE, 0x98, 0xB2, 0x84, 0xB2, 0x84, 0xC4, 0x0C,
    0xFF, 0xFF, 0xDD, 0x93, 0xB2, 0x84, 0xBB, 0x69, 0xFF, 0xFF, 0xFF, 0xFF, 0xD5, 0x11, 0xB2, 0x84,
    0xCC, 0x4D, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xDD, 0x32, 0xB2, 0x84, 0xB2, 0x84, 0x92, 0x23,
    0xAA, 0x64, 0xB2, 0x84, 0xB2, 0x84, 0xB2, 0x84, 0xB2, 0x84, 0xB2, 0x84, 0xC3, 0x8A, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xDF, 0xB2, 0x84, 0xB2, 0x84, 0xB2, 0x84,
    0xF7, 0x3B, 0xFF, 0x9D, 0xB2, 0x85, 0xB2, 0x84, 0xF7, 0x5C, 0xEE, 0xFA, 0xD4, 0xD0, 0xB2, 0x84,
    0xB2, 0xE6, 0xDD, 0x93, 0xCC, 0x6E, 0xBB, 0x68, 0xB2, 0x85, 0xB2, 0x84, 0xB2, 0x84, 0x92, 0x23,
    0xAA, 0x64, 0xB2, 0x84, 0xB2, 0x84, 0xB2, 0x84, 0xB2, 0x84, 0xB2, 0x84, 0xBB, 0x07, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xF7, 0x5C, 0xB2, 0x84, 0xB2, 0x84, 0xB2, 0x84,
    0xDD, 0x52, 0xEE, 0xD9, 0xBB, 0x07, 0xB2, 0x84, 0xB2, 0x85, 0xB2, 0x84, 0xB2, 0x84, 0xB2, 0x84,
    0xB2, 0x84, 0xB2, 0x84, 0xB2, 0x84, 0xB2, 0x84, 0xB2, 0x84, 0xB2, 0x84, 0xB2, 0x84, 0x92, 0x23,
    0xA2, 0x64, 0xB2, 0x84, 0xB2, 0x84, 0xB2, 0x84, 0xB2, 0x84, 0xB2, 0x84, 0xB2, 0x84, 0xE5, 0xD5,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xCC, 0xAF, 0xB2, 0x84, 0xB2, 0x84, 0xB2, 0x84,
    0xB2, 0x84, 0xB2, 0x84, 0xB2, 0x84, 0xB2, 0x84, 0xB2, 0x84, 0xB2, 0x84, 0xB2, 0x84, 0xB2, 0x84,
    0xB2, 0x84, 0xB2, 0x84, 0xB2, 0x84, 0xB2, 0x84, 0xB2, 0x84, 0xB2, 0x84, 0xB2, 0x84, 0x92, 0x23,
    0x9A, 0x43, 0xB2, 0x84, 0xB2, 0x84, 0xB2, 0x84, 0xB2, 0x84, 0xB2, 0x84, 0xB2, 0x84, 0xB2, 0xA5,
    0xD4, 0xF0, 0xEE, 0x99, 0xEE, 0x78, 0xCC, 0x4D, 0xB2, 0x84, 0xB2, 0x84, 0xB2, 0x84, 0xB2, 0x84,
    0xB2, 0x84, 0xB2, 0x84, 0xB2, 0x84, 0xB2, 0x84, 0xB2, 0x84, 0xB2, 0x84, 0xB2, 0x84, 0xB2, 0x84,
    0xB2, 0x84, 0xB2, 0x84, 0xB2, 0x84, 0xB2, 0x84, 0xB2, 0x84, 0xB2, 0x84, 0xB2, 0x84, 0x79, 0xC3,
    0x81, 0xE3, 0xB2, 0x84, 0xB2, 0x84, 0xB2, 0x84, 0xB2, 0x84, 0xB2, 0x84, 0xB2, 0x84, 0xB2, 0x84,
    0xB2, 0x84, 0xB2, 0x84, 0xB2, 0x84, 0xB2, 0x84, 0xB2, 0x84, 0xB2, 0x84, 0xB2, 0x84, 0xB2, 0x84,
    0xB2, 0x84, 0xB2, 0x84, 0xB2, 0x84, 0xB2, 0x84, 0xB2, 0x84, 0xB2, 0x84, 0xB2, 0x84, 0xB2, 0x84,
    0xB2, 0x84, 0xB2, 0x84, 0xB2, 0x84, 0xB2, 0x84, 0xB2, 0x84, 0xB2, 0x84, 0xB2, 0x84, 0x59, 0x42,
    0x79, 0xC3, 0xB2, 0x84, 0xB2, 0x84, 0xB2, 0x84, 0xB2, 0x84, 0xB2, 0x84, 0xB2, 0x84, 0xB2, 0x84,
    0xB2, 0x84, 0xB2, 0x84, 0xB2, 0x84, 0xB2, 0x84, 0xB2, 0x84, 0xB2, 0x84, 0xB2, 0x84, 0xB2, 0x84,
    0xB2, 0x84, 0xB2, 0x84, 0xB2, 0x84, 0xB2, 0x84, 0xB2, 0x84, 0xB2, 0x84, 0xB2, 0x84, 0xB2, 0x84,
    0xB2, 0x84, 0xB2, 0x84, 0xB2, 0x84, 0xB2, 0x84, 0xB2, 0x84, 0xB2, 0x84, 0xB2, 0x84, 0x59, 0x42,
    0x51, 0x42, 0x79, 0xC3, 0x79, 0xC3, 0x9A, 0x23, 0xA2, 0x63, 0xA2, 0x63, 0xA2, 0x63, 0xA2, 0x63,
    0xA2, 0x63, 0xA2, 0x63, 0xA2, 0x63, 0xA2, 0x63, 0xA2, 0x63, 0xA2, 0x63, 0xA2, 0x63, 0xA2, 0x63,
    0xA2, 0x63, 0xA2, 0x63, 0xA2, 0x63, 0xA2, 0x63, 0xA2, 0x63, 0xA2, 0x63, 0xA2, 0x63, 0xA2, 0x63,
    0xA2, 0x63, 0xA2, 0x63, 0xA2, 0x63, 0xA2, 0x63, 0x92, 0x23, 0x79, 0xC3, 0x79, 0xC3, 0x38, 0xE1,
};
