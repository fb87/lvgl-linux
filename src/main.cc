// vim:tabstop=4 softtabstop=4 shiftwidth=4 colorcolumn=80 autoindent expandtab

#include <stdlib.h>
#include <unistd.h>

#include <lvgl.h>

static void build_main_ui(void);

int main(int argc, char *argv[]) {
    lv_init();

    lv_display_t *dpy = lv_sdl_window_create(640, 720);
    lv_indev_set_display(lv_sdl_mouse_create(), dpy);
    lv_indev_set_display(lv_sdl_keyboard_create(), dpy);

    build_main_ui();

    while(1) {
        lv_timer_handler();
        usleep(10* 1000);
    }

    lv_deinit();
    return 0;
}


extern void draw_background(void);
extern void speedometer(void);

static void build_main_ui(void) {
    draw_background();
    speedometer();
}

