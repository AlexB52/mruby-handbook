#include <mruby.h>
#include <mruby/class.h>
#include <mruby/compile.h>
#include <stdio.h>

// class Foo; end
// class Bar < Foo; end
// module Buz; end

// puts "class 1: #{Foo}"
// puts "class 2: #{Bar}"
// puts "module 1: #{Buz}"

int main() {
  mrb_state *mrb = mrb_open();

  struct RClass *foo_class = mrb_define_class(mrb, "Foo", mrb->object_class);
  struct RClass *bar_class = mrb_define_class(mrb, "Bar", foo_class);
  struct RClass *buz_module = mrb_define_module(mrb, "Buz");

  printf("class 1: %s\n", mrb_class_name(mrb, foo_class));
  printf("class 2: %s\n", mrb_class_name(mrb, bar_class));
  printf("module 1: %s\n", mrb_class_name(mrb, buz_module));

  mrb_close(mrb);
  return 0;
}