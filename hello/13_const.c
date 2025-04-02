// RUB CODE EQUIVALENT

// FOO = 42
// class Foo
//   FOO = 63
// end
// class Bar < Foo
//   FOO = 84
// end

#include <mruby.h>
#include <mruby/class.h>
#include <mruby/compile.h>
#include <mruby/variable.h>

int main(int argc, char const *argv[]) {
  mrb_state *mrb = mrb_open();

  struct RClass *foo_class = mrb_define_class(mrb, "Foo", mrb->object_class);
  struct RClass *bar_class = mrb_define_class(mrb, "bar_class", foo_class);

  mrb_sym const_foo = mrb_intern_lit(mrb, "FOO");
  mrb_const_set(mrb, mrb_obj_value(mrb->object_class), const_foo,
                mrb_fixnum_value(42));
  mrb_const_set(mrb, mrb_obj_value(foo_class), const_foo, mrb_fixnum_value(63));
  mrb_const_set(mrb, mrb_obj_value(bar_class), const_foo, mrb_fixnum_value(84));

  mrb_value foo1 =
      mrb_const_get(mrb, mrb_obj_value(mrb->object_class), const_foo);
  mrb_value foo2 = mrb_const_get(mrb, mrb_obj_value(foo_class), const_foo);
  mrb_value foo3 = mrb_const_get(mrb, mrb_obj_value(bar_class), const_foo);

  printf("FOO: %lld\n", mrb_fixnum(foo1));
  printf("Foo::FOO: %lld\n", mrb_fixnum(foo2));
  printf("Bar::FOO: %lld\n", mrb_fixnum(foo3));

  mrb_close(mrb);
  return 0;
}

// RESULT

// FOO: 42
// Foo::FOO: 63
// Bar::FOO: 84