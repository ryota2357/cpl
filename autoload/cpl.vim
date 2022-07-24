let s:file_path = expand('<sfile>:p')

function! cpl#lib_path() abort
  return s:file_path . "/../../lib/"
endfunction

function! cpl#paste(text) abort
  let l:i = line(".")
  for line in a:text
    call append(l:i, line)
    let l:i = l:i + 1
  endfor
endfunction
