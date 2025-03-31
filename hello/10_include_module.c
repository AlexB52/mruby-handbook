// module Foo
// end

// class Buz
//   include Foo
// end
#include <mruby.h>
#include <mruby/class.h>
#include <mruby/compile.h>
#include <mruby/variable.h>

int main(int argc, char const *argv[]) {
  mrb_state *mrb = mrb_open();

  struct RClass *buz_class = mrb_define_class(mrb, "Buz", mrb->object_class);
  struct RClass *foo_module = mrb_define_module(mrb, "Foo");

  mrb_include_module(mrb, buz_class, foo_module);

  mrb_value foo_value = mrb_obj_value(mrb_module_get(mrb, "Foo"));
  mrb_value buz_value = mrb_obj_value(mrb_class_get(mrb, "Buz"));

  mrb_value val = mrb_funcall(mrb, buz_value, "include?", 1, foo_value);

  mrb_p(mrb, val);

  mrb_close(mrb);
  return 0;
}
