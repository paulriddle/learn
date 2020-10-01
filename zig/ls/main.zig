const std = @import("std");
const fs = std.fs;
const heap = std.heap;
const io = std.io;
const os = std.os;
const process = std.process;

pub fn main() !void {
    var general_purpose_allocator = heap.GeneralPurposeAllocator(.{}){};
    const gpa = &general_purpose_allocator.allocator;

    const args = try process.argsAlloc(gpa);
    defer process.argsFree(gpa, args); // Do I have to free here? No.

    if (args.len != 2) {
        const stderr = io.getStdErr().writer();
        try stderr.print("Usage {} dir_name\n", .{args[0]});
        os.exit(1);
    }

    const dir = try fs.cwd().openDir(args[1], .{.iterate = true});
    var dir_iterator = dir.iterate();
    while (try dir_iterator.next()) |entry| {
        const stdout = io.getStdOut().writer();
        try stdout.print("{}\n", .{entry.name});
    }
}
