# frozen_string_literal: true

require_relative 'util'

if ARGV.length < 5
  warn("You must specify 5 arguments (but #{ARGV.length})")
  exit(1)
end
cache_dir = ARGV[0]
compiler = ARGV[1]
test_name = ARGV[2]
solve_cpp = ARGV[3]
test_case_dir = ARGV[4]

solve_out = compile(compiler, cache_dir, solve_cpp)
all_ac = true
ac_count = 0
Dir.glob(File.join(test_case_dir, 'in', '*.in')).each do |input|
  out_file = "#{File.join(File.dirname(input, 2), 'out', File.basename(input, '.in'))}.out"
  expected = File.open(out_file, 'r').read.split
  output = `#{solve_out} < "#{input}"`.split
  if expected.length != output.length
    wa(test_name, input)
    all_ac = false
  end
  ac_count += 1
end
ac(test_name, ac_count) if all_ac
