#include "anim_list.h"



static int select_index = 0; // 选择列表的index
// 简单粗暴条目
static lv_obj_t *list_title_1;
static lv_obj_t *list_title_2;
static lv_obj_t *list_title_3;
static lv_obj_t *list_title_4;
static lv_obj_t *list_title_5;
static lv_obj_t *list_title_6;
static lv_obj_t *list_title_7;
static lv_obj_t *list_title_8;
static lv_obj_t *list_title_9;
static lv_obj_t *list_title_10;
static lv_obj_t *list_title_11;
static lv_obj_t *list_title_12;
static lv_obj_t *list_title_13;
static lv_obj_t *list_title_14;
static lv_obj_t *list_title_15;
static lv_obj_t *list_title_16;
static lv_obj_t *list_title_17;
static lv_obj_t *list_title_18;
static lv_obj_t *list_title_19;
static lv_obj_t *list_title_20;
static lv_obj_t *selected_frame;
static lv_group_t *list_group;


// 菜单结构体
typedef struct
{
  lv_obj_t *list_item; // lv_obj
  int x; // 位置 x
  int y; // 位置 y
  int selected; // 是否focus 实际不需要使用
  char *title; // 标题
} list_item_state;

int list_len = 20;

list_item_state list_item[20] = {
    {list_title_1, 10, 10, 1, "Hello World!!!"},
    {list_title_2, 10, 40, 0, "Title 2"},
    {list_title_3, 10, 70, 0, "Hello World!!!"},
    {list_title_4, 10, 100, 0, "Title 4"},
    {list_title_5, 10, 130, 0, "Hello World!!!"},
    {list_title_6, 10, 160, 0, "Title 6"},
    {list_title_7, 10, 190, 0, "Title 7"},
    {list_title_8, 10, 220, 0, "Hello World!!!"},
    {list_title_9, 10, 250, 0, "Title 9"},
    {list_title_10, 10, 280, 0, "Title 10"},
    {list_title_11, 10, 310, 0, "Title 11"},
    {list_title_12, 10, 340, 0, "Title 12"},
    {list_title_13, 10, 370, 0, "Title 13"},
    {list_title_14, 10, 400, 0, "Title 14"},
    {list_title_15, 10, 430, 0, "Title 15"},
    {list_title_16, 10, 460, 0, "Title 16"},
    {list_title_17, 10, 490, 0, "Title 17"},
    {list_title_18, 10, 520, 0, "Title 18"},
    {list_title_19, 10, 550, 0, "Title 19"},
    {list_title_20, 10, 580, 0, "Title 20"}};

list_item_state selected_frame_state = {selected_frame, 0, 0, 1, "Selected Frame"}; // 多余的

// void anim_ready_handler(lv_anim_t * a)
// {
//   lv_group_focus_obj(list_item[select_index].list_item);
//   // printf("anim ready\n");
// }

void select_frame_anim(lv_obj_t *obj, int index) // 菜单选择条动画
{
  lv_anim_t a;
  lv_anim_init(&a);
  lv_anim_t anim_width;
  lv_anim_init(&anim_width);

  lv_anim_set_var(&a, obj);
  lv_anim_set_exec_cb(&a, (lv_anim_exec_xcb_t)lv_obj_set_y);
  lv_anim_set_values(&a, lv_obj_get_y(obj), list_item[index].y - 10);
  lv_anim_set_time(&a, 200);
  lv_anim_set_path_cb(&a, lv_anim_path_overshoot);
  // lv_anim_set_ready_cb(&a, anim_ready_handler);

  lv_anim_set_var(&anim_width, obj);
  lv_anim_set_exec_cb(&anim_width, (lv_anim_exec_xcb_t)lv_obj_set_width);
  lv_anim_set_values(&anim_width, 0, lv_obj_get_width(list_item[index].list_item) + 20);
  lv_anim_set_time(&anim_width, 200);
  lv_anim_set_path_cb(&anim_width, lv_anim_path_overshoot);

  lv_anim_start(&a);
  lv_anim_start(&anim_width);
}

