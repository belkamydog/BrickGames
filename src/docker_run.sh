#!/bin/bash
docker build -t ubuntu_gtest_ncurces .
docker run  --name ubuntu_for_tests -v `pwd`:/mounted -it ubuntu_gtest_ncurces  bash
# docker exec ubuntu_for_tests cmake /usr/src/gtest/CMakeLists.txt
# docker exec ubuntu_for_tests make -C /usr/src/gtest/
# docker exec ubuntu_for_tests cp /usr/src/gtest/*.a /usr/lib
# docker exec ubuntu_for_tests ln -s /usr/lib/libgtest.a /usr/local/lib/gtest/libgtest.a
# docker exec ubuntu_for_tests ln -s /usr/lib/libgtest_main.a /usr/local/lib/gtest/libgtest_main.a
# docker exec ubuntu_for_tests make test -C /mounted
# docker exec ubuntu_for_tests make valgrind -C /mounted
# docker stop ubuntu_for_tests
docker rm ubuntu_for_tests
