#include <mruby.h>

int main(int argc, char const *argv[]) {
  mrb_state *mrb = mrb_open();

  mrb_value str = mrb_str_new_lit(mrb, "hoge");
  mrb_obj_freeze(mrb, str);

  mrb_value str_clone = mrb_obj_clone(mrb, str);
  mrb_value str_dup = mrb_obj_dup(mrb, str);

  if (mrb_frozen_p(mrb_basic_ptr((str_clone)))) {
    printf("str_clone is frozen.\n");
  }

  if (mrb_frozen_p(mrb_basic_ptr((str_dup)))) {
    printf("str_dup is frozen.\n");
  }
  mrb_close(mrb);
  return 0;
}
