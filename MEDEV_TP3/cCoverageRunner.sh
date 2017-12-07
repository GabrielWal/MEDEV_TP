#!/bin/bash
g++ pion.cpp dames.cpp damesTests.cpp -lgtest -o cc_prog -fprofile-arcs -ftest-coverage
./cc_prog
gcov damesTests.cpp
lcov -o user_test.info -c -f -d .
genhtml -o user_result user_test.info
git checkout gh-pages
git add -f user_result/*
git commit -m "Code Coverage for MEDEV_TP3"
git push
