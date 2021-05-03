#include "kbdcodes.h"

// this is a map of the keycode characters and the character to be returned for the keycode
const unsigned short keyCodes[][128] = {

    // US Layout
    {                                                                          //Base 10   Hex
       0,  KEY_F9,       0,  KEY_F5,  KEY_F3,  KEY_F1,  KEY_F2, KEY_F12,       //00-07    00-07
       0, KEY_F10,  KEY_F8,  KEY_F6,  KEY_F4, KEY_TAB,     '`',       0,       //08-15    08-0F
       0, KEY_ALT,  L_SHFT,      0,     CTRL,     'q',     '1',       0,       //16-23    10-07
       0,       0,     'z',     's',     'a',     'w',     '2',       0,       //24-31    18-1F
       0,     'c',     'x',     'd',     'e',     '4',     '3',       0,       //32-39    20-27
       0,     ' ',     'v',     'f',     't',     'r',     '5',       0,       //40-48    28-2F
       0,     'n',     'b',     'h',     'g',     'y',     '6',       0,       //48-56    30-37
       0,       0,     'm',     'j',     'u',     '7',     '8',       0,       //56-63    38-3F
       0,     ',',     'k',     'i',     'o',     '0',     '9',       0,       //64-71    40-47
       0,     '.',     '/',     'l',     ';',     'p',     '-',       0,       //72-79    48-4F
       0,       0,    '\'',       0,     '[',     '=',       0,       0,       //80-87    50-57
    CAPS,  R_SHFT, KEY_ENT,     ']',      0,     '\\',       0,       0,       //88-95    58-5F
       0,       0,       0,       0,       0,       0, KEY_BSP,       0,       //96-103   60-67
       0,     '1',       0,     '4',     '7',       0,       0,       0,       //104-111  68-6F
     '0',     '.',     '2',     '5',     '6',     '8', KEY_ESC,    NUML,       //112-119  70-77
 KEY_F11,     '+',     '3',     '-',     '*',     '9',       0,       0        //120-127  78-7F
    },
    
    // US Layout (SHIFT)
    {                                                                           //Base 10   Hex
        0,  KEY_F9,       0,  KEY_F5,  KEY_F3,  KEY_F1,  KEY_F2, KEY_F12,       //00-07    00-07
        0, KEY_F10,  KEY_F8,  KEY_F6,  KEY_F4, KEY_TAB,     '~',       0,       //08-15    08-0F
        0, KEY_ALT,  L_SHFT,      0,     CTRL,     'Q',     '!',       0,       //16-23    10-07
        0,       0,     'Z',     'S',     'A',     'W',     '@',       0,       //24-31    18-1F
        0,     'C',     'X',     'D',     'E',     '$',     '#',       0,       //32-39    20-27
        0,     ' ',     'V',     'F',     'T',     'R',     '%',       0,       //40-47    28-2F
        0,     'N',     'B',     'H',     'G',     'Y',     '^',       0,       //48-55    30-37
        0,       0,     'M',     'J',     'U',     '&',     '*',       0,       //56-63    38-3F
        0,     '<',     'K',     'I',     'O',     ')',     '(',       0,       //64-71    40-47
        0,     '>',     '?',     'L',     ':',     'P',     '_',       0,       //72-79    48-4F
        0,       0,    '\"',       0,     '{',     '+',       0,       0,       //80-87    50-57
     CAPS,  R_SHFT, KEY_ENT,     '}',       0,     '|',       0,       0,       //88-95    58-5F
        0,       0,       0,       0,       0,       0, KEY_BSP,       0,       //96-103   60-67
        0,     '1',       0,     '4',     '7',       0,       0,       0,       //104-111  68-6F
       '0',    '.',     '2',     '5',     '6',     '8', KEY_ESC,    NUML,       //112-119  70-77
  KEY_F11,     '+',     '3',     '-',     '*',     '9',       0,       0        //120-127  78-7F
    },
    
    // ==========================================================================================

    // UK Layout
    {                                                                          //Base 10   Hex
       0,  KEY_F9,       0,  KEY_F5,  KEY_F3,  KEY_F1,  KEY_F2, KEY_F12,       //00-07    00-07
       0, KEY_F10,  KEY_F8,  KEY_F6,  KEY_F4, KEY_TAB,     '`',       0,       //08-15    08-0F
       0, KEY_ALT,  L_SHFT,    '\\',    CTRL,     'q',     '1',       0,       //16-23    10-07
       0,       0,     'z',     's',     'a',     'w',     '2',       0,       //24-31    18-1F
       0,     'c',     'x',     'd',     'e',     '4',     '3',       0,       //32-39    20-27
       0,     ' ',     'v',     'f',     't',     'r',     '5',       0,       //40-48    28-2F
       0,     'n',     'b',     'h',     'g',     'y',     '6',       0,       //48-56    30-37
       0,       0,     'm',     'j',     'u',     '7',     '8',       0,       //56-63    38-3F
       0,     ',',     'k',     'i',     'o',     '0',     '9',       0,       //64-71    40-47
       0,     '.',     '/',     'l',     ';',     'p',     '-',       0,       //72-79    48-4F
       0,       0,    '\'',       0,     '[',     '=',    '\\',       0,       //80-87    50-57
    CAPS,  R_SHFT, KEY_ENT,     ']',     '#',     '#',       0,       0,       //88-95    58-5F
       0,    '\\',       0,       0,       0,       0, KEY_BSP,       0,       //96-103   60-67
       0,     '1',       0,     '4',     '7',       0,       0,       0,       //104-111  68-6F
     '0',     '.',     '2',     '5',     '6',     '8', KEY_ESC,    NUML,       //112-119  70-77
 KEY_F11,     '+',     '3',     '-',     '*',     '9',       0,       0        //120-127  78-7F
    },
    
    // UK Layout (SHIFT)
    {                                                                           //Base 10   Hex
        0,  KEY_F9,       0,  KEY_F5,  KEY_F3,  KEY_F1,  KEY_F2, KEY_F12,       //00-07    00-07
        0, KEY_F10,  KEY_F8,  KEY_F6,  KEY_F4, KEY_TAB,  '\xAA',       0,       //08-15    08-0F
        0, KEY_ALT,  L_SHFT,     '|',    CTRL,     'Q',     '!',       0,       //16-23    10-07
        0,       0,     'Z',     'S',     'A',     'W',    '\"',       0,       //24-31    18-1F
        0,     'C',     'X',     'D',     'E',     '$',  '\x9C',       0,       //32-39    20-27
        0,     ' ',     'V',     'F',     'T',     'R',     '%',       0,       //40-47    28-2F
        0,     'N',     'B',     'H',     'G',     'Y',     '^',       0,       //48-55    30-37
        0,       0,     'M',     'J',     'U',     '&',     '*',       0,       //56-63    38-3F
        0,     '<',     'K',     'I',     'O',     ')',     '(',       0,       //64-71    40-47
        0,     '>',     '?',     'L',     ':',     'P',     '_',       0,       //72-79    48-4F
        0,       0,     '@',       0,     '{',     '+',     '|',       0,       //80-87    50-57
     CAPS,  R_SHFT, KEY_ENT,     '}',     '~',     '~',       0,       0,       //88-95    58-5F
        0,     '|',       0,       0,       0,       0, KEY_BSP,       0,       //96-103   60-67
        0,     '1',       0,     '4',     '7',       0,       0,       0,       //104-111  68-6F
       '0',    '.',     '2',     '5',     '6',     '8', KEY_ESC,    NUML,       //112-119  70-77
  KEY_F11,     '+',     '3',     '-',     '*',     '9',       0,       0        //120-127  78-7F
    },
    
    // ==========================================================================================
    
    // DE Layout
    // dead keys: 0x0E (without Shift), 0x55
    {                                                                           //Base 10   Hex
        0,  KEY_F9,       0,  KEY_F5,  KEY_F3,  KEY_F1,  KEY_F2, KEY_F12,       //00-07    00-07
        0, KEY_F10,  KEY_F8,  KEY_F6,  KEY_F4, KEY_TAB,       0,       0,       //08-15    08-0F
        0, KEY_ALT,  L_SHFT,      0,     CTRL,     'q',     '1',       0,       //16-23    10-07
        0,       0,     'y',     's',     'a',     'w',     '2',       0,       //24-31    18-1F
        0,     'c',     'x',     'd',     'e',     '4',     '3',       0,       //32-39    20-27
        0,     ' ',     'v',     'f',     't',     'r',     '5',       0,       //40-47    28-2F
        0,     'n',     'b',     'h',     'g',     'z',     '6',       0,       //48-55    30-37
        0,       0,     'm',     'j',     'u',     '7',     '8',       0,       //56-63    38-3F
        0,     ',',     'k',     'i',     'o',     '0',     '9',       0,       //64-71    40-47
        0,     '.',     '-',     'l',  '\x94',     'p',  '\xE2',       0,       //72-79    48-4F
        0,       0,       0,       0,  '\x81',       0,  '\x84',       0,       //80-87    50-57
     CAPS,  R_SHFT, KEY_ENT,     '+',      0,      '#',       0,       0,       //88-95    58-5F
        0,     '<',       0,       0,       0,       0, KEY_BSP,       0,       //96-103   60-67
        0,     '1',       0,     '4',     '7',       0,       0,       0,       //104-111  68-6F
      '0',     '.',     '2',     '5',     '6',     '8', KEY_ESC,    NUML,       //112-119  70-77
  KEY_F11,     '+',     '3',     '-',     '*',     '9',       0,       0        //120-127  78-7F
    },
    
    // DE Layout (SHIFT)
    {                                                                           //Base 10   Hex
        0,  KEY_F9,       0,  KEY_F5,  KEY_F3,  KEY_F1,  KEY_F2, KEY_F12,       //00-07    00-07
        0, KEY_F10,  KEY_F8,  KEY_F6,  KEY_F4, KEY_TAB,  '\xF8',       0,       //08-15    08-0F
        0, KEY_ALT,  L_SHFT,      0,     CTRL,     'Q',     '!',       0,       //16-23    10-07
        0,       0,     'Y',     'S',     'A',     'W',    '\"',       0,       //24-31    18-1F
        0,     'C',     'X',     'D',     'E',     '$',       0,       0,       //32-39    20-27
        0,     ' ',     'V',     'F',     'T',     'R',     '%',       0,       //40-47    28-2F
        0,     'N',     'B',     'H',     'G',     'Z',     '&',       0,       //48-55    30-37
        0,       0,     'M',     'J',     'U',     '/',     '(',       0,       //56-63    38-3F
        0,     ';',     'K',     'I',     'O',     '=',     ')',       0,       //64-71    40-47
        0,     ':',     '_',     'L',  '\x99',     'P',     '?',       0,       //72-79    48-4F
        0,       0,       0,       0,  '\x9A',       0,  '\x8E',       0,       //80-87    50-57
     CAPS,  R_SHFT, KEY_ENT,     '*',       0,       0,       0,       0,       //88-95    58-5F
        0,     '>',       0,       0,       0,       0, KEY_BSP,       0,       //96-103   60-67
        0,     '1',       0,     '4',     '7',       0,       0,       0,       //104-111  68-6F
       '0',    '.',     '2',     '5',     '6',     '8', KEY_ESC,    NUML,       //112-119  70-77
  KEY_F11,     '+',     '3',     '-',     '*',     '9',       0,       0        //120-127  78-7F
    },
    
    // ==========================================================================================

    // FR Layout
    // dead keys: 0x54
    {                                                                           //Base 10   Hex
        0,  KEY_F9,       0,  KEY_F5,  KEY_F3,  KEY_F1,  KEY_F2, KEY_F12,       //00-07    00-07
        0, KEY_F10,  KEY_F8,  KEY_F6,  KEY_F4, KEY_TAB,  '\xFD',       0,       //08-15    08-0F
        0, KEY_ALT,  L_SHFT,      0,     CTRL,     'a',     '&',       0,       //16-23    10-07
        0,       0,     'w',     's',     'q',     'z',  '\x82',       0,       //24-31    18-1F
        0,     'c',     'x',     'd',     'e',     '\'',    '"',       0,       //32-39    20-27
        0,     ' ',     'v',     'f',     't',     'r',     '(',       0,       //40-48    28-2F
        0,     'n',     'b',     'h',     'g',     'y',     '-',       0,       //48-56    30-37
        0,       0,     ',',     'j',     'u',  '\x8A',     '_',       0,       //56-63    38-3F
        0,     ';',     'k',     'i',     'o',  '\x85',  '\x87',       0,       //64-71    40-47
        0,     ':',     '!',     'l',     'm',     'p',     ')',       0,       //72-79    48-4F
        0,       0,  '\x97',       0,       0,     '=',       0,       0,       //80-87    50-57
     CAPS,  R_SHFT, KEY_ENT,     '$',       0,     '*',       0,       0,       //88-95    58-5F
        0,     '<',       0,       0,       0,       0, KEY_BSP,       0,       //96-103   60-67
        0,     '1',       0,     '4',     '7',       0,       0,       0,       //104-111  68-6F
      '0',     '.',     '2',     '5',     '6',     '8', KEY_ESC,    NUML,       //112-119  70-77
  KEY_F11,     '+',     '3',     '-',     '*',     '9',       0,       0        //120-127  78-7F
    },
    
    // FR Layout (SHIFT)
    {                                                                           //Base 10   Hex
        0,  KEY_F9,       0,  KEY_F5,  KEY_F3,  KEY_F1,  KEY_F2, KEY_F12,       //00-07    00-07
        0, KEY_F10,  KEY_F8,  KEY_F6,  KEY_F4, KEY_TAB,       0,       0,       //08-15    08-0F
        0, KEY_ALT,  L_SHFT,      0,     CTRL,     'A',     '1',       0,       //16-23    10-07
        0,       0,     'W',     'S',     'Q',     'Z',     '2',       0,       //24-31    18-1F
        0,     'C',     'X',     'D',     'E',     '4',     '3',       0,       //32-39    20-27
        0,     ' ',     'V',     'F',     'T',     'R',     '5',       0,       //40-47    28-2F
        0,     'N',     'B',     'H',     'G',     'Y',     '6',       0,       //48-55    30-37
        0,       0,     '?',     'J',     'U',     '7',     '8',       0,       //56-63    38-3F
        0,     '.',     'K',     'I',     'O',     '0',     '9',       0,       //64-71    40-47
        0,     '/',  '\x15',     'L',     'M',     'P',  '\xF8',       0,       //72-79    48-4F
        0,       0,     '%',       0,       0,     '+',       0,       0,       //80-87    50-57
     CAPS,  R_SHFT, KEY_ENT,  '\x9C',       0,  '\xE6',       0,       0,       //88-95    58-5F
        0,     '>',       0,       0,       0,       0, KEY_BSP,       0,       //96-103   60-67
        0,     '1',       0,     '4',     '7',       0,       0,       0,       //104-111  68-6F
       '0',    '.',     '2',     '5',     '6',     '8', KEY_ESC,    NUML,       //112-119  70-77
  KEY_F11,     '+',     '3',     '-',     '*',     '9',       0,       0        //120-127  78-7F
    }

};
