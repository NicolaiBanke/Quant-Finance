#!/bin/bash

FILE=./01_vanilla_options_in_a_black-shcholes_world/tests/test.o

g++ -std=c++17 01_vanilla_options_in_a_black-shcholes_world/tests/test_consistency.cpp utils/utils.cpp utils/distributions.cpp 01_vanilla_options_in_a_black-shcholes_world/src/formulas.cpp 01_vanilla_options_in_a_black-shcholes_world/src/VanillaOption.cpp lib/Option.cpp -o "$FILE"

if [ -f "$FILE" ]; then
  $FILE
else
  echo "Test file not created"
fi
