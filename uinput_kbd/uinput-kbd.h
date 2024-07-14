#include <linux/input-event-codes.h>

void emit_js_event(char *jskey, char *jsvalue);
void destroy_uinputkbd();
void init_uinputkbd();