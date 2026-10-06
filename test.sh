#!/bin/bash

case $1 in
"01")
  TEST_DIR=./tests
  SRC_DIR=./src
  ;;
*)
  echo "No such folder"
  ;;
esac

FILE="${TEST_DIR}/test.o"

g++ -std=c++17 "$TEST_DIR"/domain/test_consistency.cpp "$TEST_DIR"/main.cpp "$SRC_DIR"/core/distributions.cpp "$SRC_DIR"/domain/formulas.cpp "$SRC_DIR"/domain/VanillaOption.cpp "$SRC_DIR"/domain/Option.cpp -o "$FILE"

if [ -f "$FILE" ]; then
  "./$FILE"
else
  echo "Test file not created"
fi
