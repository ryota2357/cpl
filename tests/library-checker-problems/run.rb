# frozen_string_literal: true

require 'fileutils'

LIB_CHECKER_PROBS = '/library-checker-problems'
TESTCASE_OUTPUT_DIR = File.join(__dir__, 'cases')

generate_py = File.join(LIB_CHECKER_PROBS, 'generate.py')
problems = File.open(File.join(__dir__, 'problems.txt'), 'r', encoding: 'utf-8').read.split(/\R/).filter_map do |line|
  line.strip!
  line.split unless line.start_with?('#')
end

problems.each do |problem|
  p problem[0]

  into_toml = File.join(LIB_CHECKER_PROBS, problem[0], 'info.toml')
  result = system("#{generate_py} #{into_toml}")
  unless result
    warn("Error: #{problem}")
    next
  end

  testcase_output = File.join(TESTCASE_OUTPUT_DIR, problem[1])
  FileUtils.mkdir_p(File.join(testcase_output, 'in'))
  FileUtils.mkdir_p(File.join(testcase_output, 'out'))

  Dir.glob(File.join(LIB_CHECKER_PROBS, problem[0], 'in', '*.in')).each do |old_path|
    new_path = File.join(testcase_output, 'in', "#{File.basename(old_path, '.*')}.txt")
    FileUtils.mv(old_path, new_path)
  end

  Dir.glob(File.join(LIB_CHECKER_PROBS, problem[0], 'out', '*.out')).each do |old_path|
    new_path = File.join(testcase_output, 'out', "#{File.basename(old_path, '.*')}.txt")
    FileUtils.mv(old_path, new_path)
  end

  puts("Success: #{problem}")
end
