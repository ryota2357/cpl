# frozen_string_literal: true

require 'fileutils'
require 'pathname'

def system2(cmd, &on_error)
  result = system(cmd)
  return if result

  on_error.call
  exit(1)
end

def library_checker_problem
  docker_compose_yml = File.join(__dir__, 'library-checker-problems', 'docker-compose.yaml')
  system2 "docker-compose -f #{docker_compose_yml} up" do
    warn('Faild to excute `docker-compose up`')
  end

  generated_cases_dir = File.join(__dir__, 'library-checker-problems', 'cases')
  cases_dir = File.join(__dir__, 'cases')

  Dir.glob(File.join(generated_cases_dir, '*', '{*,*.*}')).each do |file_or_dir|
    move_path = File.join(
      cases_dir,
      Pathname(file_or_dir).relative_path_from(generated_cases_dir).to_s
    )
    FileUtils.rm_r(move_path) if File.exist?(move_path)
    FileUtils.mkdir_p(File.dirname(move_path))
    FileUtils.mv(file_or_dir, move_path)
  end

  FileUtils.rm_r(generated_cases_dir)
end

def genetor_cpp
  cc = 'clang++ -std=c++17 -stdlib=libc++ -Wall -O2'
  genetor_dir = File.join(__dir__, 'generator')
  Dir.glob(File.join(genetor_dir, '*.cpp')).each do |file|
    out_file = File.join(genetor_dir, 'a.out')
    system2 "#{cc} -o #{out_file} #{file}" do
      warn("Faild to compile: #{file}")
    end
    cases_dir = File.join(__dir__, 'cases', File.basename(file, '.cpp'))
    system2 "#{out_file} #{cases_dir}" do
      warn("Faild to excute: #{out_file} compiled from #{file}")
    end
  end
end

library_checker_problem
genetor_cpp
