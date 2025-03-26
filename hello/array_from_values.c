#include <mruby.h>
#include <mruby/array.h>
#include <mruby/compile.h>

int main(int argc, char const *argv[]) {
  mrb_state *mrb = mrb_open();

  const mrb_value vals[] = {mrb_fixnum_value(42), mrb_true_value()};
  mrb_value ary = mrb_ary_new_from_values(mrb, 2, vals);
  mrb_p(mrb, ary);

  mrb_close(mrb);
  return 0;
}