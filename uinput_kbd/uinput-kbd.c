#include <linux/uinput.h>
#include <stddef.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include "input-keymap.h"
#include "stdio.h"

int fd;

void emit(int fd, int type, int code, int val)
{
   struct input_event ie;

   ie.type = type;
   ie.code = code;
   ie.value = val;
   /* timestamp values below are ignored */
   ie.time.tv_sec = 0;
   ie.time.tv_usec = 0;

   write(fd, &ie, sizeof(ie));
}

void destroy_uinputkbd()
{
   ioctl(fd, UI_DEV_DESTROY);
}

void init_uinputkbd()
{
   struct uinput_setup usetup;

   fd = open("/dev/uinput", O_WRONLY | O_NONBLOCK);


   /*
    * The ioctls below will enable the device that is about to be
    * created, to pass key events, in this case the space key.
    */
   ioctl(fd, UI_SET_EVBIT, EV_KEY);

   for (size_t i = 1; i<=70; i++) {
      ioctl(fd, UI_SET_KEYBIT, i);
   }

   memset(&usetup, 0, sizeof(usetup));
   usetup.id.bustype = BUS_VIRTUAL;
   usetup.id.vendor = 0x1234; /* sample vendor */
   usetup.id.product = 0x5678; /* sample product */
   strcpy(usetup.name, "x-virtual-keyboard");

   ioctl(fd, UI_DEV_SETUP, &usetup);
   ioctl(fd, UI_DEV_CREATE);

}

void emit_js_event(char *jskey, char *jsvalue) {
   int value;
   for (size_t i = 0; i < sizeof(key_value_labels) / sizeof(*key_value_labels); i++) 
        if ( strcmp(jsvalue, key_value_labels[i].js) == 0 ) 
         value = key_value_labels[i].keyvalue;

   for (size_t i = 0; i < sizeof(key_code_labels) / sizeof(*key_code_labels); i++) {
        if ( strcmp(jskey, key_code_labels[i].js) == 0 ) {
            emit(fd, EV_KEY, key_code_labels[i].keycode, value);
            emit(fd, EV_SYN, SYN_REPORT, 0);
            return;
        }
   }
}
