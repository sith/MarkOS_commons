
add_executable(commons_tests
        main.cpp
        collections/LinkedListTest.h
        collections/LinkedListTest.cpp
        string/StringTest.cpp string/StringTest.h)

#Link with GoogleTest
target_link_libraries(commons_tests gtest gtest_main)
#Link with GoogleMock
target_link_libraries(commons_tests gmock gmock_main)
target_link_libraries(commons_tests MarkOS_commons)