# frozen_string_literal: true

require 'digest'

def compile(compiler, cache_dir, source_cpp)
  solve_out = File.join(
    cache_dir,
    Digest::SHA256.hexdigest(File.open(source_cpp, 'r').read)
  )
  unless File.exist?(solve_out)
    compile_cmd = "#{compiler} -o #{solve_out}"
    compile_result = system("#{compile_cmd} #{source_cpp}")
    unless compile_result
      warn("Error on compiling #{source_cpp}")
      warn("  compile command: #{compile_cmd}")
      exit(1)
    end
  end
  solve_out
end

def wa(test_name, test_case)
  fgcolor = '15'
  bgcolor = '196'
  print("\e[38;5;#{fgcolor}m\e[48;5;#{bgcolor}m\e[1m WA \e[0m ")
  print("[#{test_name}] #{File.basename(test_case)}\n")
end

def ac(test_name)
  fgcolor = '15'
  bgcolor = '34'
  print("\e[38;5;#{fgcolor}m\e[48;5;#{bgcolor}m\e[1m AC \e[0m ")
  print("#{test_name}\n")
end
