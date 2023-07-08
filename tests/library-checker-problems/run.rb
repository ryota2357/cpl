# frozen_string_literal: true

require 'fileutils'

LIB_CHECKER_PROBS = '/library-checker-problems'
TESTCASE_OUTPUT_DIR = File.join(__dir__, 'cases')

generate_py = File.join(LIB_CHECKER_PROBS, 'generate.py')
problems = File.open(File.join(__dir__, 'problems.txt'), 'r').read.split(/\R/).map(&:split)

problems.each do |problem|
  next if problem[0][0] == '#'

  into_toml = File.join(LIB_CHECKER_PROBS, problem[0], 'info.toml')
  result = system("#{generate_py} #{into_toml}")
  unless result
    warn("Error: #{problem}")
    next
  end

  testcase_output = File.join(TESTCASE_OUTPUT_DIR, problem[1])
  FileUtils.mkdir_p(testcase_output) unless Dir.exist?(testcase_output)

  FileUtils.mv(
    File.join(LIB_CHECKER_PROBS, problem[0], 'in'),
    File.join(testcase_output, 'in')
  )
  FileUtils.mv(
    File.join(LIB_CHECKER_PROBS, problem[0], 'out'),
    File.join(testcase_output, 'out')
  )
  puts("Success: #{problem}")
end
