# frozen_string_literal: true

require 'fileutils'
require 'pathname'

docker_compose_yml = File.join(__dir__, 'library-checker-problems', 'docker-compose.yaml')
result = system("docker-compose -f #{docker_compose_yml} up")
unless result
  warn('Faild to excute `docker-compose up`')
  exit(1)
end

generated_cases_dir = File.join(__dir__, 'library-checker-problems', 'cases')
cases_dir = File.join(__dir__, 'cases')

Dir.glob(File.join(generated_cases_dir, '*/{in,out}/*.{in,out}')).each do |file|
  move_path = File.join(
    cases_dir,
    Pathname(file).relative_path_from(generated_cases_dir).to_s
  )
  move_path_dir = File.dirname(move_path)
  FileUtils.mkdir_p(move_path_dir) unless Dir.exist?(move_path_dir)
  FileUtils.mv(file, move_path)
end

FileUtils.rm_r(generated_cases_dir)
