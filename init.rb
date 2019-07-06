#!/usr/bin/env ruby

require "fileutils"

name = ARGV[0] or abort "Usage: #{File.basename($0)} <name>"

FileUtils.mkdir(name)

File.open("#{name}/Makefile", "w") do |f|
  f.puts <<~TEXT
.PHONY: all
all: test

#{name}: main.c
	gcc -o #{name} main.c

test: #{name}
	./#{name}

.PHONY: clean
clean:
	rm -rf #{name} *.o
  TEXT
end

File.open("#{name}/.gitignore", "w") do |f|
  f.puts <<~TEXT
#{name}
  TEXT
end

File.open("#{name}/main.c", "w") do |f|
  f.puts <<~TEXT
#include <stdio.h>

int main(int argc, char **args) {
  return 0;
}
  TEXT
end
