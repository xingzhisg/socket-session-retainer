cmake_minimum_required (VERSION 2.6)

project (sevenmile)

include (CTest)
include (CPack)

set (sevenmile_version_major 0)
set (sevenmile_version_minor 1)
set (sevenmile_version_patch 0)

add_subdirectory(inc)
add_subdirectory(src)

#add_subdirectory(tests)
#enable_testing()
#add_test(test_blocking_queue_perf tests/test_blocking_queue_perf)

