#include <mruby.h>
#include <mruby/array.h>
#include <mruby/string.h>

int main(int argc, char const *argv[]) {
  mrb_state *mrb = mrb_open();

  mrb_value str = mrb_str_new_lit(mrb, "hi");
  const mrb_value vals[] = {mrb_fixnum_value(42), mrb_true_value()};

  mrb_value ary = mrb_ary_new_from_values(mrb, 2, vals);

  mrb_p(mrb, mrb_obj_as_string(mrb, str)); // #to_s
  mrb_p(mrb, mrb_any_to_s(mrb, str));      // #inspect

  mrb_p(mrb, mrb_obj_as_string(mrb, ary));
  mrb_p(mrb, mrb_any_to_s(mrb, ary));

  mrb_close(mrb);
  return 0;
}