# cpl

**C**ompetitive **P**rogramming **L**ibrary.

```txt
cpl
├── LICENSE                        // MIT license.
├── README.md
├── autoload/                      // Vim script for ddu.vim integration.
├── denops/                        // ddu.vim integration (source and kind)
├── lib/
│   ├── [Library Name]/            // Library name. This is used for item name of ddu.
│   │   ├── index.cpp              // Library body.
│   │   ├── info.toml              // Infomation file of this library.
│   │  ...
│  ...
└── tests
    ├── test_runner.ts             // Excuted by `make test`.
    ├── generate.rb                // Excuted by `make gen_test`.
    ├── cases/                     // Test input/output files.
    ├── checker/                   // Checker scripts for test.
    └── library-checker-problems/  // Used by generate.rb
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
