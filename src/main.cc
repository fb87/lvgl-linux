// vim:tabstop=4 softtabstop=4 shiftwidth=4 colorcolumn=80 autoindent expandtab

#include <stdlib.h>
#include <unistd.h>

#include <lvgl.h>

static void build_main_ui(void);

int main(int argc, char *argv[]) {
    lv_init();

    lv_display_t *dpy = lv_sdl_window_create(800, 600);
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

static void build_main_ui(void) {
    lv_obj_t * spinner = lv_spinner_create(lv_screen_active());
    lv_obj_set_size(spinner, 100, 100);
    lv_obj_center(spinner);
    lv_spinner_set_anim_params(spinner, 10000, 200);
}

