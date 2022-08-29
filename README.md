# cpl

**C**ompetitive **P**rogramming **L**ibrary.

```txt
cpl
├── LICENSE            // MIT license.
├── README.md
├── autoload           // Vim script for ddu.vim integration.
├── denops             // ddu.vim integration (source and kind)
└── lib                // Library
    ├── _test_runner
    │   └── runner.sh  // Shell script to running all tests.
    ├── _test_util     // Test utility C++ files.
    ├── [Library Name] // Library name. This is used for item name of ddu.
    │   ├── index.cpp  // Library body.
    │   └── test.cpp   // Library test.
   ...
```

## ddu.vim integration

### source

```vim
call ddu#start({'sources': [{'name': 'cpl'}]})
```

### kind

```vim
call ddu#custom#patch_global({
    \   'kindOptions': {
    \     'cpl': {
    \       'defaultAction': 'paste',
    \     },
    \   }
    \ })
```
