#include <mruby.h>

int main(int argc, char const *argv[]) {
  mrb_state *mrb = mrb_open();

  mrb_value args[] = {mrb_fixnum_value(3)};
  mrb_value foo = mrb_obj_new(mrb, mrb->array_class, 1, args);
  mrb_p(mrb, foo);

  mrb_close(mrb);
  return 0;
}