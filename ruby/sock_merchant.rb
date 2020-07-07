#!/bin/ruby

require 'json'
require 'stringio'

# Complete the sockMerchant function below.
def sockMerchant(n, ar)
  colors = Hash.new(0)

  ar.each do |sock|
    colors[sock] += 1
  end

  colors.each do |color, count|
    colors[color] -= 1 if count.odd?
  end

  colors.values.sum / 2
end

fptr = File.open(ENV['OUTPUT_PATH'], 'w')

n = gets.to_i

ar = gets.rstrip.split(' ').map(&:to_i)

result = sockMerchant n, ar

fptr.write result
fptr.write "\n"

fptr.close()
