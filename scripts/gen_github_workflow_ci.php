#!/usr/bin/env php
<?php echo "# generated file; do not edit!\n"; ?>

name: ci
on:
  workflow_dispatch:
  release:
    types: [published]
  pull_request:
    paths-ignore:
      - .dockerignore
      - .editorconfig
      - .gitignore
      - AUTHORS
      - CONTRIBUTING.md
      - CREDITS
      - Dockerfile
      - 'docs/**'
      - EXPERIMENTAL
      - gen_stub.php*.diff
      - LICENSE
      - README.md
  push:
    paths-ignore:
      - .dockerignore
      - .editorconfig
      - .gitignore
      - AUTHORS
      - CONTRIBUTING.md
      - CREDITS
      - Dockerfile
      - 'docs/**'
      - EXPERIMENTAL
      - gen_stub.php*.diff
      - LICENSE
      - README.md

jobs:
<?php
$gen = include __DIR__ . "/ci/gen-matrix.php";
$cur = "8.1";
$job = $gen->github([
"cur" => [
    "PHP" => $cur,
    "enable_debug",
    "enable_zts",
],
"cur-cov" => [
    "CFLAGS" => "-O0 -g --coverage",
    "CXXFLAGS" => "-O0 -g --coverage",
    "PHP" => $cur,
]]);
foreach ($job as $id => $env) {
    printf("  %s:\n", $id);
    printf("    name: \"%s (%s)\"\n", $id, $env["PHP"]);
    if ($env["PHP"] == "master") {
        printf("    continue-on-error: true\n");
    }
    printf("    env:\n");
    foreach ($env as $key => $val) {
        printf("      %s: \"%s\"\n", $key, $val);
    }
?>
    runs-on: ubuntu-20.04
    steps:
      - uses: actions/checkout@v2
        with:
          submodules: recursive
      - name: Install
        run: |
          sudo apt-get install -y \
            php-cli \
            php-pear \
            re2c
      - name: Prepare
        run: |
          make -f scripts/ci/Makefile php || make -f scripts/ci/Makefile clean php
      - name: Build
        run: |
          make -f scripts/ci/Makefile ext PECL=ion || true # no package.xml yet
      - name: Test
        run: |
          make -f scripts/ci/Makefile test
<?php if (isset($env["CFLAGS"]) && strpos($env["CFLAGS"], "--coverage") != false) : ?>
      - name: Coverage
        if: success()
        run: |
          find . -name '*.gc*'
          curl -Os https://uploader.codecov.io/latest/linux/codecov
          chomd +x codecov
          ./codecov
<?php endif; ?>

<?php
}
