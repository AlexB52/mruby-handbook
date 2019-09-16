#include <mruby.h>
#include <mruby/compile.h>
#include <mruby/string.h>
#include <mruby/numeric.h>

static mrb_float
c2f(mrb_float deg)
{
  return (deg * 9.0 / 5.0) + 32.0;
}

static mrb_value
mrb_celsius_c2f_unit(mrb_state *mrb, mrb_value self)
{
  mrb_float deg;
  mrb_value unit;

  mrb_int argc = mrb_get_args(mrb, "f|S", &deg, &unit);
  if (argc == 1) {
    unit = mrb_str_new_lit(mrb, "F");
  }
  return mrb_str_plus(mrb, mrb_float_to_str(mrb, mrb_float_value(mrb, c2f(deg)), "%.1f"), unit);
}

int
main(void)
{
  mrb_state *mrb = mrb_open();

  struct RClass *celsius = mrb_define_class(mrb, "Celsius", mrb->object_class);
  mrb_define_class_method(mrb, celsius, "c2f_with_unit", mrb_celsius_c2f_unit, MRB_ARGS_REQ(1));

  mrb_load_string(mrb, "puts Celsius.c2f_with_unit(10.0)");
  mrb_load_string(mrb, "puts Celsius.c2f_with_unit(10.0, '℉')");

  mrb_close(mrb);
  return 0;
}
