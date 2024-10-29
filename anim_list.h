#ifndef ANIM_LIST_H
#define ANIM_LIST_H



#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl.h"
void scroll_meun();
void load_animation();
void select_frame_anim(lv_obj_t * obj, int index);
void select_cb(lv_event_t *e);

#ifdef __cplusplus
}
#endif

#endif /* ANIM_LIST_H */