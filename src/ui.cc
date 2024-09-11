// vim:tabstop=4 softtabstop=4 shiftwidth=4 colorcolumn=80 autoindent expandtab
#include <lvgl.h>

void draw_background(void)
{
    static const lv_color_t grad_colors[2] = {
        LV_COLOR_MAKE(0x9B, 0x18, 0x42),
        LV_COLOR_MAKE(0x00, 0x00, 0x00),
    };

    int32_t width = lv_display_get_horizontal_resolution(NULL);
    int32_t height = lv_display_get_vertical_resolution(NULL);

    static lv_style_t style;
    lv_style_init(&style);

    static lv_grad_dsc_t grad;

    lv_gradient_init_stops(&grad, grad_colors, NULL, NULL, sizeof(grad_colors) / sizeof(lv_color_t));

    lv_grad_radial_init(&grad, LV_GRAD_CENTER, LV_GRAD_BOTTOM, LV_GRAD_RIGHT, LV_GRAD_BOTTOM, LV_GRAD_EXTEND_PAD);

    lv_style_set_bg_grad(&style, &grad);

    lv_obj_t * obj = lv_obj_create(lv_screen_active());
    lv_obj_add_style(obj, &style, 0);
    lv_obj_set_size(obj, width, height);
    lv_obj_center(obj);
}

void telltale(lv_obj_t *parent, const char *text)
{
    static lv_style_t style;
    lv_style_init(&style);

    /*Set a background color and a radius*/
    lv_style_set_radius(&style, 5);
    lv_style_set_bg_opa(&style, LV_OPA_COVER);
    lv_style_set_bg_color(&style, lv_palette_lighten(LV_PALETTE_GREY, 1));

    /*Add a shadow*/
    lv_style_set_shadow_width(&style, 25);
    lv_style_set_shadow_color(&style, lv_palette_main(LV_PALETTE_BLUE));

    lv_obj_t * obj = lv_obj_create(parent);
    lv_obj_add_style(obj, &style, 0);
    lv_obj_set_size(obj, 50, 50);
    lv_obj_center(obj);
    lv_obj_set_scrollbar_mode(obj, LV_SCROLLBAR_MODE_OFF);
    
    lv_obj_t *label = lv_label_create(obj);
    lv_label_set_text(label, text);
    lv_obj_set_style_radius(obj, LV_RADIUS_CIRCLE, 0);
    lv_obj_center(label);
}

void lv_example_scale_3(void)
{
    const unsigned int width = 300;
    const unsigned int indicator_width = 70;

    lv_obj_t *arc = lv_arc_create(lv_screen_active());
    lv_obj_set_size(arc, width, width);

    lv_arc_set_rotation(arc, 135);
    lv_arc_set_bg_angles(arc, 0, 270);

    lv_arc_set_value(arc, 10);
    lv_obj_set_style_arc_width(arc, indicator_width, LV_PART_MAIN);
    lv_obj_set_style_arc_rounded(arc, false, LV_PART_MAIN);
    lv_obj_set_style_arc_width(arc, indicator_width, LV_PART_INDICATOR);
    lv_obj_set_style_arc_rounded(arc, false, LV_PART_INDICATOR);

    lv_obj_set_style_arc_color(arc, lv_color_hex(0x641E16), LV_PART_MAIN);
    lv_obj_set_style_arc_color(arc, lv_color_hex(0xF8C471), LV_PART_INDICATOR);
    lv_obj_center(arc);

    lv_obj_remove_style(arc, NULL, LV_PART_KNOB);
    lv_obj_remove_flag(arc, LV_OBJ_FLAG_CLICKABLE);

    // the indecator 
    lv_obj_t * scale = lv_scale_create(lv_screen_active());
    lv_obj_set_size(scale, width + 10, width + 10);
    lv_scale_set_label_show(scale, true);
    lv_scale_set_mode(scale, LV_SCALE_MODE_ROUND_OUTER);
    lv_obj_center(scale);

    lv_scale_set_total_tick_count(scale, 181);
    lv_scale_set_major_tick_every(scale, 10);

    lv_obj_set_style_length(scale, 5, LV_PART_ITEMS);
    lv_obj_set_style_length(scale, 20, LV_PART_INDICATOR);
    lv_scale_set_range(scale, 0, 180);

    lv_obj_t *speed = lv_label_create(lv_screen_active());
    lv_label_set_text(speed, "60");
    lv_obj_set_style_text_font(speed, &lv_font_montserrat_48, 0);
    lv_obj_set_style_text_color(speed, lv_color_white(), 0);
    lv_obj_center(speed);


    static lv_style_t style;
    lv_style_init(&style);
    lv_style_set_flex_flow(&style, LV_FLEX_FLOW_ROW_WRAP);
    lv_style_set_flex_main_place(&style, LV_FLEX_ALIGN_SPACE_EVENLY);
    lv_style_set_layout(&style, LV_LAYOUT_FLEX);

    // bottom panel
    lv_obj_t * cont = lv_obj_create(lv_screen_active());
    lv_obj_set_size(cont, 300, 100);
    lv_obj_add_style(cont, &style, 0);
    lv_obj_set_style_bg_opa(cont, 0, 0);
    lv_obj_set_style_border_width(cont, 0, 0);

    telltale(cont, LV_SYMBOL_DOWNLOAD);
    telltale(cont, LV_SYMBOL_SETTINGS);
    telltale(cont, LV_SYMBOL_GPS);

    lv_obj_align(cont, LV_ALIGN_BOTTOM_MID, 0, -30);
}

void speedometer(void)
{
    lv_example_scale_3();
}

