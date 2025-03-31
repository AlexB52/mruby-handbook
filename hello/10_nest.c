// class Foo
//   module Buz
//     class Bar
//     end
//   end
// end

#include <mruby.h>
#include <mruby/class.h>
#include <mruby/compile.h>

int main() {
  mrb_state *mrb = mrb_open();

  struct RClass *foo_class = mrb_define_class(mrb, "Foo", mrb->object_class);
  struct RClass *buz_module = mrb_define_module_under(mrb, foo_class, "Buz");
  struct RClass *bar_class =
      mrb_define_class_under(mrb, buz_module, "Bar", mrb->object_class);

  printf("name %s\n", mrb_class_name(mrb, foo_class));
  printf("name %s\n", mrb_class_name(mrb, bar_class));

  mrb_close(mrb);
  return 0;
}