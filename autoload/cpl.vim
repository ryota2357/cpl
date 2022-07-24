let s:file_path = expand('<sfile>:p')

function! cpl#lib_path() abort
  return s:file_path . '/../../lib/'
endfunction
