1.upto(Float::INFINITY) do |i|
  $stdout.puts "#{i}. out"
  $stderr.puts "#{i}. err"
  sleep 2
end
