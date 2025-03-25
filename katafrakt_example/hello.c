#include "greeter.c"
#include <mruby.h>
#include <mruby/irep.h>

int main(int argc, char const *argv[]) {
  mrb_state *mrb = mrb_open();
  mrb_load_irep(mrb, greeter);
  mrb_close(mrb);
  return 0;
}