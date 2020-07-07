#!/usr/bin/env ruby

puts `ping -c 4 #{ARGV[0]}`.include?('bytes from') ? 'yes' : 'no'
