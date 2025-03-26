#include <mruby.h>
#include <mruby/array.h>
#include <mruby/compile.h>

int main(int argc, char const *argv[]) {
  mrb_state *mrb = mrb_open();
  int i;
  mrb_value ary = mrb_ary_new_capa(mrb, 5);
  for (i = 0; i < 5; i++) {
    mrb_ary_set(mrb, ary, i, mrb_fixnum_value(i));
  }
  mrb_p(mrb, ary);

  mrb_int len = RARRAY_LEN(ary);
  mrb_value item;
  for (i = 0; i < len; ++i) {
    item = mrb_ary_ref(mrb, ary, i);
    mrb_p(mrb, item);
  }

  mrb_close(mrb);
  return 0;
}