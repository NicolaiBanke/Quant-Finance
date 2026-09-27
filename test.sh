#!/bin/bash

case $1 in
"01")
  TEST_DIR=01_vanilla_options_in_a_black-shcholes_world/tests
  SRC_DIR=01_vanilla_options_in_a_black-shcholes_world/src
  ;;
*)
  echo "No such folder"
  ;;
esac

FILE="${TEST_DIR}/test.o"

g++ -std=c++17 "$TEST_DIR"/test_consistency.cpp utils/utils.cpp utils/distributions.cpp "$SRC_DIR"/formulas.cpp "$SRC_DIR"/VanillaOption.cpp lib/Option.cpp -o "$FILE"

if [ -f "$FILE" ]; then
  "./$FILE"
else
  echo "Test file not created"
fi
