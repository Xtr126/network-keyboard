#include <linux/input-event-codes.h>
static const struct {
    int keycode; const char* js; 
} key_code_labels[] = {
    { KEY_0, "0" },
    { KEY_1, "1" },
    { KEY_2, "2" },
    { KEY_3, "3" },
    { KEY_4, "4" },
    { KEY_5, "5" },
    { KEY_6, "6" },
    { KEY_7, "7" },
    { KEY_8, "8" },
    { KEY_9, "9" },
    { KEY_A, "A" },
    { KEY_B, "B" },
    { KEY_C, "C" },
    { KEY_D, "D" },
    { KEY_E, "E" },
    { KEY_F, "F" },
    { KEY_G, "G" },
    { KEY_H, "H" },
    { KEY_I, "I" },
    { KEY_J, "J" },
    { KEY_K, "K" },
    { KEY_L, "L" },
    { KEY_M, "M" },
    { KEY_N, "N" },
    { KEY_O, "O" },
    { KEY_P, "P" },
    { KEY_Q, "Q" },
    { KEY_R, "R" },
    { KEY_S, "S" },
    { KEY_T, "T" },
    { KEY_U, "U" },
    { KEY_V, "V" },
    { KEY_W, "W" },
    { KEY_X, "X" },
    { KEY_Y, "Y" },
    { KEY_Z, "Z" },
    { KEY_COMMA, "<" },
    { KEY_DOT, ">" },
    { KEY_MINUS, "-" },
    { KEY_SEMICOLON, ":" },
    { KEY_APOSTROPHE, "\"" },
    { KEY_SLASH, "?" },
    { KEY_EQUAL, "=" },
    { KEY_GRAVE, "`" },
    { KEY_BACKSLASH, "|" },
    { KEY_LEFTBRACE, "{" },
    { KEY_RIGHTBRACE, "}" },
    { KEY_ENTER, "{enter}" },
    { KEY_SPACE, "{space}" },
    { KEY_BACKSPACE, "{backspace}" },
    { KEY_LEFTSHIFT, "{shiftleft}" },
    { KEY_UP, "{arrowup}" },
    { KEY_DOWN, "{arrowdown}" },
    { KEY_LEFT, "{arrowleft}" },
    { KEY_RIGHT, "{arrowright}" },
    { KEY_LEFTALT, "{altleft}" },
    { KEY_RIGHTALT, "{altright}" },
    { KEY_LEFTCTRL, "{controlleft}" },
    { KEY_RIGHTCTRL, "{controlright}" },
    { KEY_LEFTMETA, "{meta}" },    
    { KEY_TAB, "{tab}" },
    { KEY_F1, "f1" },
    { KEY_F2, "f2" },
    { KEY_F3, "f3" },
    { KEY_F4, "f4" },
    { KEY_F5, "f5" },
    { KEY_F6, "f6" },
    { KEY_F7, "f7" },
    { KEY_F8, "f8" },
    { KEY_F9, "f9" },
    { KEY_F10, "f10" },
    { KEY_F11, "f11" },
    { KEY_F12, "f12" },    
    { KEY_CAPSLOCK, "{capslock}" },    
    { KEY_ESC, "esc" },
};

static const struct { const char* js; int keyvalue;  } key_value_labels[] = {
        { "up", 0 },
        { "down", 1 },
        { "repeat", 2 },
};
