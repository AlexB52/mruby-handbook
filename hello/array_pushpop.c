#include <mruby.h>
#include <mruby/array.h>
#include <mruby/compile.h>

int main(int argc, char const *argv[]) {
  mrb_state *mrb = mrb_open();

  mrb_value ary = mrb_ary_new_capa(mrb, 5);

  int i;
  for (i = 0; i < 5; i++) {
    mrb_ary_push(mrb, ary, mrb_fixnum_value(i));
  }
  mrb_p(mrb, ary);

  mrb_value item;
  while (RARRAY_LEN(ary) > 0) {
    item = mrb_ary_pop(mrb, ary);
    mrb_p(mrb, item);
  }

  mrb_close(mrb);
  return 0;
}