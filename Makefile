.DEFAULT_GOAL := help

.PHONY: test
test:
	@deno run --allow-read --allow-write --allow-run tests/test_runner.ts lib

.PHONY: gen_test
gen_test:
	@ruby tests/generate.rb

.PHONY: clean
clean:
	@rm -rf .cache

.PHONY: help
help:
	@echo 'test      Excute all tests.'
	@echo 'gen_test  Generate test case from library checker problems.'
	@echo 'clean     Cleanup caches, (remove .cache directory)'