void select_cb(lv_event_t *e) // 点击屏幕时间回调
{
  select_index++;
  if (select_index > list_len - 1)
  {
    select_index = 0;
  }
  // lv_obj_set_y(selected_frame, list_item[select_index].y - 10);
  select_frame_anim(selected_frame, select_index);
  lv_group_focus_obj(list_item[select_index].list_item);
  if(list_item[select_index].y > 300)
  {
    lv_obj_scroll_by(lv_obj_get_parent(selected_frame), 0, -30, LV_ANIM_ON);
  }else{
    lv_obj_scroll_to(lv_obj_get_parent(selected_frame), 0, 0, LV_ANIM_OFF);
  }
}

void load_animation() // 屏幕加载动画入场
{
  lv_anim_t select_anim_load;
  lv_anim_init(&select_anim_load);
 

  lv_anim_t title_anim_load;
  lv_anim_init(&title_anim_load);


  lv_anim_timeline_t * timeline;
  timeline = lv_anim_timeline_create();

  lv_anim_set_var(&select_anim_load, selected_frame);
  lv_anim_set_exec_cb(&select_anim_load, (lv_anim_exec_xcb_t)lv_obj_set_width);
  lv_anim_set_values(&select_anim_load, 0, lv_obj_get_width(list_item[0].list_item) + 120);
  lv_anim_set_time(&select_anim_load, 300);
  lv_anim_set_path_cb(&select_anim_load, lv_anim_path_overshoot);
  lv_anim_set_delay(&select_anim_load, 0);
  lv_anim_timeline_add(timeline, 0, &select_anim_load);




  for(int i = 0; i < list_len; i++)
  {
    if(i == 0)
    {
      continue;
    }
    lv_anim_set_var(&title_anim_load, list_item[i].list_item);
    lv_anim_set_exec_cb(&title_anim_load, (lv_anim_exec_xcb_t)lv_obj_set_y);
    lv_anim_set_values(&title_anim_load, 10, list_item[i].y);
    lv_anim_set_time(&title_anim_load, 300);
    lv_anim_set_path_cb(&title_anim_load, lv_anim_path_overshoot);
    lv_anim_set_delay(&title_anim_load, 0);
    lv_anim_timeline_add(timeline, 300, &title_anim_load);
  }

  lv_anim_timeline_start(timeline);

}

void scroll_meun()
{

  list_group = lv_group_create();
  static lv_style_t focused_style;
  lv_style_init(&focused_style);
  lv_style_set_text_color(&focused_style, lv_color_hex(0x000000));

  static lv_obj_t *scr = lv_obj_create(NULL);
  lv_obj_set_style_bg_color(scr, lv_color_hex(0x000000), 0);
  lv_obj_set_scrollbar_mode(scr, LV_SCROLLBAR_MODE_OFF);
  lv_obj_set_scroll_snap_y(scr, LV_SCROLL_SNAP_END);
  lv_obj_clear_flag(scr, LV_OBJ_FLAG_SCROLLABLE);

  selected_frame = lv_obj_create(scr);

  lv_obj_set_size(selected_frame, 240, 30);
  lv_obj_set_style_bg_color(selected_frame, lv_color_hex(0xffffff), 0);
  lv_obj_set_style_radius(selected_frame, 5, 0);
  lv_obj_set_x(selected_frame, 0);
  lv_obj_set_y(selected_frame, 0);

  for (int i = 0; i < list_len; i++)
  {
    list_item[i].list_item = lv_label_create(scr);
    lv_label_set_text(list_item[i].list_item, list_item[i].title);
    lv_obj_set_style_text_color(list_item[i].list_item, lv_color_hex(0x778899), 0);
    lv_obj_set_x(list_item[i].list_item, 10);
    lv_obj_set_y(list_item[i].list_item, list_item[i].y);
    lv_obj_add_style(list_item[i].list_item, &focused_style, LV_STATE_FOCUSED);
    lv_group_add_obj(list_group, list_item[i].list_item);
    // lv_group_focus_obj(list_item[0].list_item);
  }

  lv_group_focus_obj(list_item[0].list_item);

  // click a screen to change the focus to next title move the selected frame
  lv_obj_add_event_cb(scr, select_cb, LV_EVENT_CLICKED, NULL);
  
  load_animation();

  lv_scr_load(scr);
}
