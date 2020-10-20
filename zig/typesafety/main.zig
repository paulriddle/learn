const std = @import("std");

pub fn main() void {
  const result = foo(1, 2);
  std.debug.print("{}\n", .{result});
}

// Does not compile if is_odd(n) evaluates to true at compile time. If called
// with foo(2, 2), then it will compile.
fn foo(comptime n: usize, i: usize) usize {
  const j = if (comptime is_odd(n)) "surprise!" else 1;
  return i + j;
}

fn is_odd(n: usize) bool {
  return n % 2 != 0;
}
